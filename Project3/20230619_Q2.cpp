/*
Q2. p.1105 문제3. QueueTp 템플릿 클래스 작성
*/
#include "QueueTp.h"
#include "worker0.h"
#include <iostream>

const int SIZE = 5;
using namespace std;

int main()
{
	Queue<Worker*> qu[SIZE];
	Worker* lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "직종을 입력하십시오:" << endl << "w: 웨이터\t s: 가수\t" << "t: 가수 겸 웨이터\t q: 종료" << endl;
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q 중에서 하나를 선택하십시오: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w': 
			if (qu[ct].isfull())
				cout << "큐가 가득 차 있습니다." << endl;
			else
			{
				lolas[ct] = new Waiter;

				cin.get();
				lolas[ct]->Set();

				qu[ct].enque(lolas[ct]);
			}
			break;
		case 's': 
			if (qu[ct].isfull())
				cout << "큐가 가득 차 있습니다." << endl;
			else
			{
				lolas[ct] = new Singer;

				cin.get();
				lolas[ct]->Set();

				qu[ct].enque(lolas[ct]);
			}
			break;
		case 't': 
			if (qu[ct].isfull())
				cout << "큐가 가득 차 있습니다." << endl;
			else
			{
				lolas[ct] = new SingingWaiter;

				cin.get();
				lolas[ct]->Set();

				qu[ct].enque(lolas[ct]);
			}
			break;
		}
	}

	cout << endl << "사원 현황은 다음과 같습니다: " << endl;
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		qu[i].deque(lolas[i]);
		lolas[i]->Show();
	}

	for (i = 0; i < ct; i++)
		delete lolas[i];

	cout << endl << "프로그램을 종료합니다." << endl;

	return 0;

}