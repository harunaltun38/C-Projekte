#pragma once

#include <string>

using namespace std;

class Airport {

public:

	Airport(string, string, string, string, string, string, string);
	~Airport();
	Airport();

	

	void setName(string name) { this->Name = name; }
	string getName() { return Name; }

	void setIata(string iata) { this->Iata = iata; }
	string getIata() { return Iata; }

	void setCity(string city) { this->City = city; }
	string getCity() { return City; }

	void setStateAbbreviation(string stateabbreviation) { this->StateAbbreviation = stateabbreviation; }
	string getStateAbbreviation() { return StateAbbreviation; }

	void setCountry(string country) { this->Country = country; }
	string getCountry() { return Country; }

	void setLat(string lat) { this->Lat = lat; }
	string getLat() { return Lat; }

	void setLongitude(string longitude) { this->Longitude = longitude; }
	string getLongitude() { return Longitude; }


private:
	string Iata = "";
	string Name = "";
	string City = "";
	string StateAbbreviation = "";
	string Country = "";
	string Lat = "";
	string Longitude = "";



};