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

	cout << "새 파일을 위한 이름을 입력하십시오: ";
	cin >> filename;

	ofstream fout(filename.c_str());

	fout << "비밀 번호 노출에 주의하십시오." << endl;
	cout << "비밀 번호를 입력하십시오: ";
	float secret;
	cin >> secret;
	fout << "귀하의 비밀 번호는 " << secret << "입니다." << endl;
	fout.close();

	ifstream fin(filename.c_str());
	cout << filename << " 파일의 내용은 다음과 같습니다." << endl;
	char ch;
	while (fin.get(ch))
		cout << ch;

	cout << "프로그램을 종료합니다." << endl;
	fin.close();

	// #2

	char ch;

	ifstream fin;
	fin.open(file);

	if (fin.is_open())
	{
		cout << file << " 파일의 현재 내용은 다음과 같습니다:" << endl;
		while (fin.get(ch))
			cout << ch;

		fin.close();
	}

	ofstream fout(file, ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "출력을 위해 " << file << " 파일을 열 수 없습니다." << endl;
		exit(EXIT_FAILURE);
	}

	cout << "새로운 손님 이름들을 입력하십시오(끝내려면 빈 줄 입력):" << endl;
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
		cout << file << " 파일의 현재 내용은 다음과 같습니다:" << endl;
		while (fin.get(ch))
			cout << ch;

		fin.close();
	}

	cout << "프로그램을 종료합니다." << endl;


	 // #3

	planet pl;
	cout << fixed;

	fstream finout;
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);

	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);
	
		cout << file << " 파일의 현재 내용은 다음과 같습니다: " << endl;
		while (finout.read((char*)&pl, sizeof pl))
		{
			cout << ct++ << ": " << setw(LIM) << pl.name << ": " << setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		if (finout.eof())
			finout.clear();
		else
		{
			cerr << file << " 파일을 읽다가 에러 발생." << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " 파일을 열 수 없습니다. 종료." << endl;
		exit(EXIT_FAILURE);
	}

	// 레코드 수정
	cout << "수정할 레코드 번호를 입력하십시오: ";
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "잘못된 레코드 번호입니다. 종료." << endl;
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof pl;
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "레코드를 찾다가 에러 발생." << endl;
		exit(EXIT_FAILURE);
	}

	finout.read((char*)&pl, sizeof pl);
	cout << "현재 레코드의 내용:" << endl;
	cout << rec << ": " << setw(LIM) << pl.name << ": " << setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;
	if (finout.eof())
		finout.clear();

	cout << "행성의 이름을 입력하십시오: ";
	cin.get(pl.name, LIM);
	eatline();
	cout << "행성의 인구를 입력하십시오: ";
	cin >> pl.population;
	cout << "행성의 중력가속도를 입력하십시오: ";
	cin >> pl.g;

	finout.seekp(place);
	finout.write((char*)&pl, sizeof pl) << flush;
	if (finout.fail())
	{
		cerr << "쓰다가 에러 발생." << endl;
		exit(EXIT_FAILURE);
	}

	ct = 0;
	finout.seekg(0);

	cout << file << " 파일의 개정된 내용은 다음과 같습니다.:" << endl;
	while (finout.read((char*)&pl, sizeof pl))
	{
		cout << rec << ": " << setw(LIM) << pl.name << ": " << setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;

	}
	finout.close();
	cout << "프로그램을 종료합니다." << endl;


	return 0;
}