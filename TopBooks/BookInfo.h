#pragma once

#include <string>

using namespace std;

class BookInfo {

public:

	BookInfo(string, string, int);
	~BookInfo();
	BookInfo();



	void setTitel(string titel) { this->Titel = titel; }
	string getTitel() { return Titel; }

	void setAutor(string autor) { this->Autor = autor; }
	string getAutor() { return Autor; }

	void setAnzahl_Downloads(int anzahl_downloads) { this->Anzahl_Downloads = anzahl_downloads; }
	int getAnzahl_Downloads() { return Anzahl_Downloads; }


private:
	string Titel = "";
	string Autor = "";
	int Anzahl_Downloads = 0;




};