#pragma once                
#include <string>

using namespace std;

class Jahreszahl
{
public:
	Jahreszahl(string tempJahreszeit, double tempDurchschnittstemperatur, int tempJahr) {
		jahrezeit = tempJahreszeit;
		durchschnittstemperatur = tempDurchschnittstemperatur;
		jahr = tempJahr;
	}

	~Jahreszahl();

	const double getDurchschnittstemperatur() {
		return durchschnittstemperatur;
	}

	const string getJahreszeit() {
		return jahrezeit;
	}

	const int getJahr() {
		return jahr;
	}

private:
	string jahrezeit;
	double durchschnittstemperatur;
	int jahr;
};
