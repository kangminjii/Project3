#include "20230616_클래스상속.h"
#include <iostream>

using namespace std;

int main()
{
	//Monster ms("Monster");
	//ms.Name();

	//FlyingMonster fm("FlyingMonster", true);
	//fm.Name(); // 부모에게 상속받아서 사용가능
	//fm.ShowName();

	// p.904~906
	/*TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);

	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << ": 탁구대가 있다." << endl;
	else
		cout << ": 탁구대가 없다." << endl;

	player1.Name();
	if(player1.HasTable())
		cout << ": 탁구대가 있다." << endl;
	else
		cout << ": 탁구대가 없다." << endl;

	cout << "이름: ";
	rplayer1.Name();
	cout << "; 랭킹: " << rplayer1.Rating() << endl;

	RatedPlayer rplayer2(1212, player1);
	cout << "이름: ";
	rplayer2.Name();
	cout << "; 랭킹: " << rplayer2.Rating() << endl;*/


	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);

	cout << "baseDMA 객체를 출력한다: " << endl;
	cout << shirt << endl;

	cout << "lacksDMA 객체를 출력한다: " << endl;
	cout << balloon << endl;
	
	cout << "hasDMA 객체를 출력한다: " << endl;
	cout << map << endl;

	lacksDMA balloon2(balloon);
	cout << "lacksDMA 복사 결과: " << endl;
	cout << balloon2 << endl;

	hasDMA map2;
	map2 = map;
	cout << "hasDMA 대입 결과: " << endl;
	cout << map2 << endl;


	return 0;
}