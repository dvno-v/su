#ifndef LINE_CPP

#define LINE_CPP

#include "Line.h"
#include <cmath>
const double EPS = 1e-6;

Line::Line() : p1(Point()), p2(Point()) {}


Line::Line(double x1, double y1, double x2, double y2) : p1(Point{x1,y1}), p2(Point{x2,y2}){}

Line::Line(const Point& _p2) : p1(Point()), p2(Point{_p2.x, _p2.y}) {}

Line::Line(const Point& _p1, const Point& _p2) : p1(Point{ _p1.x, _p1.y }), p2(Point{ _p2.x, _p2.y }) {}

Line::~Line()
{
    std::cout << "DESTRUCTION\n";
}


Point& Line::get_p1(){
	return p1;
}

Point& Line::get_p2(){
	return p2;
}

void Line::set_p1(const Point& _p1){
	p1 = _p1;
}
void Line::set_p2(const Point& _p2){
	p2 = _p2;
}

Line& Line::operator=(const Line& _other){
	p1 = _other.p1;
	p2 = _other.p2;
	return *this;
}

bool Line::check_if_parallel(const Line& _other) {
	 double slope1 = (p2.y - p1.y) / (p2.x - p1.x),
			slope2 = (_other.p2.y - _other.p1.y) / (_other.p2.x - _other.p1.x);
	 return fabs(slope1 - slope2) < EPS;
}
bool Line::check_if_line_contains_point(const Point& _p){
	double slope = (p2.y - p1.y) / (p2.x - p1.x),
			free_variable = p2.y - slope* p2.x;
	return fabs(_p.y - slope * _p.x - free_variable) < EPS;
}

Point Line::get_intersection(const Line& _other){
    // Line AB represented as a1x + b1y = c1 
    double a1 = p2.y - p1.y;
    double b1 = p1.x - p2.x;
    double c1 = a1 * (p1.x) + b1 * (p1.y);

    // Line CD represented as a2x + b2y = c2 
    double a2 = _other.p2.y - _other.p1.y;
    double b2 = _other.p1.x - _other.p2.x;
    double c2 = a2 * (_other.p1.x) + b2 * (_other.p1.y);

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0)
    {
        return Point{ FLT_MAX, FLT_MAX };
    }
    else
    {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        return Point{x, y};
    }
}

#endif // !LINE_CPP

std::ostream& operator<<(std::ostream& out, const Line& l)
{
	out << "(" << l.p1.x << ", " << l.p1.y << ") <-> " << "(" << l.p2.x << ", " << l.p2.y << ")\n";
	return out;
}
