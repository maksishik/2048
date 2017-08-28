#include <iostream>
#include "CGame.h"
#include <time.h>
using namespace std;

void main() {
	srand(time(NULL));
	CGame *obj = new CGame();
	obj->run();
	delete obj;
}