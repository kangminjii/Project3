#include<iostream>
#include <cstring>

int main()
{
	using namespace std;

	const char* state1 = "Florida";
	const char* state2 = "Kansas";
	const char* state3 = "Euphoria";

	int len = strlen(state2);
	
	cout << "루프 인덱스 증가:" << endl;
	for (int i = 1; i <= len; i++)
	{
		cout.write(state2, i);
		cout << endl;
	}
	cout << "루프 인덱스 감소:" << endl;
	for (int i = len; i > 0; i--)
	{
		cout.write(state2, i);
		cout << endl;
	}

	cout << "문자열 길이 초과:" << endl;
	cout.write(state2, len + 10) << endl;

	return 0;
}