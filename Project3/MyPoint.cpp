#include "MyPoint.h"
#include <cmath>

MyPoint::MyPoint(double x1, double y1)
	: GeometricObject(x1, y1)
{
}

MyPoint::~MyPoint()
{
}

double MyPoint::distance(const MyPoint& p)
{
	return sqrt(pow(getX() - p.getX(), 2) + pow(getY() - p.getY(), 2));
}
