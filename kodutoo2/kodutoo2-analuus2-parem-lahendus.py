from os import system, name
import time

def clear():
    if name == 'nt':
        x = system('cls')
    else:
        x = system('clear')

def run():
    array_cars = ['audi', 'bmw', 'volkswagen', 'toyota', 'kia', 'lamborghini', 'porsche', 'lexus', 'ford', 'mazda']

    while True:
        userinput = input("Sisesta automark (sisesta 'exit' lõpetamiseks):\n")
        clear()

        if userinput == 'exit':
            break

        if userinput in array_cars:
            array_cars.remove(userinput)
            print("Eemaldatud automark: " + userinput + "\n")

        print("Alles olevad automargid:")
        for car in array_cars:
            print(car)

        time.sleep(2)
        clear()

    print("Programmi töö lõpetatud.")
        
run()
