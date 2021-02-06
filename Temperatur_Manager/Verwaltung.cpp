#include "Verwaltung.h"

void Verwaltung::einlesen_Durchschnitt_N4() {
	////1. einlesen Nur die Jahre "1881 1882...."
	string tmp = "";
	int year = 0;
	ifstream file_year("Temperaturen_1881_2011.txt");
	//file_year.open("Temperaturen_1881_2011.txt", ios::in);

	if (file_year) {//A
						
		getline(file_year, tmp);  //erste Zeile �berspringen (Monate)


		while (getline(file_year, tmp)) {//B

			stringstream ss(tmp);

			ss >> year;
			
			Year yearobj(year);       //Year Objekt erzeugen//bef�llen/pushen
			yearVec.push_back(yearobj);
		}//B
				

	}//A
	else { cout << "File not found" << endl; }
	file_year.close();

	///////////////////////
	/////2.einlesen Nur die "Monate" bef�llen von den vorhin eingef�gten Jahren

	string monthname = "";
	int counter = 0;	

	//string tmp;  bereits oben deklariert

	ifstream file_month("Temperaturen_1881_2011.txt");
	//file_month.open("Temperaturen_1881_2011.txt", ios::in);

	if (file_month) {//A
		
		string filter = "";

		getline(file_month, tmp); //nehme erste Zeile 
		stringstream ss2(tmp); //stecke in ss
		ss2 >> filter; //Jahrwort weggefiltert

		for (int i = 0; i < 12; i++)
		{//B

			ss2 >> monthname; //Jan,Feb...

			Month monthobj(monthname);

			for (int i = 0; i < yearVec.size(); i++) {//C  //yearVec[0].Jan, year[1].Jan....
				yearVec[i].pushMonth(monthobj);         //yearVec[0].Feb, year[1].Feb....
			}//C

		}//B			

	}//A
	else { cout << "File not found" << endl; }
	file_month.close();
///////////////
////////////3.einlese um den Monaten die Werte zu geben

	//tmp bereits oben deklariert

	ifstream file_monthValues("Temperaturen_1881_2011.txt");
	//file_monthValues("Temperaturen_1881_2011.txt", ios::in);

	if (file_monthValues) {//A

		getline(file_monthValues, tmp);   //�berspringe erste Zeile
		int counter = 0;

		while (getline(file_monthValues, tmp))  
		{//B
			stringstream ss3(tmp);
			getline(ss3, tmp, '\t');   // JahresZahl �berspringen

			for (int i = 0; i < 12; i++)
			{//C
				getline(ss3, tmp, '\t');       
				//sucht , und ersetzt es mit .
				int positionDot = tmp.find(",");
				tmp.replace(positionDot, string(",").length(), ".");
				double temperatur = stod(tmp);  //string->double

				yearVec[counter].getMonthVec()[i].SetTemperatur(temperatur);
			}//C

			//nachdem schleife oben fertig ist, geht er ins n�chste Jahr
			//und f�ngt von vorne an bei Januar - Dezember (also 12 mal)
			counter++;
		}//B



	}//A

	else { cout << "File not found" << endl; }
	file_monthValues.close();

	///Durchnittberechnen   //linker Wert Jahreszahl(Schl�ssel)  rechter Wert Temperatur
//Bunu asa
	map<int, double>durchschnittstemp;


	for (int x = 0; x < yearVec.size(); x++) {//D                                  //vektor->map
		for (int y = 0; y < yearVec[x].getMonthVec().size(); y++) {//E

			durchschnittstemp[yearVec[x].getYear_number()] += yearVec[x].getMonthVec()[y].getTemperatur() / 12;
		}//E
	}//D
	//Bunu asa
	                                          //Ausgabe der Map  //direkte Ausgabe durch Map = aufsteigend des Schl�ssels(Jahr) = (alphab)
	cout << left << setw(20) << setfill('.') << "Jahr" << "Durchschnittstemperatur in Grad Celsius" << endl;

	for (auto& temp: durchschnittstemp) {//F  
		cout << left << setw(20) << setfill('.') << temp.first << temp.second << endl;
	}//F

	//Durchnittberechnen

	cout << endl;
	cout << " Gesamtzahl der Jahre: " << yearVec.size()  << endl;


	
	//////print  falls ben�tigt  alle Jahre mit Monaten

	//for (int x = 0; x < yearVec.size(); x++)
	//{//D
	//	for (int y = 0; y < yearVec[x].getMonthVec().size();y++) {//E

	//			cout << yearVec[x].getYear_number() <<" "<<	yearVec[x].getMonthVec()[y].getName()<<" "
	//			<< yearVec[x].getMonthVec()[y].getTemperatur() << endl;
	//		
	//	}//E

	//}//D
	//
	///////print
}


