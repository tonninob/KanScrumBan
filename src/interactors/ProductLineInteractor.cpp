/*
 * ProductLineInteractor.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: twiik
 */

#include "ProductLineInteractor.h"

ProductLineInteractor::~ProductLineInteractor() {
	for(std::vector<ProductLine*>::const_iterator it = _lines.begin(); it != _lines.end(); it++)
	{
	    delete *it;
	}
	_lines.clear();
}

ProductLine* ProductLineInteractor::createLine() {
	ProductLine* line = new ProductLine();
	_lines.push_back(line);
	return line;
}

int ProductLineInteractor::getLineCount() {
	return _lines.size();
}

void ProductLineInteractor::assignTaskToLine(Task* task, ProductLine& line) {
	line.assignTask(task);
}
