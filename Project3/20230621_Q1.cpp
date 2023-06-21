/*
Q1. ���ε� ����
*/

#include <iostream>

using namespace std;

unsigned int answer(long long l, unsigned int* v, int n);
void swap(unsigned int* a, unsigned int* b);

int main()
{
	const int n1 = 7;
	const int n2 = 2;

	unsigned int v1[n1] = {15, 5, 3, 7, 9, 14, 0}; // ���ε� ��ġ�� �ִ� �迭 0 ~ l
	unsigned int v2[n2] = { 2, 5 }; // ���ε� ��ġ�� �ִ� �迭 0 ~ l

	answer(15, v1, n1);
	cout << endl;
	answer(5, v2, n2);
	cout << endl;

	return 0;
}

unsigned int answer(long long l, unsigned int* v, int n)
{
	unsigned int d;
	unsigned int temp = 0;
	unsigned int max = 0;

	// ����
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (v[i] > v[j])
				swap(&v[i], &v[j]);
		}
	}
	// �Ÿ��� �� �Ÿ� ����
	for (int i = 0; i < n - 1; i++)
	{
		temp = v[i + 1] - v[i];
		if (max < temp)	max = temp;
	}

	if (max % 2 == 0) // ¦��
	{
		max = max / 2;
		d = max;
	}
	else // Ȧ��
	{
		max = max / 2 + 1;
		d = max;
	}

	return d;
}

void swap(unsigned int* a, unsigned int* b)
{
	unsigned int temp = *a;
	*a = *b;
	*b = temp;
}