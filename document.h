#pragma once

#include "figure.h"
#include "factory.h"
#include <memory>
#include <vector>
#include <string>



class TDocument {
	friend class TComand;
public:
	void New();
	void Save(std::ostream& os);
	void Load(std::istream& is);
	void Print();
	void Add();
	void Add(std::shared_ptr<TFigure> f, int idx);
	void Delete(int idx);
	std::shared_ptr<TFigure> Get(int idx);
	void popBack();

private:
	std::vector<std::shared_ptr<TFigure>> figures;
	Factory factory;
	void Serialize(const std::string& file);
	void Deserialize(const std::string& file);
};

