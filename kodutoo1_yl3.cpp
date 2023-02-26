#include <iostream >

 using namespace std;
 int main(){


	 	int taisarv;
	 	cout << "Sisesta siia 1 taisarv: ";
	 	cin >> taisarv;

	 	if (cin.fail()){

	 		cin.clear();
	 		cout << "Viga! Sisestada tuli taisarv, aga teie sisestasite midagi muud. " << endl;
	 	}
	 	else{
			int faktoriaal = 1;
			for (int i = 1; i <= taisarv; i++){
				faktoriaal += 1;
			}

			cout << "Arvu " << taisarv << " faktoriaal on " << 	faktoriaal << endl;
		}
	 return 0;
 }
