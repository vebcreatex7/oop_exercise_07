#include "comand.h"


void InsertComand::Exec() {
	doc->Add();
}

void InsertComand::Undo() {
	doc->popBack();
}

void RemoveComand::Exec() {
	try {
		figure = doc->Get(idx);
		pos = doc->Pos(idx);
	} catch (std::exception& e) {
		std::cout << e.what()  << std::endl;
		return;
	} 
	doc->Delete(idx);
}

void RemoveComand::Undo() {
	doc->Add(figure, pos);
}