void Verwaltung::jahre_Nach_fallend_Durchnitts_Temperatur_N4() {
	//bunu asa dedim yer
	map<int, double>durchschnittstemp;


	for (int x = 0; x < yearVec.size(); x++) {                                  //vektor->map
		for (int y = 0; y < yearVec[x].getMonthVec().size(); y++) {

			durchschnittstemp[yearVec[x].getYear_number()] += yearVec[x].getMonthVec()[y].getTemperatur() / 12;
		}
	}
	   //bunu asa dedim yer                                                                    //map->vektor
	vector <pair<int, double>> DStempMapToVec(durchschnittstemp.begin(), durchschnittstemp.end()); 

	sort(DStempMapToVec.begin(), DStempMapToVec.end(),   //SortVektor
		[](pair<int, double>& lhs, pair<int, double>& rhs) {
		return lhs.second > rhs.second;            //absteigend sortiert nach Wert
	});


	ofstream myfile;     //Ausgabe in txt Datei
	myfile.open("Fallend.txt");
	myfile << "Jahr" << " " << "Durchschnittstemperatur in Grad Celsius" << endl;

	for (pair<int, double>& temp : DStempMapToVec)
	{
		myfile << temp.first << "   " << temp.second << endl;
	}

	myfile.close();


}


void Verwaltung::warm_kalt_N3() {


	double coldmaxtemp = 10;
	int coldmaxyear = 0;
	string coldmaxmonthname = "";

	double warmmaxtemp = 0;
	int warmmaxyear = 0;
	string warmmaxmonthname = "";

	for (int x = 0; x < yearVec.size(); x++) {//A
		for (int y = 0; y < yearVec[x].getMonthVec().size(); y++) {//B

			if (yearVec[x].getMonthVec()[y].getTemperatur() < coldmaxtemp)
			{//C
				coldmaxtemp = yearVec[x].getMonthVec()[y].getTemperatur();
				coldmaxyear = yearVec[x].getYear_number();
				coldmaxmonthname = yearVec[x].getMonthVec()[y].getName();
			}//C

			if (yearVec[x].getMonthVec()[y].getTemperatur() > warmmaxtemp)
			{//D
				warmmaxtemp = yearVec[x].getMonthVec()[y].getTemperatur();
				warmmaxyear = yearVec[x].getYear_number();
				warmmaxmonthname = yearVec[x].getMonthVec()[y].getName();
			}//D
		}//B
	}//A

	cout << endl << "*** K�ltester und w�rmster Monat im Gesamtzeitraum ***" << endl << endl
		<< "K�ltester Monat: " << coldmaxmonthname << " " << coldmaxyear << " mit " << coldmaxtemp << " Grad. " << endl
		<< "W�rmster Monat: " << warmmaxmonthname << " " << warmmaxyear << " mit " << warmmaxtemp << " Grad. " << endl << endl;


}



void Verwaltung::jahreszahl_N2()
{//Z
	string jahrezeit;
	double durchschnittstemperatur = 0;
	int jahr;

	//Fruehling_____________________________________
	for (int i = 0; i < yearVec.size(); i++) {//A
		for (int y = 2; y < 5; y++) {//B

			durchschnittstemperatur += yearVec[i].getMonthVec()[y].getTemperatur() / 3;
			jahr = yearVec[i].getYear_number();
			jahrezeit = "Fruehling";
		}//B
		Jahreszahl jahreszahlobj(jahrezeit, durchschnittstemperatur, jahr);
		jahreszahlVec.push_back(jahreszahlobj);
		durchschnittstemperatur = 0;
	}//A                                    //alle JZeiten gleich  copy paste asa

	//Sommer________________________________________
	for (int i = 5; i < yearVec.size(); i++) {//A
		for (int y = 5; y < 8; y++) {//B

			durchschnittstemperatur += yearVec[i].getMonthVec()[y].getTemperatur() / 3;
			jahr = yearVec[i].getYear_number();
			jahrezeit = "Sommer";
		}//B
		Jahreszahl jahreszahlobj(jahrezeit, durchschnittstemperatur, jahr);
		jahreszahlVec.push_back(jahreszahlobj);
		durchschnittstemperatur = 0;
	}//A


	//Herbst_______________________________________
	for (int i = 0; i < yearVec.size(); i++) {//A
		for (int y = 8; y < 11; y++) {//B

			durchschnittstemperatur += yearVec[i].getMonthVec()[y].getTemperatur() / 3;
			jahr = yearVec[i].getYear_number();
			jahrezeit = "Herbst";
		}//B
		Jahreszahl jahreszahlobj(jahrezeit, durchschnittstemperatur, jahr);
		jahreszahlVec.push_back(jahreszahlobj);
		durchschnittstemperatur = 0;
	}//A

	//winter_________________________________________
	for (int i = 0; i < yearVec.size(); i++) {//A
		for (int y = 0; y < 2; y++) {//B

			durchschnittstemperatur += yearVec[i].getMonthVec()[y].getTemperatur() / 3;
			jahr = yearVec[i].getYear_number();
			jahrezeit = "Winter";

		}//B
		durchschnittstemperatur = +yearVec[i].getMonthVec()[11].getTemperatur();  //dikkat degisik
		Jahreszahl jahreszahlobj(jahrezeit, durchschnittstemperatur, jahr);
		jahreszahlVec.push_back(jahreszahlobj);
		durchschnittstemperatur = 0;
	}//A
	//______________________________________________________________________________

	//Sort
	sort(jahreszahlVec.begin(), jahreszahlVec.end(),
		[](Jahreszahl& lhs, Jahreszahl& rhs) {
		return lhs.getDurchschnittstemperatur() > rhs.getDurchschnittstemperatur(); //absteigend nach value(DurchschnittsT)
	});
	//Sort
	                                        //Ausgabe in Datei
	ofstream myfile("Jahreszeiten.txt");

	if (myfile.is_open()) {//C
		for (int i = 0; i < jahreszahlVec.size(); i++) {//D
			myfile << jahreszahlVec[i].getJahreszeit() << " " << jahreszahlVec[i].getJahr()
				<< " mit " << jahreszahlVec[i].getDurchschnittstemperatur() << endl;
		}//D
	}//C

	//Ausgabe in Datei
}//Z


