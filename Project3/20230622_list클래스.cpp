#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void outint(int n) { std::cout << n << " "; }

int main()
{
	using namespace std;
	list<int> one(5, 2);
	int stuff[5] = { 1, 2, 4, 8, 6 };
	
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);
	
	int more[6] = { 6,4, 2,4,6,5 };
	list<int> three(two);
	three.insert(three.end(), more, more + 6);

	cout << "리스트 one: ";
	for_each(one.begin(), one.end(), outint);
	cout << endl;

	cout << "리스트 two: ";
	for_each(two.begin(), two.end(), outint);
	cout << endl;

	cout << "리스트 three: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;

	three.remove(2);
	cout << "리스트 three에서 2들을 삭제: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;

	three.splice(three.begin(), one);
	cout << "접목 후의 리스트 three: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;
	cout << "리스트 one: ";
	for_each(one.begin(), one.end(), outint);
	cout << endl;

	three.unique();
	cout << "단일화 후의 리스트 three: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;

	three.sort();
	three.unique();
	cout << "정렬과 단일화 후의 리스트 three: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;

	two.sort();
	three.merge(two); // sort해야 합병 가능
	cout << "정렬된 리스트 two를 리스트 three에 합병: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;

	return 0;
}