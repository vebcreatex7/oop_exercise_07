#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <cassert>
#include <stdexcept> 
#include "point.h"
#include <cmath>
#include <exception>
#include <string>


class TFigure {
public:
	virtual std::string Name() const = 0;
	virtual void Print(std::ostream&) const = 0;
	virtual TPoint Center() const = 0;
	virtual double Square() const = 0;
};
#endif