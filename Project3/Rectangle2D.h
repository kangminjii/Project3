#pragma once
#include "MyPoint.h"

class Rectangle2D : public GeometricObject
{
private:
	double width;
	double height;
public:
	double getWidth() const;
	double getHeight() const;

	void setWidth(double w);
	void setHeight(double h);

	Rectangle2D(double x, double y, double w, double h);
	Rectangle2D(const GeometricObject& geo, double width = 0, double height = 0);
	~Rectangle2D();

	virtual double getArea() const;
	virtual double getPerimeter() const;

	virtual bool contains(double x, double y);
	virtual bool contains(const Rectangle2D& r);
	virtual bool overlaps(const Rectangle2D& r);

	friend bool contains(const Rectangle2D& r, const MyPoint& p);
};