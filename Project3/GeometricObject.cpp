#include "GeometricObject.h"

GeometricObject::GeometricObject()
    : x(0), y(0)
{
}

GeometricObject::GeometricObject(double x1, double y1)
    : x(x1), y(y1)
{
}

GeometricObject::~GeometricObject()
{
}

double GeometricObject::getX() const
{
    return x;
}

double GeometricObject::getY() const
{
    return y;
}

void GeometricObject::setX(double x1)
{
    x = x1;
}

void GeometricObject::setY(double y1)
{
    y = y1;
}

double GeometricObject::getArea() const
{
    return 0.0;
}

double GeometricObject::getPerimeter() const
{
    return 0.0;
}

bool GeometricObject::contains(double x, double y)
{
    return false;
}

bool GeometricObject::contains(const GeometricObject& geo)
{
    return false;
}

bool GeometricObject::overlaps(const GeometricObject& geo)
{
    return false;
}