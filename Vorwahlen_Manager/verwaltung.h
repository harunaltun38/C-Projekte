#pragma once
#include<vector>
#include<fstream>
#include "Store.h"
#include<sstream>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;
class Verwaltung
{
public:
	Verwaltung();
	~Verwaltung();
	void einlesen();
	void print();
	void print1();
	void einlesen1();
	void suche();
	void sortieren();
	void ausgabe(int);
	string searchvorwahl(string);
	void indatei();
	
	vector<Store>&getAllStores() { return stores; }
private:
	vector<Store>stores;
	map<string, string> vorwahl;

};

