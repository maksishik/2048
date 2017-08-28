#include <iostream>
#include <Windows.h> 
#include <stdlib.h>
#include <ctime>
#include <vector>

#include "CGame.h"

using namespace std;

struct point
{
	int x;
	int y;
};

CGame::CGame()
: row(4)
, col(4)
, helth_playerOne(100)
, helth_playerTwo(100)
, first(0)
, second(0)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mas[i][j] = 0;
		}
	}

}

bool CGame::rand_count()
{
	vector<point> arr;

	point obj;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (mas[i][j] == 0)
			{
				obj.y = i;
				obj.x = j;
				arr.push_back(obj);
			}
		}
	}

	if (arr.size() == 0)
		return false;

	point random_pos = arr[rand() % arr.size()];

	mas[random_pos.y][random_pos.x] = 2;

	return true;
}

void CGame::show()
{
	/*if ( rand_count() == false )
	{
	exit(1);
	}*/

	cout << "Player 1: " << helth_playerOne << "hp \n"
		<< "Player 2: " << helth_playerTwo << "hp" << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << mas[i][j] << "|";
		}
		cout << endl;
	}

}

void CGame::move_to(int direction)
{
	if (direction == 2)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = col - 1; j >= 0; j--)
			{
				for (int z = col - (col - j); z >= 0; z--)
				{
					if (mas[z][i] != 0 && z != j)
					{
						if (mas[j][i] == mas[z][i])
						{
							mas[j][i] = mas[j][i] + mas[z][i];
							mas[z][i] = 0;
							minusHP = mas[j][i];
							slogeniya = true;
							break;
						}
						else if (mas[j][i] == 0)
						{
							mas[j][i] = mas[z][i];
							mas[z][i] = 0;
						}
						else
							break;
					}
				}
			}
		}
	}

	if (direction == 4)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				for (int z = j; z < col; z++)
				{
					if (mas[i][z] != 0 && z != j)
					{
						if (mas[i][j] == mas[i][z])
						{
							mas[i][j] = mas[i][j] + mas[i][z];
							mas[i][z] = 0;
							minusHP = mas[i][j];
							slogeniya = true;
							break;
						}
						else if (mas[i][j] == 0)
						{
							mas[i][j] = mas[i][z];
							mas[i][z] = 0;
						}
						else
							break;
					}
				}
			}
		}
	}
	if (direction == 6)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = col - 1; j >= 0; j--)
			{
				for (int z = col - (col - j); z >= 0; z--)
				{
					if (mas[i][z] != 0 && z != j)
					{
						if (mas[i][j] == mas[i][z])
						{
							mas[i][j] = mas[i][j] + mas[i][z];
							mas[i][z] = 0;
							minusHP = mas[i][j];
							slogeniya = true;
							break;
						}
						else if (mas[i][j] == 0)
						{
							mas[i][j] = mas[i][z];
							mas[i][z] = 0;
						}
						else
							break;
					}
				}
			}
		}
	}
	if (direction == 8)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				for (int z = j; z < col; z++)
				{
					if (mas[z][i] != 0 && z != j)
					{
						if (mas[j][i] == mas[z][i])
						{
							mas[j][i] = mas[j][i] + mas[z][i];
							mas[z][i] = 0;
							minusHP = mas[j][i];
							slogeniya = true;
							break;
						}
						else if (mas[j][i] == 0)
						{
							mas[j][i] = mas[z][i];
							mas[z][i] = 0;
						}
						else
							break;

					}
				}
			}
		}
	}
}

void CGame::run()
{
	rand_count();
	rand_count();

	for (int i = 1; i < 999; i++)
	{
		show();

		cin >> key;

		if (key == 2 || key == 4 || key == 6 || key == 8)
		{
			move_to(key);
			if (i % 2)
			{
				cout << "xodit perviu" << endl;

				if (slogeniya == true)
					helth_playerTwo -= minusHP;
				if (helth_playerTwo <= 0)
				{
					cout << "Perviu igrok vigral!" << endl;
					exit(1);
				}
			}
			else{
				cout << "xodit vtorou" << endl;

				if (slogeniya == true)
					helth_playerOne -= minusHP;
				if (helth_playerOne <= 0)
				{
					cout << "Vtorou igrok vigral!" << endl;
					exit(1);
				}
			}
		}

		if (oldDirection != key || slogeniya)
		{
			slogeniya = false;
			rand_count();
		}
	}
}