void Verwaltung::Prozentsatz_w�rmste_Jahre_N1() {
	vector<double>theo_prozent;
	vector<double>prozentsatz;
	double ergebnis = 0.0;
	double n = 5.0;
	int zahl = 5;

	while (n < 131) {//A

		
		ergebnis = 0.76336* n;         //100/131=0.76336
		theo_prozent.push_back(ergebnis);
		n = n + 5;
	}//A


	// realer prozentsatz  //dubliziere von oben

	////////////von Aufgbae 1   //bestimme die W�rmsten Jahre (absteigend sort) oben w�rmste Jahre


	map<int, double>durchschnittstemp;   //w�rmste drin //nach Durchnitt sortiert


	for (int x = 0; x < yearVec.size(); x++) {                                  //vektor->map
		for (int y = 0; y < yearVec[x].getMonthVec().size(); y++) {

			durchschnittstemp[yearVec[x].getYear_number()] += yearVec[x].getMonthVec()[y].getTemperatur() / 12;
		}
	}
	//map->vektor
	vector <pair<int, double>> DStempMapToVec(durchschnittstemp.begin(), durchschnittstemp.end());

	sort(DStempMapToVec.begin(), DStempMapToVec.end(),   //SortVektor //hier steckt w�rmster Jahr drin
		[](pair<int, double>& lhs, pair<int, double>& rhs) {
		return lhs.second > rhs.second;            //absteigend sortiert nach Wert f�r die w�rmsten Jahre
	});




	////////////////von Aufgabe1
	//_____________________________________
	/////dupliziere von oben


	map<int, double>durchschnittstemp2;   //abw�rts nach jahre sortiert


	for (int x = 0; x < yearVec.size(); x++) {                                  //vektor->map
		for (int y = 0; y < yearVec[x].getMonthVec().size(); y++) {

			durchschnittstemp2[yearVec[x].getYear_number()] += yearVec[x].getMonthVec()[y].getTemperatur() / 12;
		}
	}
	//map->vektor
	vector <pair<int, double>> DStempMapToVec2(durchschnittstemp2.begin(), durchschnittstemp2.end());

	sort(DStempMapToVec2.begin(), DStempMapToVec2.end(),   //SortVektor 
		[](pair<int, double>& lhs, pair<int, double>& rhs) {
		return lhs.first > rhs.first;            //absteigend sortiert nach Jahre
	});


	/////dupliziere von oben �ndere mapnamen und vektorname und mache first


	 double hit = 0;

	static double wert = 5;

	while(wert<131){//C

	for (int x = 0; x < DStempMapToVec2.size(); x++)
	{//D
		if (x > wert-1)
			break;
		for (int y = 0; y < DStempMapToVec.size(); y++)
		{//E
			if (y > wert-1)
				break;
			if (DStempMapToVec2[x].second == DStempMapToVec[y].second) {//F
				hit++;
			}//F

		}//E


	}//D

	//berechnen und vektor schmeissen
	double ergebnis_P = 0.0;
	double tmp = 100 / wert;
	ergebnis_P = (tmp*hit);
	//ergebnis_P = 100 / ergebnis_P;
	prozentsatz.push_back(ergebnis_P);
	//
	hit = 0;
	wert = wert + 5;
}//C

	//print prozente
	int zaehler = 5;
	for (int i = 0; i < prozentsatz.size(); i++)
	{
		cout << "n: " << "     Prozentsatz" << "   " << "theoretischer Prozentsatz" << endl;
		cout<<zaehler<<"        "<< prozentsatz[i] << "             " << theo_prozent[i] << endl;
		zaehler = zaehler + 5;
		cout << endl;
	}



}




Verwaltung::Verwaltung()
{
}


Verwaltung::~Verwaltung()
{
}
