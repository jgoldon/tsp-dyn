#pragma once
class Graph
{
	ifstream file;
public:
	vector <vector < int > > Distances;
	int Dimension;
	Graph(string);
	~Graph();
	void Load();
	int tsp(int, int);
	int tsp_solver();
	vector <vector <int>> g;
	vector <vector <int>> p;
	void getPath(int, int);
	vector <int> Path;
	void drawPath();
};

