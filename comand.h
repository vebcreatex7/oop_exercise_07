#pragma once

#include "figure.h"
#include "document.h"
#include <memory>
#include <vector>


class TComand {
public:
	virtual void Exec() = 0;
	virtual void Undo() = 0;
protected:
	std::shared_ptr<TDocument> doc;
};

class InsertComand : public TComand {
public:
	InsertComand(std::shared_ptr<TDocument> doc) {
		this->doc = doc;
	}
	void Exec() override;
	void Undo() override;
};

class RemoveComand : public TComand {
public:
	RemoveComand(std::shared_ptr<TDocument> doc, int id) :
		idx(id), pos(-1), figure(nullptr) {
			this->doc = doc;
		};
		void Exec() override;
		void Undo() override;
private:
	int idx;
	int pos;
	std::shared_ptr<TFigure> figure;

};
