#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <exception>
#include <iomanip>
#include "Verwaltung.h"
#include "BookInfo.h"


using namespace std;


int main() try {

	Verwaltung object;

	char eingabe = '*';
	do {

		cout << "[1] Textdatei einlesen und Gesamtzahl ausgeben" << endl;
		cout << "[2] Haeufigkeit der einzelnen Titel ausgeben" << endl;
		cout << "[3] Neue Gesamtreihenfolge ausgeben" << endl;
		cout << "[4] Autoren nach Haeufigkeit in Textdatei ausgeben" << endl;
		cout << "[9] Programm beenden" << endl;

		cin >> eingabe;


		switch (eingabe) {

		case '1': {

			object.einlesen();
			//object.sortieren();


			cout << "Datei wurde eingelesen!" << endl;
			break;
		}
		case '2': {
			object.haufigkeit();
			break;

		}
		case '3': {
			object.gesamtzahl_downloads_absteigend_sortiert();
			break;
		}
		case '4': {
	
			object.downloads_addiert();
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

