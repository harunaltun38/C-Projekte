#pragma once
#include<vector>
#include"BookInfo.h"
#include<fstream>
#include<sstream>
#include<map>
#include<algorithm>
#include <iostream>
#include<iomanip>
#include <numeric>
#include <cmath>
#include "Verwaltung.h"
using namespace std;


Verwaltung::Verwaltung()
{
	//einlesen();
}



Verwaltung::~Verwaltung()
{
}




void Verwaltung::print() {

	cout << "Es wurden " << bookinfos.size() << " Objekte eingelesen" << endl;

	for (int i = 0; i < bookinfos.size(); i++) {

		cout << bookinfos[i].getTitel() << " " << bookinfos[i].getAutor() << " " << bookinfos[i].getAnzahl_Downloads() << endl;

	}
}

void Verwaltung::haufigkeit()
{
	map<string, int> buchtitelMap;

	for (auto& temp : bookinfos) //vector -> Map
	{
		buchtitelMap[temp.getTitel()]++; //Anzahl gleicherartigen Elemente(Schlüssel)
	}

	vector<pair<string, int>> buchtitelMapinVec(buchtitelMap.begin(), buchtitelMap.end()); //map -> vector

	//sortiere alphabetisch mit lamda funktion

	sort(buchtitelMapinVec.begin(), buchtitelMapinVec.end(),
		[](const pair<string, int>& lhs, const pair<string, int>& rhs)
	{
		return lhs.first < rhs.first; //alphabetisch sortiert

	});
		//ausgabe

	for (const auto& temp : buchtitelMapinVec) //vector ausgeben
	{
		cout << setw(70) << setfill('.') << left << temp.first << temp.second << endl;

	}
	cout << endl;

}

void Verwaltung::gesamtzahl_downloads_absteigend_sortiert()
{

	map<string, int> bookMap;

	for (auto& temp : getAllBookInfo())    //vektor->map
	{
		bookMap[temp.getTitel()] += temp.getAnzahl_Downloads();  //den wert mit gleichen schlüssel addieren
	}

	vector<pair<string, int>> booksMapInVec(bookMap.begin(), bookMap.end());  //map->vektor

	sort(booksMapInVec.begin(), booksMapInVec.end(),
		[](const pair<string, int>& lhs, const pair<string, int>& rhs)
	{
		return lhs.second > rhs.second;   //absteigend sortieren nach Anzahl Downloads
	});

	int counter = 1; //platzierung festlegen

	for (const auto& temp : booksMapInVec)    //vektor ausgeben
	{
		cout << counter << ": " << temp.second << "-> " << temp.first << endl;
		counter++;
	}

	cout << endl;
}

void Verwaltung::downloads_addiert()
{
	
	map<string, int> bookMap;

	for (auto& temp : getAllBookInfo())    //vektor->map
	{
		bookMap[temp.getAutor()] += temp.getAnzahl_Downloads();  //den wert mit gleichen schlüssel addieren
	}

	vector<pair<string, int>> booksMapInVec(bookMap.begin(), bookMap.end());  //map->vektor

	

	sort(booksMapInVec.begin(), booksMapInVec.end(),
		[](const pair<string, int>& lhs, const pair<string, int>& rhs)
	{
		return lhs.second < rhs.second;   //absteigend sortieren nach Anzahl Downloads
	});

	int counter = 1; //platzierung festlegen
			
  long double prozent = booksMapInVec.size();
	for (const auto& temp : booksMapInVec)    //vektor ausgeben
	{
		prozent = prozent*0.001;
		cout << counter << ": " << prozent << "% -> " << temp.first << endl;
		counter++;
	}
	

	cout << endl;

}



void Verwaltung::einlesen() {


	string Titel = "";
	string Autor = "";
	int Anzahl_Downloads = 0;
	string zeile = "";

	string tmp;
	ifstream file;
	file.open("TopBooks.txt", ios::in);

	if (file) {
		while (getline(file, tmp)) {


			if (tmp[0] == '*') {
				getline(file, tmp);
			}

			stringstream ss(tmp);
			getline(ss, zeile);

			int PunktIndex = zeile.find(".");
			zeile.erase(0, PunktIndex + 1);

			if (zeile.find("by") != -1) {      //wenn by vorhanden

				int ByIndex = zeile.find("by");
				Titel = zeile.substr(0, ByIndex);
				zeile.erase(0, ByIndex + 3);
				int KlammeraufIndex = zeile.find("(");
				Autor = zeile.substr(0, KlammeraufIndex);
				zeile.erase(0, KlammeraufIndex + 1);
				size_t suche1 = zeile.find(")");
				zeile.replace(suche1, string(")").length(), "");
				Anzahl_Downloads = atoi(zeile.c_str());
			}
			else {                               //wenn by nicht vorhanden

				Autor = "unknown";
				int KlammeraufIndex = zeile.find("(");
				Titel = zeile.substr(0, KlammeraufIndex);
				zeile.erase(0, KlammeraufIndex + 1);
				size_t suche2 = zeile.find(")");
				zeile.replace(suche2, string(")").length(), "");
				Anzahl_Downloads = atoi(zeile.c_str());



			}
			BookInfo bookinfo(Titel, Autor, Anzahl_Downloads);
			bookinfos.push_back(bookinfo);


		}


	}

	else { cout << "Datei konnte nicht gefunden werden" << endl; }
	file.close();

	cout << "Es wurden " << bookinfos.size() << " Objekte eingelesen" << endl;
}