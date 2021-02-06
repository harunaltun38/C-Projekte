#include<iostream>
#include"Verwaltung.h"
#include<iostream>
using namespace std;


int main() {

	Verwaltung Objekt;

	char eingabe = 'ü';

	do {

		cout << "[1] Gesamtzahl der Jahre(Objekte im Vec) und Durchschnittstemperaturen aller Jahre ausgeben (aufsteigend)=vek->map map direkt ausgeben " << endl;
		cout << "[1] Jahre nach fallenden Durchschnittstemperaturen sortiert in Datei schreiben" << endl;
		cout << "[2] Kältesten und wärmsten Monat ausgeben" << endl;
		cout << "[3] JahresZeiten Aufgabe" << endl;
		cout << "[4] Prozentsatz der wärmsten Jahre ausgeben" << endl;
		cout << "[9]  Beenden" << endl;
		cin >> eingabe;
		switch (eingabe) {


		case'1':Objekt.einlesen_Durchschnitt_N4();
			    Objekt.jahre_Nach_fallend_Durchnitts_Temperatur_N4();
			break;
		case'2': Objekt.warm_kalt_N3();		
			break;
		case'3':Objekt.jahreszahl_N2();   
			break;
		case'4':Objekt.Prozentsatz_wärmste_Jahre_N1();
			break;
		case'9':cout << "Beenden..." << endl;
			break;
		default:cout << "Falsche Eingabe ! Bitte nochmal probieren." << endl;
			break;
		}

	} while (eingabe != '9');

	return 0;
}