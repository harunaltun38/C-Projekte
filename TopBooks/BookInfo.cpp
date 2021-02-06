#include "BookInfo.h"

BookInfo::BookInfo()
{
}

BookInfo::BookInfo(string titel, string autor, int anzahl_downloads) {

	this->Titel= titel;
	this->Autor = autor;
	this->Anzahl_Downloads = anzahl_downloads;


}


BookInfo::~BookInfo()
{
}
