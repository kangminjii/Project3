/*
Q1. GemoetricObject ���̽� Ŭ������ �ؼ� ���� Ŭ�������� �缳���϶�.
	Circle2D, Rectangle2D, MyPoint Ŭ������ �߻� Ŭ���� ��� ������ �����Ͽ� �ٽ� �ۼ��϶�.
	
	UML Ŭ���� ���̾�׷��� �ۼ�
*/

#include "GeometricObject.h"
#include "MyPoint.h"
#include "Circle2D.h"
#include "Rectangle2D.h"
#include <iostream>

using namespace std;

int main()
{
	// �⺻ Ŭ����
	GeometricObject original(0, 0);

	// MyPoint ����
	MyPoint m1(0, 0);
	MyPoint m2(1, 1);

	cout << "m1�� m2 ������ �Ÿ� : " << m1.distance(m2) << endl;

	// Circle2D ����
	Circle2D c1(original, 5);
	Circle2D c2(1, 1, 4);

	cout << boolalpha;
	cout << "c1�� ����: " << c1.getArea() << endl;
	cout << "c2�� �ѷ�: " << c2.getPerimeter() << endl;
	cout << "c1�� c2�� �����ϴ°�? " << c1.contains(c2) << endl;
	cout << "c2�� c1�� ��ø�ϴ°�? " << c2.overlaps(c1) << endl;

	//// Rectangle2D ����
	Rectangle2D r1(original, 1, 1);
	Rectangle2D r2(3, 4, 10, 10);

	cout << "r1�� ����: " << r1.getArea() << endl;
	cout << "r2�� �ѷ�: " << r2.getPerimeter() << endl;
	cout << "r1�� r2�� �����ϴ°�? " << r1.contains(r2) << endl;
	cout << "r1�� r2�� ��ø�ϴ°�? " << r1.overlaps(r2) << endl;

	return 0;
}