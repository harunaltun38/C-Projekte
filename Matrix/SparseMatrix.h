#pragma once
#include"MatrixElement.h"
#include<vector>
using namespace std;
class SparseMatrix
{
public:
	SparseMatrix(int n, vector<MatrixElement>&ME) :nummer{n}, matrixelementeVec{ ME }{}

	~SparseMatrix();
	vector<MatrixElement>GetmatrixelemVec()const{ return matrixelementeVec; }
	int GetNummer()const{ return nummer; }
private:
	vector<MatrixElement>matrixelementeVec;
	int nummer = 0;
};

struct sort_matrizen{
	bool operator()(const SparseMatrix& lhs, const SparseMatrix& rhs)const{
		
		

		for (int i = 0; i < 108; i++){
			for (int j = 0; j < 108; j++){
			if (lhs.GetmatrixelemVec()[i].Getzeile() != rhs.GetmatrixelemVec()[j].Getzeile()){
				return lhs.GetmatrixelemVec()[i].Getzeile() < rhs.GetmatrixelemVec()[j].Getzeile();
			}
			else { return lhs.GetmatrixelemVec()[i].GetSpalte() < rhs.GetmatrixelemVec()[j].GetSpalte(); }
		}
		}

	}
};