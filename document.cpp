#include "document.h"

void TDocument::Save(std::ostream& os) {
	for (auto &tmp : figures) {
		os << tmp->Name();
		tmp->Print(os);
	}
}

void TDocument::Add(std::shared_ptr<TFigure> f, int idx) {
	std::shared_ptr<TComand> tmp(new TComand(f, "insert", idx));
	figures.insert(figures.begin() + idx, std::move(f));
	comands.push_back(std::move(tmp));
}

void TDocument::Delete(int idx) {
	std::shared_ptr<TComand> tmp(new TComand(figures[idx], "delete", idx));
	figures.erase(figures.begin() + idx);
	comands.push_back(std::move(tmp));
	
}

void TDocument::Print(std::ostream& os) {
	for (auto &tmp : figures) {
		std::cout << tmp->Name();
		tmp->Print(os);
		std::cout << "Square: " << tmp->Square() << std::endl;
		std::cout << "Center: " << tmp->Center() << std::endl;
	}
}

void TDocument::Load(std::istream& is) {
	std::string name;
	while(is >> name)
	if (name == "rectangle") {
		std::shared_ptr<TFigure> f(new TRectangle(is));
		figures.push_back(std::move(f));
	} else if (name == "rhombus") {
		std::shared_ptr<TFigure> f(new TRhombus(is));
		figures.push_back(std::move(f));
	} else if (name == "trapezoid") {
		std::shared_ptr<TFigure> f(new TTrapezoid(is));
		figures.push_back(std::move(f));
	}
}

void TDocument::Undo() {
	if (comands.size() == 0) {
		throw std::logic_error("list of comands is empty\n");
	}
	if (comands.back()->comand == "delete") {
		figures.insert(figures.begin() + comands.back()->index, std::move(comands.back()->f));	
		comands.pop_back();

	} else if (comands.back()->comand == "insert") {
		figures.erase(figures.begin() + comands.back()->index);
		comands.pop_back();
	}
}

