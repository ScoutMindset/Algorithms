#ifndef QUICKFINDNETWORK_H
#define QUICKFINDNETWORK_H

#include <vector>
class QuickFindNetwork
{
private:
	std::vector<int> networkStructure;
	std::vector<int> nodeSizes;
	int Root(int node);
	int Size(int node);
	int NetworkSize();
	void Union(int node1, int node2);
public:
	QuickFindNetwork();
	QuickFindNetwork(int networkSize);
	~QuickFindNetwork();
	bool IsConnected(int node1, int node2);
	bool CheckIfAllNodesAreConnected();
	void Connect(int node1, int node2);
};

#endif