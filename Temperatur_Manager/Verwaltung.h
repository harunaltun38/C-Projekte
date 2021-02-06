#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include<algorithm>
#include<iomanip>
#include"Year.h"
#include"Jahreszahl.h"

using namespace std;
class Verwaltung
{
public:
	Verwaltung();
	~Verwaltung();

	void einlesen_Durchschnitt_N4();     
	void jahre_Nach_fallend_Durchnitts_Temperatur_N4();
	void warm_kalt_N3();
	void jahreszahl_N2();    

	void Prozentsatz_wärmste_Jahre_N1();  
	vector<Year>&getAllYears() { return yearVec; }
	

private:
	vector<Year>yearVec;
	vector <Jahreszahl> jahreszahlVec;     
	
};

