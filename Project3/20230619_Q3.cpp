///*
//Q3. �����Ʈ�� �����϶�.
//	���� 1, 2, 3 ������ ���� ���α׷��� �ۼ��ϰ� ������ ������ ���϶�.
//*/
//
//#include <iostream>
//
//using namespace std;
//
//const int SIZE = 7;
//void swap(int* a, int* b);
//
//int main()
//{
//	int sort[SIZE] = { 6, 4, 3, 7, 1, 9, 8 }; // ������ �迭
//	char check[SIZE];
//	int isSorted = 0, count = 0, exchangeNumber = 0, compareNumber = 0;
//
//
//
//	// ���� 1.
//
//	
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		for (int j = i; j < SIZE - 1; j++)
//		{
//			compareNumber++;
//
//			if (sort[SIZE - 1 - j] < sort[SIZE - 2 - j])
//			{
//				swap(&sort[SIZE - 1 - j], &sort[SIZE - 2 - j]);
//				check[SIZE - 2 - j] = '+';
//				exchangeNumber++;
//			}
//			else
//			{
//				check[SIZE - 2 - j] = '-';
//			}
//
//		}
//	}
//	
//
//	cout << endl;
//	cout << "�� �񱳸� " << compareNumber << "ȸ �߽��ϴ�." << endl;
//	cout << "�� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl;
//}
//
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}