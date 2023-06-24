/*
Q2.�뷮�� ū ������ ���� �뷮���� �����ؼ� ���� ������ ���Ϸ� ������ ���α׷��� �ۼ��϶�.
	����ڷκ��� �ҽ� ���ϸ��� �Է� ���� ��, ���� ���ҵ� ���� ������ ����Ʈ ���� �Է� �޾ƾ� �Ѵ�.

	ex) Enter file name : test.zip
	    Enter file size : 1024
			-> file test.zip.01
			-> file test.zip.02
			-> file test.zip.03
			-> file test.zip.04
			...
			Split Done.

Q3. ����ڷκ��� �ҽ� ������ ����, �ҽ� ������ �̸�, ���� ������ �̸��� 
	�Է� �޾� ���ο� �ϳ��� ���Ϸ� ���ϵ��� �����ϴ� ���α׷��� �ۼ��϶�.
	
	ex > Enter file number : 4
		Enter source file : test.zip.01
		Enter source file : test.zip.02
		Enter source file : test.zip.03
		Enter source file : test.zip.04
		Enter target file : Dest.zip
		...
		Combine Done.
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	// # Q2
	/*string filename;
	int filesize;

	cout << "Enter file name : ";
	cin >> filename;
	cout << "Enter file size : ";
	cin >> filesize;

	fstream file;
	file.open(filename, ios_base::in | ios_base::out | ios_base::binary);
	file.seekg(0, ios_base::end);

	int size = file.tellg();
	int count = size / filesize;
	int remain = size % filesize;
	char* buf = new char[filesize];

	file.seekp(0);
	for (int i = 0; i < count; i++)
	{
		string newfilename = filename + '.' + to_string(i);
		file.read(buf, filesize);
		fstream fin;
		fin.open(newfilename, ios_base::out | ios_base::binary);
		fin.write(buf, filesize);
		fin.close();
		cout << "-> file " << newfilename << endl;
	}
	delete[] buf;
	
	if (remain)
	{
		string newfilename = filename + '.' + to_string(count);
		fstream fin;
		fin.open(newfilename, ios_base::out | ios_base::binary);
		
		char ch;
		while (file.get(ch))
			fin << ch;
		
		fin.close();
		cout << "-> file " << newfilename << endl;
	}
	
	cout << "Split done" << endl;*/


	// # Q3
	
	int filenumber;
	cout << "Enter file number : ";
	cin >> filenumber;
	
	string filename[100];

	for (int i = 0; i < filenumber; i++)
	{
		cout << "Enter source file : ";
		cin >> filename[i];
	}

	string targetfile;
	cout << "Enter target file : ";
	cin >> targetfile;

	for (int i = 0; i < filenumber; i++)
	{
		fstream file;
		file.open(filename[i], ios_base::in | ios_base::out | ios_base::binary);
	}
	
	fstream output;
	output.open(targetfile, ios_base::in | ios_base::out | ios_base::binary);
	output.seekg(0, ios_base::end);

	int size = file.tellg();
	int count = size / filesize;
	int remain = size % filesize;
	char* buf = new char[filesize];

	file.seekp(0);
	for (int i = 0; i < count; i++)
	{
		string newfilename = filename + '.' + to_string(i);
		file.read(buf, filesize);
		fstream fin;
		fin.open(newfilename, ios_base::out | ios_base::binary);
		fin.write(buf, filesize);
		fin.close();
		cout << "-> file " << newfilename << endl;
	}
	delete[] buf;


	return 0;
}

