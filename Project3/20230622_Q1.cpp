/*
Q1. Ȧ���� ���� ���� k�� �־����� ��, ���� ������ ũ�Ⱑ k�� ������ ���������� ���ĵ� �ﰢ����
	����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	�� �� �ﰢ���� �𼭸��� '*'�� ����ϰ�, �ﰢ���� ������ ���ڴ� '+'�� ä���� �Ѵ�.

	���� > �ﰢ�� ũ��� (3 <= ũ�� <= 99 ) ������ ���� �߿� Ȧ���� �Էµǰ�
			�߸��� �����Ͱ� �ԷµǴ� ���� ����.

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
		cout << "3�̻� 99������ Ȧ���� �Է����ּ��� : ";
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