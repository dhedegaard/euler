/*
 * euler165.cpp
 *
 *  Created on: 12/03/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <cmath>
#include <set>
#include <sys/types.h>

using namespace std;

#define INVAL_COORD -1000l

/**
 * Repressents a point in a 2-dimensional space.
 */
struct t_point {
	long double x, y;

	t_point() {
	}
	t_point(long double _x, long double _y) {
		x = _x;
		y = _y;
	}

	bool operator ==(const t_point &p) const {
		return x == p.x && y == p.y;
	}

	bool operator !=(const t_point &p) const {
		t_point _p(x, y);
		return !(p == _p);
	}

	bool operator <(const t_point &p) const {
		long double x_delta = x - p.x;
		if (x_delta < 0)
			return true;
		else if (x_delta > 0)
			return false;
		else {
			long double y_delta = y - p.y;
			if (y_delta < 0)
				return true;
			else
				return false;
		}
	}

	bool operator >(const t_point &p) const {
		long double x_delta = x - p.x;
		if (x_delta > 0)
			return true;
		else if (x_delta < 0)
			return false;
		else {
			long double y_delta = y - p.y;
			if (y_delta > 0)
				return true;
			else
				return false;
		}
	}

	struct t_point operator -(const struct t_point &p) const {
		return t_point(x - p.x, y - p.y);
	}

	struct t_point operator +(const struct t_point &p) const {
		return t_point(x + p.x, y + p.y);
	}

	// times the coordinates with d.
	struct t_point operator *(const long double d) const {
		return t_point(x * d, y * d);
	}

	// dot_product of 2 points/vectors.
	long double operator *(const t_point &p) const {
		return x * p.x + y * p.y;
	}
}typedef point;

/**
 * Operator overload to allow point objects onto an output stream.
 */
ostream &operator <<(ostream &stream, const point& p) {
	stream << '(' << (long double) p.x << ", " << (long double) p.y << ')';
	return stream;
}

/**
 * Repressents a line, with 2 points.
 */
struct t_line {
	point p1, p2;

	t_line() {
	}
	t_line(point _p1, point _p2) {
		p1 = _p1;
		p2 = _p2;
	}
}typedef line;

/**
 * Implements the blum blum shub pseudo-random number generator, it
 * returns the number requested in a vector.
 */
static vector<long> blum_blum_shub(int count);
/**
 * Returns NULL(0x0) if they don't true intersect, else they return the point they
 * intersect in.
 */
static point intersect(line l1, line l2);

int main(int argc, char **argv) {
	cout << "running blum blum shub.. " << flush;
	vector<long> shub = blum_blum_shub(5000);
	cout << "done" << endl;
	assert(shub.size() == 5000);
	vector<line> lines;
	cout << "generate lines.. " << flush;
	// push the numbers onto points in lines on a vector.
	for (vector<long>::iterator ite = shub.begin(); ite != shub.end();)
		lines.push_back(
				line(point(*ite++ % 500, *ite++ % 500),
						point(*ite++ % 500, *ite++ % 500)));
	cout << "done" << endl;
	set<point> points;
	int count = 0;
	static point inval = point(INVAL_COORD, INVAL_COORD);
	for (vector<line>::iterator ite = lines.begin(); ite != lines.end(); ite++)
		for (vector<line>::iterator ite2 = ite + 1; ite2 != lines.end(); ite2++) {
			point p = intersect(*ite, *ite2);
			if (p != inval) {
				// cout << p.x << "," << p.y << endl;
				count++;
				set<point>::iterator ite = points.find(p);
				if (ite != points.end()) {
					cout << p << " != " << *ite << endl;
				} else
					points.insert(p);
			}
		}
	cout << count << " - " << points.size() << " (" << count - points.size()
			<< ")" << endl;
	return 0;
}

static vector<long> blum_blum_shub(int count) {
	long s = 290797;
	vector<long> result;
	while (count-- > 0) {
		s = (s * s) % 50515093;
		result.push_back(s % 500);
	}
	return result;
}

// http://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
static point intersect(line l1, line l2) {
	// E = B-A = ( Bx-Ax, By-Ay )
	point E(l1.p2 - l1.p1);

	// F = D-C = ( Dx-Cx, Dy-Cy )
	point F(l2.p2 - l2.p1);

	// P = ( -Ey, Ex )
	point P(-1 * E.y, E.x);

	// Q = ( -Fy, Fx )
	point Q(-1 * F.y, F.x);

	// check for parallel lines, if F*P == 0 or E*Q == 0
	if (F * P == 0 || E * Q == 0)
		return point(INVAL_COORD, INVAL_COORD);

	// h = ( (A-C) * P ) / ( F * P )
	long double h = ((l1.p1 - l2.p1) * P) / (F * P);
	// g = ( (C-A) * Q ) / ( E * Q )
	long double g = ((l2.p1 - l1.p1) * Q) / (E * Q);

	// if h or g is less or equal 0, or equal or higher than 1,
	// they don't true intersect.
	if (h < 0 || h > 1)// || g < 0 || g > 1)
		return point(INVAL_COORD, INVAL_COORD);

	// The point of intersection is: C + F*h
	return l2.p1 + (F * h);
}
