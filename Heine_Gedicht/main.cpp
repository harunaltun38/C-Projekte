#include<iostream>
#include<string>
#include<exception>
#include"Word.h"
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<map>
#include<iomanip>
#include<iterator>
using namespace std;
void einlesen(const string&, vector<Word>&);
void print(const vector<Word>&);

int main()try{
	vector<Word>wordVec; //WICHTIG NICHT VERGESSEN
	string datei = "Heine.txt";
	map<string, int>word_haeufigkeit; //(2)
	map<int, int>tabelle; //(3)
	char eingabe = '#';
	do{
		cout << "[1]einlesen_sortieren_ausgeben" << endl;//nach laenge
		cout << "[2]Haeufigkeit_in Datei" << endl;
		cout << "[3]Tabelle" << endl;
		cout << "[9]Beenden" << endl;
		cout << "Eingabe: ";
		cin >> eingabe;
		switch (eingabe){

		case'1':{einlesen(datei, wordVec);
			sort(wordVec.begin(), wordVec.end(), [](const Word&lhs, const Word&rhs){
				return lhs.GetLaenge() < rhs.GetLaenge();
			});
			print(wordVec);
			break; }
		case'2':{
					for (const auto&tmp : wordVec){
						word_haeufigkeit[tmp.GetWord()]++;  //Haeufigkeit
					}
					//map->vector

					vector<pair<string, int>>wordhaeufigInVec(word_haeufigkeit.begin(), word_haeufigkeit.end());
					//sort
					sort(wordhaeufigInVec.begin(), wordhaeufigInVec.end(), [] //Z
						(const pair<string,int>&lhs,const pair<string,int>&rhs){

						if (lhs.first.length() != rhs.first.length()){  //wenn ungleich nach laenge
							return lhs.first.length() < rhs.first.length();

						}
						else{  //bei gleich alphabetisch
							return lhs.first < rhs.first;
						}
					}); //Z
					//ausgabe in Datei
					ofstream file("Woerter.txt", ios::out);

					for (const auto&tmp : wordhaeufigInVec){ //F

						file << tmp.first  << " Laenge: " << tmp.first.length()
							 << " Haeufigkeit: " << tmp.second  << endl;
					}//F
					file.close();
					cout << "In datei geschrieben" << endl;
					break; }

		case'3':{//PART1
					for (const auto&tmp : wordVec){
						tabelle[tmp.GetLaenge()]++;

					}
					//PART2
					cout << "Gesamtzahl der Woerter" << wordVec.size() << endl;

					//durchschnittliche Länge
					//von der map
					int ergebnis = 0;
					for (const auto&tmp : tabelle){
						ergebnis =ergebnis+ (tmp.first*tmp.second);
					}
					int Endergebnis = ergebnis / wordVec.size(); //durch geamzahl der wörter
					cout << "Durchschnittliche Laenge des Woerter " << Endergebnis << endl;
					//PART3
					sort(wordVec.begin(), wordVec.end(), [](const Word&lhs, const Word&rhs){
						return lhs.GetLaenge() < rhs.GetLaenge();
					});

					double median = (wordVec.size() / 2)+0.5 ; //Bei ungeraden
					//Bei geraden muss du gesamtzahl/2 -> dann wert=wert+1;
					//Beide nochmal summieren und durch 2
					double gesucht = wordVec[median].GetLaenge();
					cout << "Der Median ist: " << gesucht << endl;
					break; }

		case'4':{//nochmal einlesen ohne zeichenfilter
			string suchwort = "";
			string filter = "";
			string einlese = "";
			string komplettertext = "";
			fstream file2("Heine.txt", ios::in);

			getline(file2, filter);
			getline(file2,filter);  //2 zeilen filtern
			stringstream ss;
			while (getline(file2, einlese)){//B  //zeilenweise in stringstream rein
				ss << einlese;
			}//B
			komplettertext = ss.str(); //den ganzen textinhalt in string variabel
			
			/*for (int i = 0; i < komplettertext.size(); i++){ \\zum testen print
				cout<<komplettertext[i];
			}*/

					cout << "Bitte geben sie das zu suchende Wort ein" << endl;
					cin >> suchwort;					
										
					for (int i = 0; i < komplettertext.size(); i++){//C

						if (komplettertext.find(suchwort) != -1){//D //falls vorhanden

							int wortindex = komplettertext.find(suchwort); //position des gesuchten
							cout << suchwort << " " << wortindex << endl;

							//kontext bestimmen							
							komplettertext.erase(0, wortindex - 50);
							wortindex = komplettertext.find(suchwort);
							string kontext = komplettertext.substr(0, wortindex+50);

							//füge ein zeichen hinter dem gesuchten Wort
							int index = kontext.find(suchwort);
							kontext.replace(index, string("").length(), "*");
							cout << kontext << endl;
							break;
						}//D

					}//C					

					break; }
		case'9':{cout << "Beenden...."; }
		default:{cerr << "Ungueltige Eingabe!"; }
		}
	} while (eingabe != '9');
	return 0;
}
catch (exception&e){
	cerr << "Ausnahme: " << e.what() << endl;
	return -2;
}
catch (...){
	cerr << "unbekannte Ausnahme" << endl;
	return -1;
}


void einlesen(const string&datei, vector<Word>&wordVec){
	fstream file(datei, ios::in);
	string tmp = "";
	//variables aus klasse
	string wort = "";
	int laenge = 0;

	if (!file){ throw runtime_error{ "Datei konnte nicht geoffnet werden" }; }

	getline(file, tmp);
	getline(file, tmp);  //2 zeilen filtern

	while (getline(file, tmp)){ //A

		if (tmp == ""){ //wenn leere zeile dann "" \\ (' ') nur bei string
			getline(file, tmp);
		}
		stringstream ss(tmp); // \n entfernen
		getline(ss, tmp);

		//Zeichenfiltern___
		while (tmp.find(".") != -1){ //solange vorhanden
			size_t suche1 = tmp.find(".");
			tmp.replace(suche1, string(".").length(), "");
		}
		while (tmp.find(",") != -1){ //solange vorhanden
			size_t suche1 = tmp.find(",");
			tmp.replace(suche1, string(",").length(), "");
		}
		while (tmp.find("!") != -1){ //solange vorhanden
			size_t suche1 = tmp.find("!");
			tmp.replace(suche1, string("!").length(), "");

		}
		while (tmp.find("?") != -1){ //solange vorhanden
			size_t suche1 = tmp.find("?");
			tmp.replace(suche1, string("?").length(), "");
		}
		while (tmp.find("''") != -1){ //solange vorhanden
			size_t suche1 = tmp.find("''");
			tmp.replace(suche1, string("''").length(), "");
		}

		while (tmp.find("-") != -1){ //solange vorhanden
			size_t suche1 = tmp.find("-");
			tmp.replace(suche1, string("-").length(), "");
		}
		//Zeichenfiltern___
		stringstream ss2(tmp);
		while (ss2 >> wort){ //B
		Word word(wort, wort.length());
		wordVec.push_back(word);
	}//B
	}//A
	file.close();
	
}
void print(const vector<Word>&wordVec){

	for (const auto&tmp : wordVec){

		cout << tmp.GetWord() <<setw(10)<< tmp.GetLaenge() <<setfill('.')<< endl;
	}

}