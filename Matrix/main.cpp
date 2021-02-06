#include<iostream>
#include<string>
#include"MatrixElement.h"
#include"SparseMatrix.h"
#include<fstream>
#include<sstream>
#include<exception>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;

void einlesen(const string&, vector<SparseMatrix>&);
void print(const vector<SparseMatrix>&);
void testExport(const string&, const vector<SparseMatrix>&);
void sortiere_ausgeben(vector<SparseMatrix>&);
void auswahl_ausgabe(vector<SparseMatrix>&);
int main()try{
	char eingabe = '#';
	vector<SparseMatrix>spVec{};
	
	spVec.clear();
	string datei = "Matrizen.txt";
	string datei_out = "testexport.txt";
	do{

		cout << "[1] Textdatei einlesen, Matrizenanzahl und Elementanzahl ausgeben" << endl;
		cout << "[2] Sortieren und Anzahl der Elemente jeder Matrix ausgeben " << endl;
		cout << "[3] Eintraege einer Matrix ausgeben " << endl;
		cout << "Eingabe: ";
		cin >> eingabe;
		switch (eingabe){

		case'1':{einlesen(datei, spVec);
			//print(spVec);
			//testExport(datei_out, spVec);
			break; }
		case'2':{sortiere_ausgeben(spVec);
					break; }
		case'3':{auswahl_ausgabe(spVec);
					break; }
		case'9':{cout << "Beenden..." << endl; break; }
		default:cerr << "Falsche Eingabe !" << endl;
		}

	} while (eingabe != '9');



	return 0;
}
catch (exception&e){
	cerr << "Ausnahme: " << e.what() << endl;
	return -2;
}
catch (...){

	cerr << "Unbekannte Ausnahme " << endl;
	return -1;
}


template<class T>T string_to(const string&s){
	istringstream is(s);
	T t;
	if (!(is >> t)) throw runtime_error("Fehler beim Konvertieren");
	return t;
}


void einlesen(const string&datei, vector<SparseMatrix>&spVec){
	fstream file(datei, ios::in);
	string tmp = "";
	int zeile = 0;
	int spalte = 0;
	int wert = 0;
	static int nummer = 1;
	vector<MatrixElement>meVec;
	/*meVec.reserve(100001);
	cout << "die groesse vom vektor>: " << meVec.capacity() << endl;*/
	

	if (!file){ throw runtime_error{ "Fehler: Datei konnte nicht geoeffnet werden !" }; }


	for (int i = 0; i < 6; i++){  //6 Zeilen filtern
		getline(file, tmp);
	}

	for (int i = 0; i < 107; i++){    //nur bis zum vorletzen

		
		while (getline(file, tmp)){

			if (tmp.at(0) == '='){ getline(file, tmp, '='); }


			stringstream ss(tmp);

			while (ss >> tmp){
				zeile = string_to<int>(tmp);
				ss >> tmp;
				spalte = string_to<int>(tmp);
				ss >> tmp;
				wert = string_to<int>(tmp);

				MatrixElement matrixelement(zeile, spalte, wert);
				meVec.push_back(matrixelement);
			
			}

			SparseMatrix sparsematrix(nummer,meVec);
			nummer++;
			spVec.push_back(sparsematrix);
			meVec.clear();  //damit sich der vector nicht aufsummiert
			break;
		}
	}
	//Wichtig:Außerhalb von for schleife
	//ein OBj bleibt übrig,weil letztes ohne "=" terminiert
	getline(file, tmp); //==... filtern

	while (getline(file, tmp)){
		stringstream ss2(tmp);
		ss2 >> zeile;
		ss2 >> spalte;
		ss2 >> wert;
		MatrixElement matrixelement(zeile, spalte, wert);
		meVec.push_back(matrixelement);
	}
	SparseMatrix sparsematrix(nummer,meVec);
	//kein nummer++ weil er nur einmal macht
	spVec.push_back(sparsematrix);

	file.close();

	cout << "Anzahl der Matrizen:  " << spVec.size() << endl;

		// Von jeder Matrix sagen,wieviele Elemente sie hat

	for (int i = 0; i < spVec.size(); i++){
		cout << "MatrixNr.______________" << spVec[i].GetNummer() << endl;
		//for (int j = 0; j < spVec[i].GetmatrixelemVec().size(); j++){

			int size = spVec[i].GetmatrixelemVec().size();
			cout << "Anzahl der Elemente: " << size << endl;
			//break;
		//}
		
	}
		// Von jeder Matrix sagen,wieviele Elemente sie hat

}


void print(const vector<SparseMatrix>&spVec){
	
	for (int i = 0; i < spVec.size(); i++){
		cout << "MatrixNr.______________" << spVec[i].GetNummer() << endl;
		for (int j = 0; j < spVec[i].GetmatrixelemVec().size(); j++){

			cout << spVec[i].GetmatrixelemVec()[j].Getzeile() << " "
				<< spVec[i].GetmatrixelemVec()[j].GetSpalte() << " "
				<< spVec[i].GetmatrixelemVec()[j].Getwert() << " " << endl;
		}
	
	}
}


//ausgeben immer wie print + file
void testExport(const string&datei, const vector<SparseMatrix>&spVec){
	ofstream file(datei, ios::out);


	for (int i = 0; i < spVec.size(); i++){
		file <<"MatrixNr.______________"<< spVec[i].GetNummer() << endl; //file
		for (int j = 0; j < spVec[i].GetmatrixelemVec().size(); j++){

			file << spVec[i].GetmatrixelemVec()[j].Getzeile() << " " //file
				<< spVec[i].GetmatrixelemVec()[j].GetSpalte() << " "
				<< spVec[i].GetmatrixelemVec()[j].Getwert() << " " << endl;
		}
		
	}



}
void sortiere_ausgeben(vector<SparseMatrix>&spVec){
	//multimap<int, int>matrizenMap;
	multiset<int>matrizenset; //es können matrizen mit gleicher Anzahl geben->multi
	//static int counter = 1;	
	//print geklaut->modifiziert ABER-> set
	for (int i = 0; i < spVec.size(); i++){

		int size = spVec[i].GetmatrixelemVec().size();
		//matrizenMap.insert(make_pair(size, counter)); //2.parm unnötig gewesen(besser:set)
		matrizenset.insert(size);
		/*counter++;*/
	}
	//Ausgabe
	
	for (const auto&tmp : matrizenset){
		static int cnt = 1;
		//cout << "Matrix " << tmp.second << ": " << tmp.first << endl;
		cout <<"Matrix: "<<cnt<<"  "<< tmp << endl;
		cnt++;

	}

}

void auswahl_ausgabe(vector<SparseMatrix>&spVec){

	sort(spVec.begin(), spVec.end(), sort_matrizen());

		



	int auswahl = 0;
	cout << "Es sind " << spVec.size() << "Matrizen vorhanden " << endl;
	cout << "Auswahl: ";
	cin >> auswahl;
	for (int i = 0; i < spVec.size(); i++){
		if (spVec[i].GetNummer() == auswahl){
			cout << "MatrixNr.______________" << spVec[i].GetNummer() << endl;
			for (int j = 0; j < spVec[i].GetmatrixelemVec().size(); j++){

				cout << spVec[i].GetmatrixelemVec()[j].Getzeile() << " "
					<< spVec[i].GetmatrixelemVec()[j].GetSpalte() << " "
					<< spVec[i].GetmatrixelemVec()[j].Getwert() << " " << endl;
			}

		}
	}

}
