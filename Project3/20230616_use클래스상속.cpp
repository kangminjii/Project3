#include "20230616_Ŭ�������.h"
#include <iostream>

using namespace std;

int main()
{
	//Monster ms("Monster");
	//ms.Name();

	//FlyingMonster fm("FlyingMonster", true);
	//fm.Name(); // �θ𿡰� ��ӹ޾Ƽ� ��밡��
	//fm.ShowName();

	// p.904~906
	/*TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);

	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << ": Ź���밡 �ִ�." << endl;
	else
		cout << ": Ź���밡 ����." << endl;

	player1.Name();
	if(player1.HasTable())
		cout << ": Ź���밡 �ִ�." << endl;
	else
		cout << ": Ź���밡 ����." << endl;

	cout << "�̸�: ";
	rplayer1.Name();
	cout << "; ��ŷ: " << rplayer1.Rating() << endl;

	RatedPlayer rplayer2(1212, player1);
	cout << "�̸�: ";
	rplayer2.Name();
	cout << "; ��ŷ: " << rplayer2.Rating() << endl;*/


	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);

	cout << "baseDMA ��ü�� ����Ѵ�: " << endl;
	cout << shirt << endl;

	cout << "lacksDMA ��ü�� ����Ѵ�: " << endl;
	cout << balloon << endl;
	
	cout << "hasDMA ��ü�� ����Ѵ�: " << endl;
	cout << map << endl;

	lacksDMA balloon2(balloon);
	cout << "lacksDMA ���� ���: " << endl;
	cout << balloon2 << endl;

	hasDMA map2;
	map2 = map;
	cout << "hasDMA ���� ���: " << endl;
	cout << map2 << endl;


	return 0;
}