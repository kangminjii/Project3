#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

//const char* file = "guests.txt";
const int LIM = 20;
struct planet
{
	char name[LIM];
	double population;
	double g;
};
const char* file = "planets.dat";
inline void eatline() { while (std::cin.get() != '\n') continue; }

int main()
{
	using namespace std;

	// #1

	string filename;

	cout << "�� ������ ���� �̸��� �Է��Ͻʽÿ�: ";
	cin >> filename;

	ofstream fout(filename.c_str());

	fout << "��� ��ȣ ���⿡ �����Ͻʽÿ�." << endl;
	cout << "��� ��ȣ�� �Է��Ͻʽÿ�: ";
	float secret;
	cin >> secret;
	fout << "������ ��� ��ȣ�� " << secret << "�Դϴ�." << endl;
	fout.close();

	ifstream fin(filename.c_str());
	cout << filename << " ������ ������ ������ �����ϴ�." << endl;
	char ch;
	while (fin.get(ch))
		cout << ch;

	cout << "���α׷��� �����մϴ�." << endl;
	fin.close();

	// #2

	char ch;

	ifstream fin;
	fin.open(file);

	if (fin.is_open())
	{
		cout << file << " ������ ���� ������ ������ �����ϴ�:" << endl;
		while (fin.get(ch))
			cout << ch;

		fin.close();
	}

	ofstream fout(file, ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "����� ���� " << file << " ������ �� �� �����ϴ�." << endl;
		exit(EXIT_FAILURE);
	}

	cout << "���ο� �մ� �̸����� �Է��Ͻʽÿ�(�������� �� �� �Է�):" << endl;
	string name;
	while (getline(cin, name) && name.size() > 0)
	{
		fout << name << endl;
	}
	fout.close();

	fin.clear();
	fin.open(file);
	if (fin.is_open())
	{
		cout << file << " ������ ���� ������ ������ �����ϴ�:" << endl;
		while (fin.get(ch))
			cout << ch;

		fin.close();
	}

	cout << "���α׷��� �����մϴ�." << endl;


	 // #3

	planet pl;
	cout << fixed;

	fstream finout;
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);

	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);
	
		cout << file << " ������ ���� ������ ������ �����ϴ�: " << endl;
		while (finout.read((char*)&pl, sizeof pl))
		{
			cout << ct++ << ": " << setw(LIM) << pl.name << ": " << setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		if (finout.eof())
			finout.clear();
		else
		{
			cerr << file << " ������ �дٰ� ���� �߻�." << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " ������ �� �� �����ϴ�. ����." << endl;
		exit(EXIT_FAILURE);
	}

	// ���ڵ� ����
	cout << "������ ���ڵ� ��ȣ�� �Է��Ͻʽÿ�: ";
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "�߸��� ���ڵ� ��ȣ�Դϴ�. ����." << endl;
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof pl;
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "���ڵ带 ã�ٰ� ���� �߻�." << endl;
		exit(EXIT_FAILURE);
	}

	finout.read((char*)&pl, sizeof pl);
	cout << "���� ���ڵ��� ����:" << endl;
	cout << rec << ": " << setw(LIM) << pl.name << ": " << setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;
	if (finout.eof())
		finout.clear();

	cout << "�༺�� �̸��� �Է��Ͻʽÿ�: ";
	cin.get(pl.name, LIM);
	eatline();
	cout << "�༺�� �α��� �Է��Ͻʽÿ�: ";
	cin >> pl.population;
	cout << "�༺�� �߷°��ӵ��� �Է��Ͻʽÿ�: ";
	cin >> pl.g;

	finout.seekp(place);
	finout.write((char*)&pl, sizeof pl) << flush;
	if (finout.fail())
	{
		cerr << "���ٰ� ���� �߻�." << endl;
		exit(EXIT_FAILURE);
	}

	ct = 0;
	finout.seekg(0);

	cout << file << " ������ ������ ������ ������ �����ϴ�.:" << endl;
	while (finout.read((char*)&pl, sizeof pl))
	{
		cout << rec << ": " << setw(LIM) << pl.name << ": " << setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;

	}
	finout.close();
	cout << "���α׷��� �����մϴ�." << endl;


	return 0;
}