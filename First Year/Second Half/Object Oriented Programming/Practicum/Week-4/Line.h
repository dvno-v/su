#ifndef LINE_H

#define LINE_H

#include "Point.h"
#include <iostream>

class Line
{
public:
	Line();
	Line(double, double, double, double);
	Line(const Point&);
	Line(const Point&, const Point&);
	~Line();

	Point& get_p1();
	Point& get_p2();

	void set_p1(const Point&);
	void set_p2(const Point&);

	Line& operator=(const Line&);

	bool check_if_parallel(const Line&);
	bool check_if_line_contains_point(const Point&);

	Point get_intersection(const Line&);
	
	friend std::ostream& operator<<(std::ostream&, const Line&);


private:
	Point p1;
	Point p2;
};

#endif // !LINE_H
