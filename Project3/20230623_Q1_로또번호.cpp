/*
Q1. p.1343 7번
*/

#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

vector<int> Lotto(int, int);
int main()
{
	vector<int> winners;
	winners = Lotto(45, 6);

	cout << "로또 번호: " << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << winners[i] << " ";
	}
	cout << endl;

	return 0;
}

vector<int> Lotto(int a, int b)
{
	vector<int> temp;
	srand(time(NULL));
	
	for (int i = 1; i <= a; i++)
	{
		temp.push_back(i);
	}

	random_shuffle(temp.begin(), temp.end());
	
	temp.erase(temp.begin() + b, temp.end());

	return temp;
}
