/*
Q1. Encoding
	���� ���� ��� ����Ʈ�� ���� ���� ���ϵ��� ������ ��ȣȭ �϶�.
	����ڰ� �Է� ���� �̸��� ��� ���� �̸��� �Է��ϸ�
	�Է� ������ ��ȣȭ�� ������ ��� ���Ϸ� �����ϴ� ���α׷��� �ۼ��϶�.
	ex> Input source filename : source.txt
		Input encoding filename : encoding.txt
	������ ���� ���� encoding.txt�� �Ǿտ� �����ϵ��� �Ѵ�.

Q2.	Decoding
	��ȣȭ�� ������ ��ȣȭ �ϴ� ���α׷��� �ۼ��϶�.
	����ڰ� �Է� ���� �̸��� ��� ���� �̸��� �Է��ϸ�
	�Է� ������ ��ȣ�� Ǯ�� ������ ��� ���Ͽ� �����϶�.
	ex> Input source filename : encoding.txt
		Input decoding filename : dest.txt
	�� �տ� ������ ���� ���� �о� decoding �ϵ��� �Ѵ�.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	// Q1.
	int size1, size2;
	char ch, temp;
	char key = 1;

	string sourceName;
	cout << "Input source filename : ";
	cin >> sourceName;
	
	fstream input;
	input.open(sourceName, ios_base::in | ios_base::binary);
	input.seekg(0, ios_base::end);
	size1 = input.tellg();
	input.seekg(0);

	string encodeName;
	cout << "Input encoding filename : ";
	cin >> encodeName;
	
	fstream output;
	output.open(encodeName, ios_base::out | ios_base::binary);
	
	// for�� �Ⱦ��� while������ file�� �������������� ���� �� ����
	output << key;
	for (int i = 0; i < size1; i++)
	{
		input.get(ch);
		if (ch == '\n')	temp = '\n';
		else			temp = ch + key;
		output << temp;
	}

	cout << "Encoding Done!" << endl;

	input.close();
	output.close();

	// Q2.
	string sourceName2;
	cout << "Input source filename : ";
	cin >> sourceName2;

	fstream input2;
	input2.open(sourceName2, ios_base::in | ios_base::binary);
	input2.seekg(0, ios_base::end);
	size2 = input2.tellg();
	input2.seekg(0);

	string decodeName;
	cout << "Input decoding filename : ";
	cin >> decodeName;

	fstream output2;
	output2.open(decodeName, ios_base::out | ios_base::binary);


	for (int i = 0; i < size2; i++)
	{
		input2.get(ch);
		if (i == 0) 
		{
			key = ch;
			continue;
		}
		if (ch == '\n')	temp = '\n';
		else			temp = ch - key;
		output2 << temp;
	}

	cout << "Decoding Done!" << endl;

	input2.close();
	output2.close();


	return 0;
}
