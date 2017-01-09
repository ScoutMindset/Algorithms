#include <iostream>
#include <vector>

#include "QuickFindNetwork.h"

int main()
{
	int socialNetworkSize = 0;
	int numberOfConnectionsMade = 0;

	std::cout << "Give the size of the social network: ";
	std::cin >> socialNetworkSize;
	std::cout << "Give the number of connections made: ";
	std::cin >> numberOfConnectionsMade;
	QuickFindNetwork network(socialNetworkSize);
	bool allNodesConnected = false;

	for (int ii = 0; ii < numberOfConnectionsMade; ++ii)
	{
		int node1 = 0;
		int node2 = 0;
		std::cout << "CONNECTION " << ii + 1 << std::endl;
		std::cout << "Please provide the 1st node to connect: ";
		std::cin >> node1;
		std::cout << "Please provide the 2nd node to connect: ";
		std::cin >> node2;
		network.Connect(node1, node2);
		allNodesConnected = network.CheckIfAllNodesAreConnected();
		if (allNodesConnected)
			break;
	}

	std::cout << "All the network's nodes are connected: " << allNodesConnected;

	return 0;
}