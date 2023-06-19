#define _CRT_SECURE_NO_WARNINGS
#include "20230616_클래스상속.h"
#include <iostream>

Monster::Monster(string str) //같은의미
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
		cout << GetName() << "은 하늘을 날고 있다." << endl;

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
// baseDMA 메소드들
baseDMA::baseDMA(const char* l, int r)
{
	cout << "baseDMA 생성자" << endl;
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}
baseDMA::baseDMA(const baseDMA& rs)
{
	cout << "baseDMA 생성자" << endl;
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
}
baseDMA::~baseDMA()
{
	cout << "baseDMA 소멸자" << endl;
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
	os << "상표: " << rs.label << endl;
	os << "등급: " << rs.rating << endl;
	return os;
}

// lacksDMA 메소드들
lacksDMA::lacksDMA(const char* c, const char* l, int r)
	: baseDMA(l, r)
{
	cout << "lacksDMA 생성자" << endl;
	strncpy(color, c, 39);
	color[39] = '\0';
}
lacksDMA::lacksDMA(const char* c, const baseDMA& rs)
	: baseDMA(rs)
{
	cout << "lacksDMA 생성자" << endl;
	strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;
	os << "색상: " << ls.color << endl;
	return os;
}

// hasDMA 메소드들
hasDMA::hasDMA(const char* s, const char* l, int r)
	: baseDMA(l, r)
{
	cout << "hasDMA 생성자" << endl;
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs)
	: baseDMA(rs)
{
	cout << "hasDMA 생성자" << endl;
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs)
	: baseDMA(hs)
{
	cout << "hasDMA 생성자" << endl;
	style = new char[strlen(hs.style) + 1];
	strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	cout << "hasDMA 소멸자" << endl;
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
	os << "스타일: " << hs.style << endl;
	return os;
}
