#include <iostream>


using namespace std;
int main(){

	int taisarv;
	cout << "Sisesta siia 1 taisarv: ";
	cin >> taisarv;

	if (cin.fail()){

		cin.clear();
		cout << "Viga! Sisestada tuli taisarv, aga teie sisestasite midagi muud. " << endl;
	}
	else {
		int kohtadearv = 0;
		if (taisarv < 0){
			kohtadearv ++;
		}
		 // Deklareerin et kohtadearv on alguses o, selleks et sellele midagi juurde liita
		while (taisarv != 0 ){ // senikaua kuni arv ei ole 0 võrdne tehakse seda tehet.
			taisarv = taisarv / 10;
			kohtadearv ++; // kohtade arvud liidetakse 1 koht + 1 koht + 1koht
		}
		cout << "Sisestatud arvus on kumnendsusteemiskohti " << kohtadearv << " ." << endl;
	}
	return 0;
}
