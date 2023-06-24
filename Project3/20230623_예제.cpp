#include <iostream>
#include <cmath>

const int Limit = 255;
int main()
{
	using namespace std;
	cout.setf(ios_base::left, ios_base::adjustfield); // ���� ����, �÷��� ��ȣ ���
	cout.setf(ios_base::showpos); //
	cout.setf(ios_base::showpoint);
	cout.precision(3); // ���е� 3

	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield); // ������ E ǥ�� ���

	cout << "���� ����:" << endl;
	for (long n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|" << endl;
	}

	cout.setf(ios_base::internal, ios_base::adjustfield); // ���� ����
	cout.setf(old, ios_base::floatfield); // ���� �Ҽ��� ǥ��

	cout << "���� ����:" << endl;
	for (long n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|" << endl;
	}

	cout.setf(ios_base::right, ios_base::adjustfield); // ������ ����
	cout.setf(ios_base::fixed, ios_base::floatfield); // ���� �Ҽ��� ǥ��

	cout << "������ ����:" << endl;
	for (long n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|" << endl;
	}


	//  ���ܹ߻�
	/*cout << "���� �Է��Ͻʽÿ�: ";
	int sum = 0; 
	int input;
	while (cin >> input)
	{
		sum += input;
	}

	cout << "���������� �Է��� �� = " << input << endl;
	cout << "�հ� = " << sum << endl;*/

	char input[Limit];

	cout << "getline()�� ó���� ���ڿ��� �Է��Ͻʽÿ�: " << endl;
	cin.getline(input, Limit, '#'); // # ���� ���ڸ� �а� ������
	cout << "������ ���� �Է��ϼ̽��ϴ�: " << endl;
	cout << input << "\n1�ܰ�Ϸ�\n";

	char ch;
	cin.get(ch); // #���� ����
	cout << "���� �Է� ���ڴ� " << ch << "�Դϴ�." << endl;

	if (ch != '\n')
		cin.ignore(Limit, '\n');

	cout << "get()�� ó���� ���ڿ��� �Է��Ͻʽÿ�:" << endl;
	cin.get(input, Limit, '#'); // ���� ���� #�� ���д�
	cout << "������ ���� �Է��ϼ̽��ϴ�:" << endl;
	cout << input << "\n2�ܰ� �Ϸ�\n";

	cin.get(ch); // #
	cout << "���� �Է� ���ڴ� " << ch << "�Դϴ�." << endl;



	return 0;
}