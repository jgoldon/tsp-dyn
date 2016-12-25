// dynamic_tsp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Generator.h"
#include "Graph.h"
double PCFreq = 0.0;
__int64 licznik = 0;


void start()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "B³¹d!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	licznik = li.QuadPart;
}
double getTime()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	cout << "Operacja zajela: " << (li.QuadPart - licznik) / PCFreq << " milisekund" << endl;
	return double((li.QuadPart - licznik) / PCFreq);
}

void cos(int n)
{
	int size2;
	int number2 = n;
	double times2 = 0;
	for (int i = 0; i < 30; i++)
	{
		//ifstream file;
		//file.open("t_" + to_string(number2) + to_string(i) + ".txt");
		//file >> size2;
		//BB m(size2);
		auto g = new Graph("t_" + to_string(number2) + to_string(i) + ".txt");
		g->Load();
		start();
		//m.name = "t_" + to_string(number2) + to_string(i) + ".txt";
		//m.size = size2;
		//m.read();
		//start();
		g->tsp_solver();
		times2 += getTime();
		//file.close();
		cout << i << endl;
	}
	ofstream file;
	file.open("wd_" + to_string(number2) + ".txt");
	file << times2 / 30;
	file.close();
}

int main()
{
	//int wybor = 0;
	//int n;
	//string s;
	//while (wybor != 3)
	//{
	//	cout << "Co chcesz zrobic? \n1 - algorytm dynamiczny \n2 - wygeneruj plik \n3 - wyjscie" << endl;

	//	cin >> wybor;
	//	double a, b;


	//	switch (wybor)
	//	{
	//	case 1:
	//	{
	//		cout << "Podaj nazwe pliku.\n";
	//		cin >> s;
	//		auto g = new Graph(s);
	//		g->Load();
	//		start();
	//		cout << "Dystans: " << g->tsp_solver() << endl;
	//		getTime();
	//		g->drawPath();
	//		break;
	//	}

	//	case 2:
	//	{
	//		cout << "Podaj ilosc miast." << endl;
	//		cin >> n;
	//		Generator test(n);
	//		break;
	//	}
	//	}
	//}
	//Generator(4);
	//Generator(6);
	//Generator(8);
	//Generator(9);
	//Generator(10);
	//Generator(11);
	//Generator(12);
	cos(4);
	cos(6);
	cos(8);
	cos(9);
	cos(10);
	cos(11);
	cos(12);

	system("pause");
	return 0;
}