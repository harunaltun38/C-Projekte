#pragma once
#include<vector>
#include"Airport.h"
#include<fstream>
#include<sstream>
#include<map>
#include<algorithm>
#include <iostream>
#include<iomanip>
#include "Verwaltung.h"
using namespace std;


Verwaltung::Verwaltung()
{
	//einlesen();
}



Verwaltung::~Verwaltung()
{
}





void Verwaltung::iatainfo() {


}


void Verwaltung::haufigkeit() {
	map<string, int> airportsMap;

	for (auto& temp : airports)  //vektor->map
	{
		airportsMap[temp.getStateAbbreviation()]++;  // Anzahl der gleichartigen Elemente(Schlüssel)
	}

	vector<pair<string, int>> airportsMapInVec(airportsMap.begin(), airportsMap.end());  //map->vektor

	sort(airportsMapInVec.begin(), airportsMapInVec.end(),
		[](const pair<string, int>& lhs, const pair<string, int>& rhs)
	{
		return lhs.second < rhs.second;   //aufsteigend sortieren nach Wert
	});
	
	cout << "*** Anzahl Flughaefen in einzelnen Staaten/Territorien ***" << endl;
	for (const auto& temp : airportsMapInVec)    //vektor ausgeben
	{
		cout << setw(35) << left << searchState(temp.first) << temp.first  << "\t" << setw(2) << temp.second << endl;
	}
	cout << endl;	

}

void Verwaltung::print() {

	cout << "Es wurden " << airports.size() << " Objekte eingefuegt" << endl;
	int count=1;
	for (int i = 0; i < airports.size(); i++)
	{
		ausgabe(i);
	}
	
}

void Verwaltung::print1() {

	cout << "Es wurden " << abbreviation_state.size() << " Objekte eingelesen" << endl;

	for (std::map<string, string>::iterator it = abbreviation_state.begin(); it != abbreviation_state.end(); ++it) {
		cout << setw(30) << setfill('.') << left << it->first <<  it->second << endl;
	}
}


void Verwaltung::inDatei() {

	ofstream file("Output.txt");
	file << "Stadt" << "\t" << "Einwohner" << "\t" << "Land" << "\t" << "Kontinent" << endl;

	for (int i = 0; i < airports.size(); i++) {
		file  << airports[i].getIata() << ": " << airports[i].getName() << ", " << airports[i].getCity() << ", "<< right << airports[i].getStateAbbreviation()
			<< ", \t\t\t\t" << left << airports[i].getCountry() << "\t" << airports[i].getLat() << "\t"<< airports[i].getLongitude() << endl;
	}


	file.close();

	cout << "Datei wurde erfolgreich erstellt und mit Inhalt befuellt!" << endl;

}




//void Verwaltung::sortieren() {
//
//
//	sort(getAllAirport().begin(), getAllAirport().end(),
//		[](Airport& lhs, Airport& rhs) {
//
//		return (lhs.getIata() < rhs.getIata());
//
//	});
//
//}


void Verwaltung::einlesen1() {


	string State = "";
	string Abbreviation = "";
	

	string tmp;
	ifstream file;
	file.open("stateabb.txt", ios::in);

	if (file) {


		getline(file, tmp);    //erste zeile löschen


		while (getline(file, tmp)) {


			stringstream ss(tmp);
			getline(ss, tmp, '\t');
			State = tmp;

		

			ss >> Abbreviation;
			
			abbreviation_state.insert({Abbreviation, State });

		}



	}
	else { cout << "Datei konnte nicht gefunden werden" << endl; }
	file.close();

	
}

void Verwaltung::einlesen() {
	
	string Iata = "";
	string Name = "";
	string City = "";
	string StateAbbreviation = "";
	string Country = "";
	string Lat = "";
	string Longitude = "";

	string tmp;
	ifstream file;
	file.open("airports.txt", ios::in);

	if (file) {

				
			getline(file, tmp);    //erste zeile löschen
		

		while (getline(file, tmp)) {

			// die 10 Hochkommatas löschen
			for (int i = 0; i < 10; i++) {
				
				size_t suche2 = tmp.find("\"");
				tmp.replace(suche2, string("\"").length(), "");
				}
			//
			stringstream ss(tmp);
			getline(ss, tmp, ',');
			Iata = tmp;

			getline(ss, tmp, ','); 	
			Name = tmp;

			getline(ss, tmp, ',');             
			City = tmp;

			getline(ss, tmp, ',');
			StateAbbreviation = tmp;

			getline(ss, tmp, ',');
			Country = tmp;

			getline(ss, tmp, ',');
			Lat = tmp;

			ss >> Longitude; //direkt einlesen da letztes wert
			
			Airport airport(Iata, Name, City, StateAbbreviation, Country, Lat, Longitude);
			airports.push_back(airport);
			
		}

		cout << "Es wurden : " << airports.size() << " Objekte eingelesen!" << endl;


	}
	
	else { cout << "Datei konnte nicht gefunden werden" << endl; }
	file.close();


}


void Verwaltung::auswahl() {



	char auswahl = '*';
	do {
		cout << "Geben sie entweder 1 ein um ein IATA code einzugeben \noder 2 um eine Stadt einzugeben um die Infos fuer Flughaefen zu bekommen!" << endl;
		cout << "9 um wieder ins Hauptmenue zu gelangen!" << endl;
		cout << "Eingabe: ";
		cin >> auswahl;


		switch (auswahl) {

		case '1': {
			cout << "Bitte geben sie ein IATA-Code ein um die Infos auf der Konsole ausgeben zu lassen!" << endl;
			cout << "Eingabe: ";
			string eingabe1;
			cin >> eingabe1;           //Auswahl
			std::transform(eingabe1.begin(), eingabe1.end(), eingabe1.begin(), ::toupper);
			
			cout << endl;


			for (int i = 0; i < airports.size(); i++)
			{
				if (airports[i].getIata() == eingabe1) {    //Benutzer sucht IATA-code
					ausgabe(i);
				}

			}




			break;
		}
		case '2': {

			cout << "Bitte geben sie eine Stadt ein um die Infos auf der Konsole ausgeben zu lassen!" << endl;
			cout << "Eingabe: ";
			string eingabe;
			cin >> eingabe;           //Auswahl
			std::transform(eingabe.begin(), eingabe.end(), eingabe.begin(), ::tolower); //die komplette eingabe in kleinbuchstaben transformieren
			eingabe[0] = static_cast<std::string::value_type>(toupper(eingabe[0])); //den ersten Buchstaben der eingabe in ein großbuchstabe umwandeln

			cout << endl;


			for (int i = 0; i < airports.size(); i++)
			{
				if (airports[i].getCity() == eingabe) {    //Benutzer sucht Stadt
					ausgabe(i);
				}

			}

			
			break;

		}
	
		case '9': 
			break;
		default: cerr << "Falsche Eingabe. Nochmal probieren" << endl;
			break;

		}
	} while (auswahl != '9');
	
}


string Verwaltung::searchState(string abbreviation) {
	map<string, string>::iterator it = abbreviation_state.find(abbreviation);
	return it->second;
}

void Verwaltung::ausgabe(int i) {
	cout << airports[i].getIata() << ": " << airports[i].getName() << ", " << airports[i].getCity() << ", " << searchState(airports[i].getStateAbbreviation()) << "(" << airports[i].getStateAbbreviation() << ")"
		<< ", " << airports[i].getCountry() << "    " << airports[i].getLat() << "    " << airports[i].getLongitude() << endl;
	cout << endl;
}