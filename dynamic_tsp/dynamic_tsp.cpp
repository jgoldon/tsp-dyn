// dynamic_tsp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Generator.h"
#include "Graph.h"

int main()
{
	//Generator(5);
	auto g = new Graph("liczby.txt");
	g->Load();
	cout << g->tsp_solver() << endl;
	g->drawPath();
	system("pause");
	return 0;
}