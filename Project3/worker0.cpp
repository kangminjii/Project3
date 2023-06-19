#include "worker0.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker()
{
}
void Worker::Data() const
{
	cout << "��� �̸�: " << fullname << endl;
	cout << "��� ��ȣ: " << id << endl;
}
void Worker::Get()
{
	getline(cin, fullname);
	cout << "��� ��ȣ�� �Է��Ͻʽÿ�: ";
	cin >> id;
	while (cin.get() != '\n')	continue;
}


void Waiter::Set()
{
	cout << "�������� �̸��� �Է��Ͻʽÿ�: ";
	Worker::Get();
	Get();
}
void Waiter::Show() const
{
	cout << "����: ������" << endl;
	Worker::Data();
	Data();
}
void Waiter::Data() const
{
	cout << "������ ���: " << panache << endl;
}
void Waiter::Get()
{
	cout << "������ ����� �Է��Ͻʽÿ�: ";
	cin >> panache;
	while (cin.get() != '\n')	continue;
}


const char* Singer::pv[] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };

void Singer::Set()
{
	cout << "������ �̸��� �Է��Ͻʽÿ�: ";
	Worker::Get();
	Get();
}
void Singer::Show() const
{
	cout << "����: ����" << endl;
	Worker::Data();
	Data();
}
void Singer::Data() const
{
	cout << "��Ҹ� ����: " << pv[voice] << endl;
}
void Singer::Get()
{
	cout << "������ ��Ҹ� ���� ��ȣ�� �Է��Ͻʽÿ�::" << endl;
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)	cout << endl;
	}
	if (i % 4 != 0)	cout << endl;

	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "0���� ũ�ų� ���� " << Vtypes << "���� ���� ���� �Է��Ͻÿ�." << endl;
	while (cin.get() != '\n')	continue;
}


void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}
void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}
void SingingWaiter::Set()
{
	cout << "���� �� �������� �̸��� �Է��Ͻʽÿ�: ";
	Worker::Get();
	Get();
}
void SingingWaiter::Show() const
{
	cout << "����: ���� �� ������" << endl;
	Worker::Data();
	Data();
}