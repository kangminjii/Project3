///*
//Q3. 버블소트를 구현하라.
//	버전 1, 2, 3 각각에 대해 프로그램을 작성하고 각각의 성능을 비교하라.
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
//	int sort[SIZE] = { 6, 4, 3, 7, 1, 9, 8 }; // 정렬할 배열
//	char check[SIZE];
//	int isSorted = 0, count = 0, exchangeNumber = 0, compareNumber = 0;
//
//
//
//	// 버젼 1.
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
//	cout << "총 비교를 " << compareNumber << "회 했습니다." << endl;
//	cout << "총 교환을 " << exchangeNumber << "회 했습니다." << endl;
//}
//
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}