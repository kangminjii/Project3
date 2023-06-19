#define _CRT_SECURE_NO_WARNINGS
#include "20230616_Ŭ�������.h"
#include <iostream>

Monster::Monster(string str) //�����ǹ�
	:name(str)
{
	name = str;
}
void Monster::Name() const
{
	cout << name << endl;
}

void Monster::SetName(string str)
{
	name = str;
}

string Monster::GetName()
{
	return name;
}

FlyingMonster::FlyingMonster(string str, bool isFlying)
	: isFlying(isFlying)
{
	SetName(str);
}

void FlyingMonster::ShowName()
{
	if (isFlying)
		cout << GetName() << "�� �ϴ��� ���� �ִ�." << endl;

}

// p.904~906
TableTennisPlayer::TableTennisPlayer(const string& fn, const string& ln, bool ht) 
	: firstname(fn), lastname(ln), hasTable(ht)
{
}

void TableTennisPlayer::Name() const
{
	cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht)
	: TableTennisPlayer(fn, ln, ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp)
	: TableTennisPlayer(tp), rating(r)
{
}

// p.962~968
// baseDMA �޼ҵ��
baseDMA::baseDMA(const char* l, int r)
{
	cout << "baseDMA ������" << endl;
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}
baseDMA::baseDMA(const baseDMA& rs)
{
	cout << "baseDMA ������" << endl;
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
}
baseDMA::~baseDMA()
{
	cout << "baseDMA �Ҹ���" << endl;
	delete[] label;
}
baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}
std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << "��ǥ: " << rs.label << endl;
	os << "���: " << rs.rating << endl;
	return os;
}

// lacksDMA �޼ҵ��
lacksDMA::lacksDMA(const char* c, const char* l, int r)
	: baseDMA(l, r)
{
	cout << "lacksDMA ������" << endl;
	strncpy(color, c, 39);
	color[39] = '\0';
}
lacksDMA::lacksDMA(const char* c, const baseDMA& rs)
	: baseDMA(rs)
{
	cout << "lacksDMA ������" << endl;
	strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;
	os << "����: " << ls.color << endl;
	return os;
}

// hasDMA �޼ҵ��
hasDMA::hasDMA(const char* s, const char* l, int r)
	: baseDMA(l, r)
{
	cout << "hasDMA ������" << endl;
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs)
	: baseDMA(rs)
{
	cout << "hasDMA ������" << endl;
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs)
	: baseDMA(hs)
{
	cout << "hasDMA ������" << endl;
	style = new char[strlen(hs.style) + 1];
	strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	cout << "hasDMA �Ҹ���" << endl;
	delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	 if (this == &hs)
		return *this;
	 baseDMA::operator=(hs);
	 delete[] style;
	 style = new char[strlen(hs.style) + 1];
	 strcpy(style, hs.style);
	return *this;
}
std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const baseDMA&)hs;
	os << "��Ÿ��: " << hs.style << endl;
	return os;
}
