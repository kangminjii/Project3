/*
Q2. p.1105 ����3. QueueTp ���ø� Ŭ���� �ۼ�
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
		cout << "������ �Է��Ͻʽÿ�:" << endl << "w: ������\t s: ����\t" << "t: ���� �� ������\t q: ����" << endl;
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q �߿��� �ϳ��� �����Ͻʽÿ�: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w': 
			if (qu[ct].isfull())
				cout << "ť�� ���� �� �ֽ��ϴ�." << endl;
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
				cout << "ť�� ���� �� �ֽ��ϴ�." << endl;
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
				cout << "ť�� ���� �� �ֽ��ϴ�." << endl;
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

	cout << endl << "��� ��Ȳ�� ������ �����ϴ�: " << endl;
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		qu[i].deque(lolas[i]);
		lolas[i]->Show();
	}

	for (i = 0; i < ct; i++)
		delete lolas[i];

	cout << endl << "���α׷��� �����մϴ�." << endl;

	return 0;

}