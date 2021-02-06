#include "Verwaltung.h"


Verwaltung::Verwaltung()
{
}



void Verwaltung::flashback(){
	vector<string>flashbacks;
	double eingabe;
	string flash_B;

	for (int i = 0; i < episoden.size(); i++)
	{

		cout << "EpisodenNr: " << episoden[i].getEpi_NR() << " " << episoden[i].getEnglisch_T() << endl;
	}

	cout << "Von welcher Episode sollen die Rückblicke ausgegeben werden : ";
	cin >> eingabe;

	for (int i = 0; i < episoden.size(); i++)
	{
		if (episoden[i].getEpi_NR() == eingabe){

			
			flash_B = episoden[i].getInhalt();

			while (flash_B.find("<FLASHBACK>")!=-1){

				int anfang_FB = flash_B.find("<FLASHBACK>");
				flash_B.erase(0, anfang_FB);

				size_t suche1 = flash_B.find("<FLASHBACK>");
				flash_B.replace(suche1, string("<FLASHBACK>").length(), "");
				int Ende_FB=flash_B.find("</FLASHBACK>");

				flashbacks.push_back(flash_B.substr(0, Ende_FB));

				size_t suche2 = flash_B.find("</FLASHBACK>");
				flash_B.replace(suche2, string("</FLASHBACK>").length(), "");

			}		

		}

	}

	for (int i = 0; i < flashbacks.size(); i++)
	{
		static int nr = 1;
		cout <<"Nr. "<<nr<< flashbacks[i] << endl;
		nr++;
	}

}


void Verwaltung::einlesen(){
	string inhalt;
	string zeile;
	string tmp;
	ifstream file;

	string englisch_T = "", deutsch_T = "";       //Variabeln
	double EP_NR = 0;

	file.open("Lost_Staffel_1.txt", ios::in);

	if (file){

			getline(file, tmp);//  1 Zeile filtern

			while (getline(file, tmp, '\n')){        //erste Zeile einlesen

				if (tmp[0] == '*'){
					getline(file, tmp, '\n');
				}

				stringstream ss(tmp);   //ss immer zum verarbeiten der ganzen zeile mit ifstream
				ss >> zeile;


				if (zeile == "EPISODE"){
					//string EP_string = "";
				//	ss >> EP_string;
					//EP_NR = atof(EP_string.c_str());   //string-> double
					ss >> EP_NR; 
				}

				(getline(file, tmp, '\n'));  // 2. zeile

				stringstream ss2(tmp);   //ss immer zum verarbeiten der ganzen zeile mit ifstream

				getline(ss2, zeile);    //ganze Zeile vom ss in Zeile speichern

				while (zeile.find(")") != -1){  //ueberpruefe ob Zeichen überhaupt vorhanden ist

					int findeKlammer = zeile.find('(');
					deutsch_T = zeile.substr(0, findeKlammer);
					zeile.erase(0, findeKlammer);

					size_t suche1 = zeile.find("(");
					zeile.replace(suche1, string("(").length(), "");
					size_t suche2 = zeile.find(")");
					zeile.replace(suche2, string(")").length(), "");
					englisch_T = zeile;
				}  //Ueberpruefe ob Zeichen überhaupt vorhanden ist

				if (deutsch_T==""){ break; }
				//Inhalt einlesen

				(getline(file, tmp, '*'));

				stringstream ss3(tmp);   //ss immer zum verarbeiten des  ifstream

				getline(ss3, zeile,'*');    //Inhalt  vom ss in Zeile speichern
				inhalt = zeile;
				//


				Episode episode(deutsch_T, englisch_T, inhalt, EP_NR);
				episoden.push_back(episode);

				/*if (episoden.size() >= 25){
					break;
				}
				continue;*/

			}
			int size = episoden.size();
			episoden.erase(episoden.begin()+size - 1);  //liest letztes Element leer ein->entfernen
			
	}
	else{ cout << "file not found !"<<endl; }


	////print

	//for (int i = 0; i < episoden.size(); i++)
	//{
	//	cout << "EPISODE " << episoden[i].getEpi_NR() << " " << episoden[i].getEnglisch_T() << endl;
	//	cout << endl;
	//	cout << "Inhalt: " << endl;
	//	cout << episoden[i].getInhalt() << endl;
	//		
	//}
	cout << "_____________________________________________________________" << endl;
	cout << "Es wurden " << episoden.size() << " Objekte eingelesen" << endl;
	cout << "__________________________________________________________" << endl;
	cout << endl;

	for (int i = 0; i < episoden.size(); i++)
	{

		cout << "EpisodenNr: " << episoden[i].getEpi_NR() << " " << episoden[i].getEnglisch_T() << endl;
	}

	cout << "Bitte waehlen sie eine Folge " << endl;
	cout << "Eingabe: ";
	double eingabe;
	cin >> eingabe;

	cout << endl;


	for (int i = 0; i < episoden.size(); i++)
	{
		if (episoden[i].getEpi_NR() == eingabe){


			cout << "EPISODE " << episoden[i].getEpi_NR() << " " << episoden[i].getEnglisch_T() << endl;
				cout << endl;
				cout << "Inhalt: " << endl;
				cout << episoden[i].getInhalt() << endl;

		}

	}

}


void Verwaltung::haeufigkeit_woerter(){
	double eingabe;
	string inhalt="";
	string ssInhalt="";
	map<string, int> episodenMap;

	for (int i = 0; i < episoden.size(); i++)
	{

		cout << "EpisodenNr: " << episoden[i].getEpi_NR() << " " << episoden[i].getEnglisch_T() << endl;
	}

	cout << "Von welcher Episode sollen die Woerter gezaehlt werden : ";
	cin >> eingabe;
	cout << endl;

	for (int x = 0; x < episoden.size(); x++)
	{
		if (episoden[x].getEpi_NR() == eingabe){


			inhalt = episoden[x].getInhalt();

			///zeichen entfernen

			while (inhalt.find(".") != -1){
				size_t suche1 = inhalt.find(".");
				inhalt.replace(suche1, string(".").length(), "");
			}

			while (inhalt.find(",") != -1){
				size_t suche2 = inhalt.find(",");
				inhalt.replace(suche2, string(",").length(), "");
			}
			while (inhalt.find("''") != -1){
				size_t suche3 = inhalt.find(".");
				inhalt.replace(suche3, string(".").length(), "");
			}
			while (inhalt.find("!") != -1){
				size_t suche4 = inhalt.find("!");
				inhalt.replace(suche4, string("!").length(), "");
			}

			while (inhalt.find("?") != -1){
				size_t suche5 = inhalt.find("?");
				inhalt.replace(suche5, string("?").length(), "");
			}

			///

		
			stringstream ss(inhalt);


			while (ss >> ssInhalt){

				episodenMap[ssInhalt]++;



			}
			
		}

	}

	vector<pair<string, int>> EpisodenMapInVec(episodenMap.begin(), episodenMap.end());

	sort(EpisodenMapInVec.begin(), EpisodenMapInVec.end(),
		[]( pair<string, int>& lhs,  pair<string, int>& rhs)
	{
		return lhs.second > rhs.second;
	});


	static int counter =15;

	for ( auto& temp : EpisodenMapInVec)
	{
		cout << counter << ": " << temp.first << "-> " << temp.second << endl;
		counter--;
		if (counter == 0){
			break;
		}
	}

	cout << endl;

	//for (auto& temp : getAllEpisodes())
	//{
	//	booksMap[temp.getTitel()]++;  // Anzahl der gleichartigen Elemente
	//}
}

Verwaltung::~Verwaltung()
{
}
