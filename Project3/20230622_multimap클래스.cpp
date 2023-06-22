#include <iostream>
#include <string>
#include <map>
#include <algorithm>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
	using namespace std;
	MapCode codes;

	codes.insert(Pair(415, "샌프란시스코"));
	codes.insert(Pair(510, "오클랜드"));
	codes.insert(Pair(718, "브루클린"));
	codes.insert(Pair(415, "샌라파엘"));
	codes.insert(Pair(510, "버클리"));

	cout << "지역 코드가 415인 도시수: " << codes.count(415) << endl;
	cout << "지역 코드가 718인 도시수: " << codes.count(718) << endl;
	cout << "지역 코드가 510인 도시수: " << codes.count(510) << endl;
	cout << "지역 코드    도시\n";

	MapCode::iterator it;
	for (it = codes.begin(); it != codes.end(); ++it)
		cout << "      " << (*it).first << "    " << (*it).second << endl;

	pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
	cout << "지역 코드가 718인 도시들:\n";
	for (it = range.first; it != range.second; ++it)
		cout << (*it).second << endl;

	return 0;
}