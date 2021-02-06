#pragma once
#include<string>
using namespace std;
class Episode
{
public:
	Episode();
	Episode(string, string,string, double);
	~Episode();

	void setDeutsch_T(string deutsch_t){ this->deutsch_t = deutsch_t; }
	void setEnglisch_T(string englisch_t){ this->englisch_t = englisch_t; }
	void setEpi_NR(double episode_nr){ this->episode_nr = episode_nr; }
	void setInhalt(string inhalt){ this->inhalt = inhalt; }

	string getDeutsch_T()const{ return deutsch_t; }
	string getEnglisch_T()const{ return englisch_t; }
	double getEpi_NR()const{ return episode_nr; }
	string getInhalt()const{ return inhalt; }

private:
	double episode_nr = 0;
	string deutsch_t = "";
	string englisch_t = "";
	string inhalt = "";

};

