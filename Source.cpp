#include"Prva.h"
#include"Druga.h"
#include"Treca.h"
#include"Cetvrta.h"
#include"Ucenik.h"
#include<istream>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include "Izuzetak.h"

using namespace std;

int main() {
	Prva prva;
	Druga druga;
	Treca treca;
	Cetvrta cetvrta;
	int izbor = 0;int izbor2 = 0;
	
	
	cout << "xxx" << endl;

	while (1) {
		try {

			throw Izuzetak();
		}
		catch(Izuzetak){


			cout << "DOBRO DOSLI NA C++ DNEVNIK, Izaberite godinu za pokretanje programa (1-4) :" << endl;
			cin >> izbor;
			switch (izbor) {
			case 1:
				cout << "        I GODINA" << endl;
				cout << "1.Unesi ucenika I godine:" << endl;
				cout << "2.Ispisi sve ucenike:" << endl;
				cout << "3.Pretrazi ucenika:" << endl;
				cout << "4.Obrisi ucenika:" << endl;
				cout << "5.Izmeni ucenika:" << endl;
				cin >> izbor2;
				switch (izbor2) {



				case 1:
					prva.upis();
					prva.upisUfajl();
					break;
				case 2:
					prva.ispis();
					break;
				case 3:
					prva.pretraga();
					break;
				case 4:
					prva.obrisi();
					break;
				case 5:
					prva.izmeni();
					break;
				}
				break;
			case 2:
				cout << "        II GODINA" << endl;
				cout << "1.Unesi ucenika II godine:" << endl;
				cout << "2.Ispisi sve ucenike:" << endl;
				cout << "3.Pretrazi ucenika:" << endl;
				cout << "4.Obrisi ucenika:" << endl;
				cout << "5.Izmeni ucenika:" << endl;
				cin >> izbor;
				switch (izbor) {
				case 1:
					druga.upis();
					druga.upisUfajl();
					break;
				case 2:
					druga.ispis();
					break;
				case 3:
					druga.pretraga();
					break;
				case 4:
					druga.obrisi();
					break;
				case 5:
					druga.izmeni();
					break;
				}
				break;
			case 3:
				cout << "        III GODINA" << endl;
				cout << "1.Unesi ucenika III godine:" << endl;
				cout << "2.Ispisi sve ucenike:" << endl;
				cout << "3.Pretrazi ucenika:" << endl;
				cout << "4.Obrisi ucenika:" << endl;
				cout << "5.Izmeni ucenika:" << endl;
				cin >> izbor;
				switch (izbor) {
				case 1:
					treca.upis();
					treca.upisUfajl();
					break;
				case 2:
					treca.ispis();
					break;
				case 3:
					treca.pretraga();
					break;
				case 4:
					treca.obrisi();
					break;
				case 5:
					treca.izmeni();
					break;
				}
				break;
			case 4:
				cout << "        IV GODINA" << endl;
				cout << "1.Unesi ucenika IV godine:" << endl;
				cout << "2.Ispisi sve ucenike:" << endl;
				cout << "3.Pretrazi ucenika:" << endl;
				cout << "4.Obrisi ucenika:" << endl;
				cout << "5.Izmeni ucenika:" << endl;
				cin >> izbor;
				switch (izbor) {
				case 1:
					cetvrta.upis();
					cetvrta.upisUfajl();
					break;
				case 2:
					cetvrta.ispis();
					break;
				case 3:
					cetvrta.pretraga();
					break;
				case 4:
					cetvrta.obrisi();
					break;
				case 5:
					cetvrta.izmeni();
					break;
				}
				break;

			}
		}
	}

	return 0;
}