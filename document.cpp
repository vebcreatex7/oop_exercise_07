#include "document.h"
#include <string>

void TDocument::New() {
	figures.clear();
}

void TDocument::Save(std::ostream& os) {
	int i = 0;
	for (auto &tmp : figures) {
		os << i << " ";
		i++;
		tmp->Print(os);
	}
}

void TDocument::Add(std::shared_ptr<TFigure> f, int idx) {
	figures.insert(figures.begin() + idx, std::move(f));
}

void TDocument::Delete(int idx) {
	figures.erase(figures.begin() + idx);
}

void TDocument::Print() {
	for (auto &tmp : figures) {

		tmp->Print(std::cout);
		std::cout << "Square: " << tmp->Square() << std::endl;
		std::cout << "Center: " << tmp->Center() << std::endl;
	}
}

void TDocument::Load(std::istream& is) {
	this->New();
	int num;
			std::string n;
	while (is >> num) {

		std::shared_ptr<TFigure> figure = this->factory.FigureCreate(is);
		if (figure) {
			figures.push_back(figure);
		}
	}
}

void TDocument::popBack() {
	if (!figures.size()) {
		throw std::logic_error("Doc is empty\n");
	}
	figures.pop_back();
}

std::shared_ptr<TFigure> TDocument::Get(int idx) {
	int i = 0;
	for (const auto& figure : figures) {
		if (i == idx)  {
			return figure;
		}
		i++;
	}
	throw std::invalid_argument("No figure with such Id\n");
}

void TDocument::Add() {
	std::shared_ptr<TFigure> figure = this->factory.FigureCreate(std::cin);
	if (figure) {
		figures.push_back(figure);

	}
}

