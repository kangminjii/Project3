/*
Q1. Encoding
	파일 내의 모든 바이트에 임의 수를 더하도록 파일을 부호화 하라.
	사용자가 입력 파일 이름과 출력 파일 이름을 입력하면
	입력 파일의 암호화된 버전을 출력 파일로 저장하는 프로그램을 작성하라.
	ex> Input source filename : source.txt
		Input encoding filename : encoding.txt
	더해진 임의 수를 encoding.txt의 맨앞에 기입하도록 한다.

Q2.	Decoding
	암호화된 파일을 복호화 하는 프로그램을 작성하라.
	사용자가 입력 파일 이름과 출력 파일 이름을 입력하면
	입력 파일의 암호가 풀린 버전을 출력 파일에 저장하라.
	ex> Input source filename : encoding.txt
		Input decoding filename : dest.txt
	맨 앞에 더해진 임의 수를 읽어 decoding 하도록 한다.
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
	
	// for문 안쓰고 while문으로 file이 열려있을때동안 받을 수 있음
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
