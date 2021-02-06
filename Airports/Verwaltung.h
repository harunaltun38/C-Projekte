#pragma once
#include<vector>
#include"Airport.h"
#include<fstream>
#include<sstream>
#include<map>
#include<algorithm>
#include<iomanip>
#include "string.h"

using namespace std;
class Verwaltung
{
public:
	Verwaltung();
	~Verwaltung();
	void einlesen();
	void print();
	void sortieren();
	void inDatei();
	void haufigkeit();
	void einlesen1();
	void print1();
	void iatainfo();
	void auswahl();
	string searchState(string);
	void ausgabe(int);

	vector<Airport>&getAllAirport() { return airports; } //für textdatei mit allen sachen


private:
	vector<Airport>airports;
	map<string, string> abbreviation_state;
};

