#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Episode.h"
#include<fstream>
#include<sstream>
#include<map>
#include<algorithm>

using namespace std;
class Verwaltung
{
public:
	Verwaltung();
	~Verwaltung();
	void einlesen();
	void flashback();
	void haeufigkeit_woerter();
	vector<Episode>getAllEpisodes(){ return episoden; }
private:
	vector<Episode>episoden;
};

