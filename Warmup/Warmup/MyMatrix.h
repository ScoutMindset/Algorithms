#ifndef My_MATRIX_H
#define My_MATRIX_H

#include <vector>

template <typename Type>

class MyMatrix
{
private:
	std::vector< std::vector<Type> > atDataArray;
public:
	MyMatrix() : atDataArray(0, std::vector<Type>(0))
	{
	}
	MyMatrix(int nSideLength) : atDataArray(nSideLength, std::vector<Type>(nSideLength))
	{
	}
	MyMatrix(int nNoRows, int nNoCols) : atDataArray(nNoRows, std::vector<Type>(nNoCols))
	{
	}

	int ReturnNoRows() const
	{
		return atDataArray.size();
	}

	int ReturnNoCols() const
	{
		return atDataArray[0].size();
	}

	Type ComputeDiagonalSum()
	{
		int nDiagonalSum = 0;

		for (int nRowIndex = 0; nRowIndex < ReturnNoRows(); ++nRowIndex)
			for (int nColumnIndex = 0; nColumnIndex < ReturnNoCols(); ++nColumnIndex)
				if (nColumnIndex == nRowIndex)
					nDiagonalSum += this->ReadOnly(nRowIndex, nColumnIndex);

		return nDiagonalSum;
	}

	const Type& ReadOnly(int nRow, int nCol) const
	{
		return atDataArray[nRow][nCol];
	}

	Type& operator()(int nRow, int nCol)
	{
		return atDataArray[nRow][nCol];
	}

	friend std::ostream& operator<<(std::ostream &os, const MyMatrix<Type> &cMatrix)
	{
		
		for (int nRowIndex = 0; nRowIndex < cMatrix.ReturnNoRows(); ++nRowIndex)
		{
			std::cout << "[";
			for (int nColIndex = 0; nColIndex < cMatrix.ReturnNoCols(); ++nColIndex)
			{
				os << " " << cMatrix.ReadOnly(nRowIndex, nColIndex) << " ";
			}
			std::cout << "]\n";
		}		

		return os;
	}

	friend std::istream& operator>>(std::istream &is, MyMatrix<Type> &cMatrix)
	{
		for (int nRowIndex = 0; nRowIndex < cMatrix.ReturnNoRows(); ++nRowIndex)
			for (int nColIndex = 0; nColIndex < cMatrix.ReturnNoCols(); ++nColIndex)
				is >> cMatrix(nRowIndex, nColIndex);

		return is;

	}

};

#endif
