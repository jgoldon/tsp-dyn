#include "stdafx.h"
#include "Generator.h"

Generator::Generator(int number)
{

	srand(time(NULL));
	
	for (int k = 0; k < 30; k++)
	{
		ofstream file;
		file.open("t_" + to_string(number) + to_string(k) + ".txt");

		//zapisanie ilosci miast w pliku
		file << number;
		file << endl;


		for (int i = 1; i <= number; i++)
		{
			for (int j = 1; j <= number; j++)
			{
				if (i == j)
				{
					file << 0;
				}
				else
				{
					int rundom_number = (rand() % 100) + 1;
					file << rundom_number;
				}
				file << " ";
			}
			file << endl;
		}
		file.close();
	}
}


Generator::~Generator()
{
}


