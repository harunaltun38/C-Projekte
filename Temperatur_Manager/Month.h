#pragma once
#include<string>
using namespace std;

class Month
{
public:
	Month();
	Month(string name) { this->month_name = name; }
	~Month();

	string getName()const { return month_name; }
	double getTemperatur()const { return temperatur; }

	void SetTemperatur(double temp) { this->temperatur = temp; }
private:
	string month_name ="" ;
	double temperatur = 0.0;
};

