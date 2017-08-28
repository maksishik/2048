#include <iostream>

using namespace std;

class CGame
{
private:
	const int row;
	const int col;
	int mas[4][4];
	int key;
	int size;
	int random_stolbec;
	int random_stroka;
	int random_count;
	bool slogeniya;
	int oldDirection;
	int helth_playerOne;
	int helth_playerTwo;
	int first, second;
	int minusHP;
public:
	CGame();
	bool rand_count();
	void show();
	void move_to(int);
	void run();
};