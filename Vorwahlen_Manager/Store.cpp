#include "Store.h"


Store::Store()
{
}

Store::Store(string plz, string ort, string strasse, string telefonnummer) {

	this->PLZ = plz;
	this->Ort = ort;
	this->Strasse = strasse;
	this->Telefonnummer = telefonnummer;

}

Store::~Store()
{
}
