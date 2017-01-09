#include "QuickFindNetwork.h"



int QuickFindNetwork::Root(int node)
{
	int currNode = node;
	
	do
	{
		currNode = networkStructure[currNode];
	}
	while (currNode != networkStructure[currNode]);

	return currNode;
}

int QuickFindNetwork::Size(int node)
{
	return nodeSizes[node];
}

int QuickFindNetwork::NetworkSize()
{
	return networkStructure.size();
}

void QuickFindNetwork::Union(int node1, int node2)
{
	networkStructure[node2] = node1;
}

QuickFindNetwork::QuickFindNetwork()
{
}

QuickFindNetwork::QuickFindNetwork(int networkSize)
{
	for (int ii = 0; ii < networkSize; ++ii)\
	{
		networkStructure.push_back(ii);
		nodeSizes.push_back(1);
	}		
}

QuickFindNetwork::~QuickFindNetwork()
{
}

bool QuickFindNetwork::IsConnected(int node1, int node2)
{
	return (Root(node1) == Root(node2));
}

bool QuickFindNetwork::CheckIfAllNodesAreConnected()
{
	std::vector<int> roots(this->NetworkSize());
	for (int ii = 0; ii < this->NetworkSize(); ++ii)
		roots[ii] = Root(ii);
	
	int firstRoot = roots[0];

	for (int ii = 1; ii < this->NetworkSize(); ++ii)
	{
		if (firstRoot != roots[ii])
			return false;
	}
	
	return true;
}

void QuickFindNetwork::Connect(int node1, int node2)
{
	if (Size(node1) < Size(node2))
	{
		Union(node1, node2);
		nodeSizes[node2] += nodeSizes[node1];
	}

	else
	{
		Union(node2, node1);
		nodeSizes[node1] += nodeSizes[node2];
	}
		
}
