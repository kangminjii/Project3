#include <iostream>
#include "Circle2D.h"
#include "MyPoint.h"

double Circle2D::getRadius() const
{
	return radius;
}

void Circle2D::setRadius(double radius1)
{
	radius = radius1;
}

Circle2D::Circle2D(double x1, double y1, double radius1)
	: GeometricObject(x1, y1), radius(radius1)
{
}

Circle2D::Circle2D(const GeometricObject& geo, double radius1)
	: GeometricObject(geo)
{
	radius = radius1;
}

Circle2D::~Circle2D()
{
}

double Circle2D::getArea() const
{
	return radius * radius * 3.14;
}

double Circle2D::getPerimeter() const
{
	return 2 * radius * 3.14;
}

bool Circle2D::contains(double x1, double y1)
{
	double distance = sqrt(pow(x1 - getX(), 2) + pow(y1 - getY(), 2));

	if (distance <= radius)	return true;
	else					return false;
}

bool Circle2D::contains(const Circle2D& circle)
{
	if (sqrt(pow(circle.getX() - getX(), 2) + pow(circle.getY() - getY(), 2)) <= abs(radius - circle.radius))
	{
		return true;
	}
	else return false;
}

bool Circle2D::overlaps(const Circle2D& circle)
{
	double distance = sqrt(pow(circle.getX() - getX(), 2) + pow(circle.getY() - getY(), 2));

	if (contains(circle) == false)
	{
		if (distance <= circle.radius + radius)	return true;
		else return false;
	}
	else return true;
}

bool contains(const Circle2D& circle, const MyPoint& p)
{
	if (sqrt(pow(circle.getX() - p.getX(), 2) + pow(circle.getY() - p.getY(), 2)) <= circle.radius)
		return true;
	else return false;
}