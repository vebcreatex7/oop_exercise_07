#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"
#include "document.h"
#include "factory.h"
#include "editor.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <fstream>

int main() {

	std::cout << "new - to create new document\n"
			  << "insert- to insert figure to document \n"
			  << "delete idx- to delete figure on position idx from document\n"
			  << "undo - to cancel last comand\n"
			  << "save - to save document in file\n"
			  << "load - to load document from file\n"
			  << "print - to print all figure\n"
			  << "help - to show this page\n"
			  << "exit - to finish execution of program\n";

	int id;
	std::string cmd;
	std::string path;
	std::string figureType;
	TEditor e;
	while (std::cin >> cmd) {
		if (cmd == "new") {
			e.CreateDoc();
		} else if (cmd == "save") {
			std::cin >> path;
			std::ofstream os(path);
			e.SaveDoc(os);	
		} else if (cmd == "load") {
			std::cin >> path;
			std::ifstream is(path);
			e.LoadDoc(is);
		} else if (cmd == "insert") {
			e.Add();
		} else if (cmd == "delete") {
			std::cin >> id;
			try {
				e.Remove(id);
			} catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		} else if (cmd == "undo"){
			try {
				e.Undo();
			} catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		} else if (cmd == "print") {
			e.Print();
		} else if (cmd == "help") {
				std::cout << "new - to create new document\n"
			  << "insert- to insert figure to document \n"
			  << "delete idx- to delete figure on position idx from document\n"
			  << "undo - to cancel last comand\n"
			  << "save - to save document in file\n"
			  << "load - to load document from file\n"
			  << "print - to print all figure\n"
			  << "help - to show this page\n"
			  << "exit - to finish execution of program\n";

		} else if (cmd == "exit") {
			break;
		} else {
			std::cout << "Wrong comand" << std::endl;
			continue;
		}



	}

}