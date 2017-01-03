#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include "MyMatrix.h"

int main() 
{
	// DIAGONAL DIFFERENCE
	int n;
	std::cout << "Please provide the size of the matrix: ";
	std::cin >> n;
	MyMatrix<int>  cMatrix(n);

	std::cout << "Please provide the elements of the matrix:\n";

	std::cin >> cMatrix;
	std::cout << cMatrix;
	std::cout << " The diagonal sum of the given matrix is: " << cMatrix.ComputeDiagonalSum() << "\n";
	return 0;
}