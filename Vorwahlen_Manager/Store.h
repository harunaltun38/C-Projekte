#pragma once

#include <string>

using namespace std;

class Store {

public:

	Store(string, string, string, string);
	~Store();
	Store();



	void setOrt(string ort) { this->Ort = ort; }
	string getOrt() { return Ort; }

	void setPLZ(string plz) { this->PLZ = plz; }
	string getPLZ() { return PLZ; }

	void setStrasse(string strasse) { this->Strasse = strasse; }
	string getStrasse() { return Strasse; }

	void setTelefonnummer(string telefonnummer) { this->Telefonnummer = telefonnummer; }
	string getTelefonnummer() { return Telefonnummer; }



private:
	string PLZ = "";
	string Ort = "";
	string Strasse = "";
	string Telefonnummer = "";
	


};