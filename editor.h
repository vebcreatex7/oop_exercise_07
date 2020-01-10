#pragma once

#include <stack>
#include "comand.h"
#include "document.h"
#include "figure.h"


class TEditor {
public:
	TEditor() : doc(nullptr) {};
	void CreateDoc();
	void Add();
	void Add(int idx);
	void Remove(int idx);
	void SaveDoc(std::ostream& os);
	void LoadDoc(std::istream& is);
	void Undo();
	void Print();
private:
	std::shared_ptr<TDocument> doc;
	std::stack<std::shared_ptr<TComand>> cmds;
};