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
#include "Airport.h"


using namespace std;


int main() try {

	Verwaltung object;
	
	char eingabe = '*';
	do {

		cout << "[1] Infos zu IATA-Code auf Konsole ausgeben" << endl;
		cout << "[2] eingelesen Inhalt von Datei ausgeben!" << endl;
		cout << "[3] eingelesene Datei gefiltert in neue Datei speichern" << endl; 
		cout << "[4] Inhalt zweiter Textdatei ausgeben!" << endl;
		cout << "[5] Anzahl Flughäfen in einzelnen Staaten/Territorien ausgenen!" << endl;
		cout << "[9] Programm beenden" << endl;
		cout << "Ihre Wahl: ";
		cin >> eingabe;


		switch (eingabe) {

		case '1': {
			object.einlesen1();
			object.einlesen();
			//object.sortieren();
			object.auswahl();
			cout << "Datei wurde eingelesen!" << endl;

			break;
		}
		case '2': {
			
			object.print();

			break;

		}
		case '3': {
			object.inDatei();
			break;
		}
		case '4': {
		
			object.print1();
			break;
		}
		case '5': {
			object.haufigkeit();
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

