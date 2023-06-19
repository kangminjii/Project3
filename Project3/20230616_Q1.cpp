/*
Q1. GemoetricObject 베이스 클래스로 해서 다음 클래스들을 재설계하라.
	Circle2D, Rectangle2D, MyPoint 클래스를 추상 클래스 상속 개념을 적용하여 다시 작성하라.
	
	UML 클래스 다이어그램도 작성
*/

#include "GeometricObject.h"
#include "MyPoint.h"
#include "Circle2D.h"
#include "Rectangle2D.h"
#include <iostream>

using namespace std;

int main()
{
	// 기본 클래스
	GeometricObject original(0, 0);

	// MyPoint 예제
	MyPoint m1(0, 0);
	MyPoint m2(1, 1);

	cout << "m1과 m2 사이의 거리 : " << m1.distance(m2) << endl;

	// Circle2D 예제
	Circle2D c1(original, 5);
	Circle2D c2(1, 1, 4);

	cout << boolalpha;
	cout << "c1의 면적: " << c1.getArea() << endl;
	cout << "c2의 둘레: " << c2.getPerimeter() << endl;
	cout << "c1은 c2를 포함하는가? " << c1.contains(c2) << endl;
	cout << "c2와 c1는 중첩하는가? " << c2.overlaps(c1) << endl;

	//// Rectangle2D 예제
	Rectangle2D r1(original, 1, 1);
	Rectangle2D r2(3, 4, 10, 10);

	cout << "r1의 면적: " << r1.getArea() << endl;
	cout << "r2의 둘레: " << r2.getPerimeter() << endl;
	cout << "r1은 r2를 포함하는가? " << r1.contains(r2) << endl;
	cout << "r1는 r2와 중첩하는가? " << r1.overlaps(r2) << endl;

	return 0;
}