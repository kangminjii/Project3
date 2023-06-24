#include <iostream>
#include <cmath>

const int Limit = 255;
int main()
{
	using namespace std;
	cout.setf(ios_base::left, ios_base::adjustfield); // 왼쪽 정렬, 플러스 부호 출력
	cout.setf(ios_base::showpos); //
	cout.setf(ios_base::showpoint);
	cout.precision(3); // 정밀도 3

	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield); // 과학적 E 표시 사용

	cout << "왼쪽 정렬:" << endl;
	for (long n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|" << endl;
	}

	cout.setf(ios_base::internal, ios_base::adjustfield); // 내부 정렬
	cout.setf(old, ios_base::floatfield); // 고정 소수점 표기

	cout << "내부 정렬:" << endl;
	for (long n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|" << endl;
	}

	cout.setf(ios_base::right, ios_base::adjustfield); // 오른쪽 정렬
	cout.setf(ios_base::fixed, ios_base::floatfield); // 고정 소수점 표기

	cout << "오른쪽 정렬:" << endl;
	for (long n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|" << endl;
	}


	//  예외발생
	/*cout << "수를 입력하십시오: ";
	int sum = 0; 
	int input;
	while (cin >> input)
	{
		sum += input;
	}

	cout << "마지막으로 입력한 값 = " << input << endl;
	cout << "합계 = " << sum << endl;*/

	char input[Limit];

	cout << "getline()이 처리할 문자열을 입력하십시오: " << endl;
	cin.getline(input, Limit, '#'); // # 종료 문자를 읽고 버린다
	cout << "다음과 같이 입력하셨습니다: " << endl;
	cout << input << "\n1단계완료\n";

	char ch;
	cin.get(ch); // #이후 문자
	cout << "다음 입력 문자는 " << ch << "입니다." << endl;

	if (ch != '\n')
		cin.ignore(Limit, '\n');

	cout << "get()이 처리할 문자열을 입력하십시오:" << endl;
	cin.get(input, Limit, '#'); // 종료 문자 #을 냅둔다
	cout << "다음과 같이 입력하셨습니다:" << endl;
	cout << input << "\n2단계 완료\n";

	cin.get(ch); // #
	cout << "다음 입력 문자는 " << ch << "입니다." << endl;



	return 0;
}