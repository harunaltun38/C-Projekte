#pragma once
#include<string>
using namespace std;
class Word
{
public:
	Word(string w,int l) :wort{w}, laenge{l}{}
	~Word();

	string GetWord()const { return wort; }
	int GetLaenge()const{ return laenge; }
private:
	string wort = "";
	int laenge = 0;
};

