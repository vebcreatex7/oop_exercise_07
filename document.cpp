#include "document.h"

void TDocument::New() {
	figures.clear();
	FigureId = 0;
}

void TDocument::Save(std::ostream& os) {
	for (auto &tmp : figures) {
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
	is >> num;
	while (num --) {
		this->Add();
	}
}

void TDocument::popBack() {
	if (!figures.size()) {
		throw std::logic_error("Doc is empty\n");
	}
	figures.pop_back();
}

std::shared_ptr<TFigure> TDocument::Get(int idx) {
	for (const auto& figure : figures) {
		if (idx == figure->getId()) {
			return figure;
		}
	}
	throw std::invalid_argument("No figure with such Id\n");
}

void TDocument::Add() {
	std::shared_ptr<TFigure> figure = this->factory.FigureCreate(FigureId);
	if (figure) {
		figures.push_back(figure);
		FigureId++;
	}
}

int TDocument::Pos(int idx) {
	for (int i = 0; i < figures.size(); i ++) {
		if (idx == figures[i]->getId()) {
			return i;
		}
	}
	throw std::invalid_argument("No figure with such Id\n");

}

