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

using namespace std;

#define INVAL_COORD -1000
#define PRECISION 0.00000000000000001L

/**
 * Repressents a point in a 2-dimensional space.
 */
struct t_point {
	long double x, y;

	t_point() {
		x = INVAL_COORD;
		y = INVAL_COORD;
	}

	t_point(long double _x, long double _y) {
		x = _x;
		y = _y;
	}

	bool operator ==(const t_point &p) const {
		return x < p.x ? p.x - x < PRECISION
				: x - p.x < PRECISION && y < p.y ? p.y - y < PRECISION : y
						- p.y < PRECISION;
	}

	bool operator !=(const t_point &p) const {
		t_point _p(x, y);
		return !(p == _p);
	}

	bool operator <(const t_point &p) const {
		long double x_delta = x - p.x;
		if (x_delta < -PRECISION)
			return true;
		else if (x_delta > PRECISION)
			return false;
		else {
			long double y_delta = y - p.y;
			if (y_delta < -PRECISION)
				return true;
			else
				return false;
		}
	}

	bool operator >(const t_point &p) const {
		long double x_delta = x - p.x;
		if (x_delta > PRECISION)
			return true;
		else if (x_delta < -PRECISION)
			return false;
		else {
			long double y_delta = y - p.y;
			if (y_delta > PRECISION)
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

	struct t_point operator *(const long double d) const {
		return t_point(x * d, y * d);
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
struct _line {
	point p1, p2;
}typedef line;

/**
 * Implements the blum blum shub pseudo-random number generator, it
 * returns the number requested in a vector.
 */
static vector<int> blum_blum_shub(int count);
/**
 * Returns NULL(0x0) if they don't true intersect, else they return the point they
 * intersect in.
 */
static point intersect(line l1, line l2);
/**
 * Used for generating the dot-product of 2 points (or vectors in 2d).
 */
static long double dot_product(const point p1, const point p2);

int main(int argc, char **argv) {
	cout << "running blum blum shub.. " << flush;
	vector<int> shub = blum_blum_shub(5000);
	cout << "done" << endl;
	assert(shub.size() == 5000);
	vector<line> lines;
	cout << "generate lines.. " << flush;
	for (vector<int>::iterator ite = shub.begin(); ite != shub.end();) {
		line l;
		l.p1.x = *ite++ % 500;
		l.p1.y = *ite++ % 500;
		l.p2.x = *ite++ % 500;
		l.p2.y = *ite++ % 500;
		lines.push_back(l);
	}
	cout << "done" << endl;
	set<point> points;
	int count = 0;
	for (vector<line>::iterator ite = lines.begin(); ite != lines.end(); ite++)
		for (vector<line>::iterator ite2 = ite + 1; ite2 != lines.end(); ite2++) {
			point p = intersect(*ite, *ite2);
			if (p.x != INVAL_COORD && p.y != INVAL_COORD) {
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

static vector<int> blum_blum_shub(int count) {
	long long s = 290797;
	vector<int> result;
	while (count-- > 0) {
		s = (s * s) % 50515093;
		result.push_back((int) s);
	}
	return result;
}

static long double dot_product(const point p1, const point p2) {
	// A*B = Ax*Bx + Ay*By
	return p1.x * p2.x + p1.y * p2.y;
}

// http://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
static point intersect(line l1, line l2) {
	// E = B-A = ( Bx-Ax, By-Ay )
	point e(l1.p2 - l1.p1);

	// F = D-C = ( Dx-Cx, Dy-Cy )
	point f(l2.p2 - l2.p1);

	// P = ( -Ey, Ex )
	point p(-1 * e.y, e.x);

	// check for parallel lines, if F*P == 0
	if (f.x * p.x == 0 && f.y * p.y == 0)
		return point(INVAL_COORD, INVAL_COORD);

	// h = ( (A-C) * P ) / ( F * P )
	// long double h = dot_product(minus_point(l1.p1, l2.p1), p) / dot_product(f, p);
	long double h = dot_product(l1.p1 - l2.p1, p) / dot_product(f, p);

	// if h is less or equal 0, or equal or higher than 1, they don't true intersect.
	if (h <= 0 || h > 1)
		return point(INVAL_COORD, INVAL_COORD);
	// The point of intersection is: C + F*h
	point result = l2.p1 + f * h;
	return result;
}
