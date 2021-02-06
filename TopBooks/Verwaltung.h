#pragma once
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include<algorithm>
#include "BookInfo.h"
#include<iomanip>
using namespace std;
class Verwaltung
{
public:
	Verwaltung();
	~Verwaltung();
	void einlesen();
	void print();
	//void sortieren();
	//void inDatei();
	void haufigkeit();
	//void einlesen1();
	//void print1();
	void gesamtzahl_downloads_absteigend_sortiert();

	void downloads_addiert();

	vector<BookInfo>&getAllBookInfo() { return bookinfos; } //für textdatei mit allen sachen



private:
	vector<BookInfo>bookinfos;
	};

