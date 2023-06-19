#include "StopWatch.h"
#include <iostream>

using namespace std;

int main()
{
	StopWatch s;

	s.start();
	for (int i = 2; i < 11; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " x " << j << " = " << i * j << endl;
		}
	}
	s.stop();
	
	cout << s.getElapsedTime() << "ms °æ°ú";

	return 0;
}
