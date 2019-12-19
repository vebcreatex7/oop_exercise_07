#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"
#include "document.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <fstream>

int main() {
	std::string cmd;
	std::cout << "new - to create new document\n"
			  << "insert idx- to insert figure to document to position idx\n"
			  << "delete idx- to delete figure on position idx from document\n"
			  << "undo - to cancel last comand\n"
			  << "save - to save document in file\n"
			  << "load - to load document from file\n"
			  << "print - to print all figure\n"
			  << "help - to show this page\n"
			  << "exit - to finish execution of program\n";
	while (true) {
		std::cin >> cmd;
		if (cmd == "new") {
			TDocument doc;
			while (true) {
				std::cin >> cmd;
				if (cmd == "insert") {
				int i;
				std::cin >> i;
				int chose;
				std::cout << "1 - rectangle\n2 - rhombus\n3 - trapezoid\n";
				std::cin >> chose;
				std::shared_ptr<TFigure> f;
				if (chose == 1) {
					try {
						f = std::make_shared<TRectangle>(TRectangle(std::cin));
					} catch (std::exception& err) {
						std::cout << err.what();
						continue;
					}

				} else if (chose == 2) {
					try {
						f = std::make_shared<TRhombus>(TRhombus(std::cin));
					} catch (std::exception& err) {
						std::cout << err.what();
						continue;
					}
				} else if (chose == 3) {
					try {
						f = std::make_shared<TTrapezoid>(TTrapezoid(std::cin));
					} catch(std::exception& err) {
						std::cout << err.what();
						continue;
					}
				} else {
					std::cout << "error, try again\n";
					continue;
				}	
					doc.Add(f, i);
				} else if (cmd == "delete") {
					int i;
					std::cin >> i;
					doc.Delete(i);
				} else if (cmd == "save") {
					std::string path;
					std::cin >> path;
					std::ofstream os(path);
					doc.Save(os);
				} else if (cmd == "load") {
					std::string path;
					std::cin >> path;
					std::ifstream is(path);
					doc.Load(is);
				} else if (cmd == "print") {
					doc.Print(std::cout);
				} else if (cmd == "undo") {
					try {
						doc.Undo();
					} catch (std::exception& err) {
						std::cout << err.what();
					}
					
				} else if (cmd == "help") {
					std::cout << "new - to create new document\n"
			 				  << "insert idx- to insert figure to document to position idx\n"
			  				  << "delete idx- to delete figure on position idx from document\n"
			  				  << "undo - to cancel last comand\n"
							  << "save - to save document in file\n"
							  << "load - to load document from file\n"
							  << "print - to print all figure\n"
							  << "help - to show this page\n"
							  << "exit - to finish execution of program\n";
							  continue;
				} else if (cmd == "exit") {
					return 0;
				} else {
					std::cout << "wrong comand, enter 'help' to show man\n";
				}
		
			}
		} else if (cmd == "exit") {
			break;
		} else {
			std::cout << "firstly create new document\n";
			continue;
		}

	}
}