#pragma once
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include<algorithm>
#include <iostream>
#include<iomanip>
#include "verwaltung.h"
#include <cctype>
using namespace std;


Verwaltung::Verwaltung()
{
	
}

Verwaltung::~Verwaltung()
{
}


void Verwaltung::einlesen1() {

	string PLZ = "";
	string Ort = "";
	string Strasse = "";
	string Telefonnummer = "";


	string tmp;
	ifstream file;
	file.open("filialen.txt", ios::in);

	if (file) {
		
		while (getline(file, tmp)) {
			
			stringstream ss(tmp);
			getline(ss, tmp, ',');
			PLZ = tmp;

			getline(ss, tmp, ',');
			Ort = tmp;

			getline(ss, tmp, ',');
			Strasse = tmp;			

			ss >> Telefonnummer; //direkt einlesen da letztes wert

			Store store(PLZ, Ort, Strasse, Telefonnummer);
			stores.push_back(store);

		}

		cout << "Es wurden : " << stores.size() << " Objekte eingelesen!" << endl;


	}

	else { cout << "Datei konnte nicht gefunden werden" << endl; }
	file.close();


}




void Verwaltung::einlesen() {


	string telefonvorwahlen = "";
	string ort = "";
	string tmp;
	ifstream file;
	file.open("vorwahlen.txt", ios::in);


	if (file) {

		while (getline(file, tmp)) {
			

			stringstream ss(tmp);

			getline(ss, tmp, '\t');
			ort = tmp;

		
			ss >> telefonvorwahlen;
						
			vorwahl.insert({ort, telefonvorwahlen });


		}

	}

	else { cout << "Datei konnte nicht gefunden werden" << endl; }
	file.close();

}



void Verwaltung::indatei() {

	string textdateiname = "";

	cout << "geben sie textdatei namen ein!" << endl;

	cin >> textdateiname;

	ofstream file(textdateiname+".txt");

	file <<"Die Datei enth‰lt: "<< vorwahl.size() << " Vorwahlen\n\n\n" << endl;
	file << "Ort" << "\t\t\t\t" << "Vorwahl" << endl;
	for (std::map<string, string>::iterator it = vorwahl.begin(); it != vorwahl.end(); ++it) {
		file << setw(32) << setfill('.') << left << it->first << it->second << endl;
	}


	file.close();

	cout << "Datei wurde erfolgreich erstellt und mit Inhalt befuellt!\n\n" << endl;

}


void Verwaltung::print1() {

	cout << "Es wurden " << stores.size() << " Objekte eingefuegt" << endl;
	int count = 1;
	for (int i = 0; i < stores.size(); i++)
	{
		ausgabe(i);
	}

}

void Verwaltung::print() {

	cout << "Es wurden " << vorwahl.size() << " Objekte eingefuegt" << endl;

	for (std::map<string, string>::iterator it = vorwahl.begin(); it != vorwahl.end(); ++it) {
		cout << setw(30) << setfill('.') << left << it->first << it->second << endl;
	}
}


void Verwaltung::suche() {

	cout << "Geben sie ein Orts-Anfangsbuchstabe ein um infos ¸ber filialen zu bekommen: ";
	
	char eingabe = '1';

	cin >> eingabe;

	eingabe = static_cast<char>(std::toupper(static_cast<unsigned char>(eingabe))); //eingabe in groﬂbuchstabe umwandeln
	
	for (int i = 0; i < stores.size(); i++)
	{
		if (stores[i].getOrt().at(0) == eingabe) {    //Benutzer sucht Ort
			
			ausgabe(i);
		}

	}

}


void Verwaltung::sortieren() {


	sort(getAllStores().begin(), getAllStores().end(),
		[](Store& lhs, Store& rhs) {

		return (lhs.getOrt() < rhs.getOrt());

	});

}

string Verwaltung::searchvorwahl(string ort) {
	map<string, string>::iterator it = vorwahl.find(ort);
	return it->second;
}

void Verwaltung::ausgabe(int i) {
	cout << stores[i].getPLZ() << ", " << stores[i].getOrt() << ", " << stores[i].getStrasse() << ", " 
		<<searchvorwahl(stores[i].getOrt()) <<"-"<< stores[i].getTelefonnummer() << endl;
	
}