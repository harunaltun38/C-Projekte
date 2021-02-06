#include "Airport.h"


Airport::Airport()
{
}

Airport::Airport(string iata, string name, string city, string stateabbreviation, string country, string lat, string longitude) {

	this->Iata = iata;
	this->Name = name;
	this->City = city;
	this->StateAbbreviation = stateabbreviation;
	this->Country = country;
	this->Lat = lat;
	this->Longitude = longitude;

}


Airport::~Airport()
{
}
