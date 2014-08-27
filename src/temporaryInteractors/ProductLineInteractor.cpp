/*
 * ProductLineInteractor.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: twiik
 */

#include "ProductLineInteractor.h"

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
