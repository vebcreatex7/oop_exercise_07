#include "editor.h"
void TEditor::CreateDoc() {
	doc = std::make_shared<TDocument>();
	while(!cmds.empty()) {
		cmds.pop();
	}
}

void TEditor::Add() {
	std::shared_ptr<TComand> c = std::shared_ptr<TComand>(new InsertComand(doc));
	c->Exec();
	cmds.push(c);
}

void TEditor::Remove(int idx) {
	try {
		std::shared_ptr<TComand> c = std::shared_ptr<TComand>(new RemoveComand(doc, idx));
		c->Exec();
		cmds.push(c);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void TEditor::SaveDoc(std::ostream& os) {
	doc->Save(os);
}

void TEditor::LoadDoc(std::istream& is) {
	CreateDoc();
	doc->Load(is);
}

void TEditor::Undo() {
	if (cmds.empty()) {
		throw std::logic_error("Stack comands is empty\n");
	}
	std::shared_ptr<TComand> c = cmds.top();
	c->Undo();
	cmds.pop();
}

void TEditor::Print() {
	doc->Print();
}
