#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <exception>
#include <iomanip>
#include "verwaltung.h"

using namespace std;

Verwaltung object;

int main() try {

	object.einlesen();


	char eingabe = '*';
	do {

		cout << "[1] Vorwahlen nach Orten sortiert in Datei speichern!" << endl;
		cout << "[2] Filialen einlesen!" << endl;
		cout << "[3] Vorwahlen fuer Filialen ergaenzen" << endl;
		cout << "[4] Filialen ausgeben (fuer bestimmte Orts-Anfangsbuchstaben)" << endl;
		cout << "[9] Programm beenden" << endl;

		cin >> eingabe;


		switch (eingabe) {

		case '1': {

			
			object.indatei();
			
			break;
		}
		case '2': {
			object.einlesen1();
			cout << "\n\n Filialen erfolgreich eingelesen!" << endl;
			//object.print();
			break;

		}
		case '3': {
			object.print1();

			cout << "\n\n\nVorwahlen fuer Filialen erfolgreich ergaenzt!\n\n" << endl;


			break;
		}
		case '4': {
			object.sortieren();
			object.suche();

			break;
		}
		case '9': cout << "Beenden..." << endl;
			break;
		default: cerr << "Falsche Eingabe. Nochmal probieren" << endl;
			break;

		}
	} while (eingabe != '9');
	return 0;

}





catch (exception&e) {
	cerr << "Unbekannte Ausnahme" << endl;
	return -2;
}

catch (...) {
	cerr << "Unbekannte Ausnahme" << endl;
	return -1;
}

