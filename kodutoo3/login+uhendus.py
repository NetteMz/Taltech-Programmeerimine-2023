import mysql.connector
from customtkinter import CTk, CTkLabel, CTkButton, CTkEntry
import bcrypt 

window = CTk()
window.title("Kasutajaliides")
window.geometry("400x320")

# tekstibokisid
def login():
    username = username_entry.get()
    password = password_entry.get()
    birthday = birthday_entry.get()

    # peaks andmebaasist võtma kasutaja andmed ja neid kontrollima
    query = "SELECT * FROM minu_andmebaas WHERE username = %s"
    cursor.execute(query, (username,))
    user = cursor.fetchone()

    # kontrollib kas kasutaja on olemas ja parool mätchib
    if user and user["password"] == password:
        message = "Sisselogimine oli edukas:)"
    else:
        message = "Sisselogimine ebaõnnestus:("

    # kui andmed on õiged või valed siis annab teada
    message_label.config(text=message)

# võimaldab uuel kasutajal liituda
def create_account():
    username = username_entry.get()
    password = password_entry.get()
    birthday = birthday_entry.get()
    
    hashed_password = bcrypt.hashpw(password.encode(), bcrypt.gensalt())

    # paneb kasutaja sisestatud andmed andmebaasi
    query = "INSERT INTO Minu andmebaas (parool, kasutajanimi, sünnipäev) VALUES (%s, %s, %s)"
    values = (password, username, birthday)
    cursor.execute(query, values)
    connection.commit()

    message = "Konto loodud edukalt;)"

    # annab teada kui konto on edukalt loodud
    message_label.config(text=message)

# kasutajanime teksiboks ja kiri
username_label = CTkLabel(window, text="Kasutajanimi")
username_label.pack()
username_entry = CTkEntry(window)
username_entry.pack()

# parooli tekstiboks ja kiri
password_label = CTkLabel(window, text="Parool")
password_label.pack()
password_entry = CTkEntry(window, show="o")
password_entry.pack()

# sõnnipäeva tekstiboks ja kiri, äkki peaks seadma kuidagi üles mis formaadis seda küsitakse? 
# ülesandes oli et "vähemalt 2 välja nii et panin sünnipäeva ka"
birthday_label = CTkLabel(window, text="Sünnipäev")
birthday_label.pack()
birthday_entry = CTkEntry(window)
birthday_entry.pack()

# sisselogimise nupp
login_button = CTkButton(window, text="Logi sisse", command=login)
login_button.pack()

# uue konto loomise nupp
create_account_button = CTkButton(window, text="Loo konto", command=create_account)
create_account_button.pack()

message_label = CTkLabel(window, text="")
message_label.pack()

# Establish a connection to the MySQL database- jama mis ei tööta
connection = mysql.connector.connect(
    host="sql7.freemysqlhosting.net",
    user="sql7622218",
    password="W1SvJpaGAj",
    database="sql7622218"
)

# # Create a cursor to execute SQL queries
cursor = connection.cursor(dictionary=True)

 # Start the CustomTkinter event loop()
window.mainloop()

# # Close the cursor and database connection when the program exits
cursor.close()
connection.close()

