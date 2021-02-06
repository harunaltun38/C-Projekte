#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include"Verwaltung.h"
using namespace std;


int main(){

	Verwaltung Objekt;
	char eingabe='0';

	do{
		cout << "[1] Englische Episodentitel und Inhalt einer beliebigen Episode ausgeben"<<endl;
		cout << "[2] Nur Rückblicke einer beliebigen Episode ausgeben"<<endl;
		cout << "[3] Die 15 häufigsten Wörter der Rückblicke einer Episode ausgeben"<<endl;
		cout << "[4] Hauptpersonen aller Episoden ausgeben"<<endl;
		cout << "[9] Programm beenden" << endl;
		cout << "Ihre Wahl: ";
		cin >> eingabe;

		switch (eingabe){
			cout << endl;
		case'1':Objekt.einlesen();
			break;
		case'2':Objekt.flashback();
			break;
		case '3':Objekt.haeufigkeit_woerter();
			break;
		case '4':
			break;
		case '9': cout << "Beenden..." << endl;
			break;
		default:cout << "Falsche Eingabe Nochmal probieren !" << endl;
			break;



		}

	} while (eingabe !='9');



	system("pause");

	return 0;
}