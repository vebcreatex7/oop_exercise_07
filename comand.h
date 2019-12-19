#include "figure.h"
#include "point.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"
#include "document.h"
#include <memory>
#include <vector>
#include <string>


struct TComand {
	std::shared_ptr<TFigure> f;
	std::string comand;
	int index;
	TComand(std::shared_ptr<TFigure> fig, std::string cmd, int idx) {
		comand = cmd;
		index = idx;
		f = std::move(fig);
	}

};