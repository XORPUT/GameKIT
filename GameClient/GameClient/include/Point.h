#ifndef POINT_H
#define POINT_H

struct Point {
	Point()
	{
	}
	Point(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
	float x;
	float y;
};

#endif