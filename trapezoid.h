#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"
#include <cmath>

class TTrapezoid : public TFigure{
private:
	TPoint a, b, c, d;
	int id;
public:
	double Square() const override;
	TPoint Center() const override;
	void Print(std::ostream&) const override;
	int getId() const override;
	TTrapezoid();
	TTrapezoid(const TPoint p1, const TPoint p2, const TPoint p3, const TPoint p4, int id);
	TTrapezoid(std::istream& is, int id);
};
#endif