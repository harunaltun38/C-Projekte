#pragma once
#include<vector>
#include<string>
#include"Month.h"
using namespace std;

class Year
{
public:
	Year();
	~Year();

	Year(int year) { this->year_number = year; }

	int getYear_number()const { return year_number; }

	vector<Month>&getMonthVec() { return monthVec; }
	void pushMonth(Month month_value) { monthVec.push_back(month_value); }

private:

	int year_number = 0;
	vector<Month>monthVec;

};

