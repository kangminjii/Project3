#include "Rectangle2D.h"
#include "MyPoint.h"
#include <cmath>

double Rectangle2D::getWidth() const
{
	return width;
}
double Rectangle2D::getHeight() const
{
	return height;
}

void Rectangle2D::setWidth(double w)
{
	width = w;
}
void Rectangle2D::setHeight(double h)
{
	height = h;
}


Rectangle2D::Rectangle2D(double x1, double y1, double w, double h)
	: GeometricObject(x1, y1), width(w), height(h)
{
}
Rectangle2D::Rectangle2D(const GeometricObject& geo, double w, double h)
	: GeometricObject(geo)
{
	width = w;
	height = h;
}
Rectangle2D::~Rectangle2D()
{
}

double Rectangle2D::getArea() const
{
	return	width * height;
}
double Rectangle2D::getPerimeter() const
{
	return (2 * width) + (2 * height);
}

bool Rectangle2D::contains(double x1, double y1)
{
	width /= 2;
	height /= 2;
	if (getX() - width <= x1 && x1 <= getX() + width)
	{
		if (getY() - height <= y1 && y1 <= getY() + height)
			return true;
	}
	else	return false;
}
bool Rectangle2D::contains(const Rectangle2D& r)
{
	width /= 2;
	height /= 2;
	double widthR = r.width / 2;
	double heightR = r.height / 2;

	if (abs(r.getX() - getX()) <= abs(width - widthR) && abs(r.getY() - getY()) <= abs(height - heightR))
	{
		return true;
	}
	else	return false;
}
bool Rectangle2D::overlaps(const Rectangle2D& r)
{
	width /= 2;
	height /= 2;
	double widthR = r.width / 2;
	double heightR = r.height / 2;

	if (contains(r) == false)
	{
		if (abs(r.getX() - getX()) >= width + widthR || abs(r.getY() - getY()) >= height + heightR)
		{
			return false;
		}
	}
	else	return true;
}

bool contains(const Rectangle2D& r, const MyPoint& p)
{
	if (r.getX() - r.width / 2 <= p.getX() && p.getX() <= r.getX() + r.width / 2)
	{
		if (r.getY() - r.height <= p.getY() && p.getY() <= r.getY() + r.height)
			return true;
	}
	else	return false;
}
