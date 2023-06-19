#pragma once

class GeometricObject
{
private:
	double x;
	double y;
public:
	GeometricObject();
	GeometricObject(double, double);
	virtual ~GeometricObject();

	double getX() const;
	double getY() const;
	void setX(double);
	void setY(double);

	virtual double getArea() const;
	virtual double getPerimeter() const;

	virtual bool contains(double x, double y);
	virtual bool contains(const GeometricObject& geo);
	virtual bool overlaps(const GeometricObject& geo);
};