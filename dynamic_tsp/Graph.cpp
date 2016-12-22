#include "stdafx.h"
#include "Graph.h"

Graph::Graph(string s)
{
	file.open(s);
	if (!file.good())
		throw new exception("File not found");
	file >> Dimension;
	for (int i = 0; i < Dimension; i++)
	{
		g.push_back(vector<int>());
		p.push_back(vector<int>());
	}
}

void Graph::Load()
{
	for (auto i = 0; i < Dimension; i++)
	{
		Distances.push_back(vector<int>());
	}

	for (auto i = 0; i < Dimension; i++)
	{
		for (auto j = 0; j < Dimension; j++)
		{
			int distance;
			file >> distance;
			Distances[i].push_back(distance);
		}
	}
}

Graph::~Graph()
{
	file.close();
}

int Graph::tsp(int start, int set)
{
	int masked, mask, result = -1;
	int temp;
	if (g[start].at(set) != -1)
		return g[start].at(set);
	else
	{
		for (int i = 0; i < Dimension; i++)
		{
			mask = pow(2, Dimension) - 1 - (int)pow(2, i);
			masked = set & mask;
			if (masked != set)
			{
				temp = Distances[start].at(i) + tsp(i, masked);
				if (result == -1 || result > temp)
				{
					result = temp;
					p[start].at(set) = i;
				}
			}
		}
	}
	g[start].at(set) = result;
	return result;
}

int Graph::tsp_solver()
{
	for (int i = 0; i < Dimension; i++)
	{
		for (int j = 0; j < pow(2, Dimension); j++)
		{
			g[i].push_back(-1);
			p[i].push_back(-1);
		}
	}

	for (int i = 0; i < Dimension; i++)
	{
		g[i].at(0) = Distances[i].at(0);
	}
	return tsp(0, (pow(2, Dimension) - 2));
}

void Graph::getPath(int start, int set)
{
	if (p[start].at(set) == -1)
		return;
	int x = p[start].at(set);
	int mask = pow(2, Dimension) - 1 - (int)pow(2, x);
	int masked = set & mask;
	cout << x << " --- ";
	getPath(x, masked);
}

void Graph::drawPath()
{
	cout << "0 --- ";
	getPath(0, (pow(2, Dimension) - 2));
	cout << "0" << endl << endl;
}