#ifndef DOCUMENT_H
#define DOCUMENT_H


#include "figure.h"
#include "point.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"
#include "comand.h"
#include <memory>
#include <vector>
#include <string>



class TDocument {
private:
	std::vector<std::shared_ptr<TFigure>> figures;
	std::vector<std::shared_ptr<TComand>> comands;
public:
	TDocument() {}
	void Save(std::ostream& os);
	void Load(std::istream& is);
	void Print(std::ostream& os);
	void Add(std::shared_ptr<TFigure> f, int idx);
	void Delete(int idx);
	void Undo();
	void AddCmd(TComand cmd);
};


#endif