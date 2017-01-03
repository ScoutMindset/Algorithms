#include <iostream>
#include <vector>

#include "Connection.h"

int main()
{
	int socialNetworkSize = 0;
	int numberOfConnectionsMade = 0;

	std::cout << "Give the size of the social network: ";
	std::cin >> socialNetworkSize;
	std::cout << "Give the number of connections made: ";
	std::cin >> numberOfConnectionsMade;

	std::vector<int> socialNetworkHierarchy(socialNetworkSize);

	for (int ii = 0; ii < socialNetworkSize; ++ii)
		socialNetworkHierarchy[ii] = ii;

	std::vector
	for (int ii = 0; ii < numberOfConnectionsMade; ++ii)
	{

	}

	return 0;
}