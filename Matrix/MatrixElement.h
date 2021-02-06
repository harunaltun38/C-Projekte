#pragma once
#include <string>
using namespace std;
class MatrixElement
{
public:
	MatrixElement(int z, int s, int w) :zeile{ z }, spalte{ s }, wert{w}{}
	MatrixElement() :zeile{ 0 }, spalte{0}, wert{0}{}//Konstruktor ohne param für resize
	~MatrixElement();

	int Getzeile()const{ return zeile; }
	int GetSpalte()const{ return spalte; }
	int Getwert()const{ return wert; }

private:

	int zeile = 0;
	int spalte = 0;
	int wert = 0;
};

