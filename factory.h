#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "figure.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"

class Factory {
public:
	std::shared_ptr<TFigure> FigureCreate(int id) {
		std::string type;
		std::cin >> type;
		if (type == "rectangle") {
			 std::shared_ptr<TFigure> f(new TRectangle(std::cin, id));
			return f;
		} else if (type == "rhombus") {
			std::shared_ptr<TFigure> f(new TRhombus(std::cin, id));
			return f;
		} else if (type == "trapezoid") {
			std::shared_ptr<TFigure> f(new TTrapezoid(std::cin, id));
			return f;
		} else {
			throw std::logic_error("Wrong figure\n");
		}
	}

};