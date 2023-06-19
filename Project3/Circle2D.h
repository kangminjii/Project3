#pragma once
#include "MyPoint.h"

class Circle2D : public GeometricObject
{
private:
	double radius;

public:
	double getRadius() const;
	void setRadius(double radius);

	Circle2D(double x, double y, double radius);
	Circle2D(const GeometricObject& geo, double radius = 0);
	~Circle2D();

	virtual double getArea() const; // ���� ����
	virtual double getPerimeter() const; // ���� �ѷ�

	virtual bool contains(double x, double y);
	virtual bool contains(const Circle2D& circle);
	virtual bool overlaps(const Circle2D& circle);

	friend bool contains(const Circle2D& circle, const MyPoint& p);
};