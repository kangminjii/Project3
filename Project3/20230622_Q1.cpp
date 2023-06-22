/*
Q1. 홀수의 양의 정수 k가 주어졌을 때, 가로 세로의 크기가 k인 공간에 오른쪽으로 정렬된 삼각형을
	출력하는 프로그램을 작성하시오.
	이 때 삼각형의 모서리는 '*'로 출력하고, 삼각형의 내부의 문자는 '+'로 채워야 한다.

	조건 > 삼각형 크기는 (3 <= 크기 <= 99 ) 사이의 정수 중에 홀수가 입력되고
			잘못된 데이터가 입력되는 경우는 없다.

	ex> 3					5
		  *					    *
		* *					  * *
		  *					* + *
		  					  * *
		  						*
*/

#include <iostream>

using namespace std;

int main()
{
	int k = 0;

	while (k < 3 || k > 99 || k % 2 == 0)
	{
		cout << "3이상 99이하의 홀수를 입력해주세요 : ";
		cin >> k;
	}


	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (i < k / 2)
			{
				if (i + j == k - 1)		cout << "*";
				else if (j == k - 1)	cout << "*";
				else if (i + j >= k)	cout << "+";
				else					cout << " ";
			}
			else
			{
				if (i == j)						cout << "*";
				else if (j == k - 1)			cout << "*";
				else if (i + j >= k && i < j)	cout << "+";
				else							cout << " ";
			}
		}
		cout << endl;
	}


	return 0;
}