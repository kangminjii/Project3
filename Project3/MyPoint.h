#pragma once
#include "GeometricObject.h"

class MyPoint : public GeometricObject
{
public:
	MyPoint(double x, double y);
	~MyPoint();

	double distance(const MyPoint& p);
};