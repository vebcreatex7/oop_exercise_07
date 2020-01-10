#pragma once

#include "figure.h"
#include "factory.h"
#include <memory>
#include <vector>
#include <string>



class TDocument {
	friend class TComand;
public:
	TDocument() : FigureId(0) {};
	void New();
	void Save(std::ostream& os);
	void Load(std::istream& is);
	void Print();
	void Add();
	void Add(std::shared_ptr<TFigure> f, int idx);
	void Delete(int idx);
	std::shared_ptr<TFigure> Get(int idx);
	void popBack();
	int Pos(int idx);
private:
	int FigureId;
	std::vector<std::shared_ptr<TFigure>> figures;
	Factory factory;
	void Serialize(const std::string& file);
	void Deserialize(const std::string& file);
};

