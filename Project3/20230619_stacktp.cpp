#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

using namespace std;

int main()
{
	Stack<string> st;
	char ch;
	string po;
	cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, " << endl << "�����Ϸ��� Q�� �Է��Ͻʽÿ�." << endl;

	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << "\a";
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ�: ";
			cin >> po;
			if (st.isfull())
				cout << "������ ���� �� �ֽ��ϴ�." << endl;
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "������ ��� �ֽ��ϴ�. " << endl;
			else
			{
				st.pop(po);
				cout << "#" << po << " �ֹ����� ó���߽��ϴ�." << endl;
				break;
			}
		}

		cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, " << endl << "�����Ϸ��� Q�� �Է��Ͻʽÿ�." << endl;
	}

	cout << "���α׷��� �����մϴ�." << endl;

	return 0;
}