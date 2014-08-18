/*
 * ProductLineInteractor.h
 *
 *  Created on: Aug 12, 2014
 *      Author: twiik
 */

#ifndef PRODUCTLINEINTERACTOR_H_
#define PRODUCTLINEINTERACTOR_H_

#include <vector>
#include "../models/ProductLine.h"

class ProductLineInteractor {
public:
	std::vector<ProductLine*> _lines;
public:
	ProductLine* createLine();
	int getLineCount();
	void assignTaskToLine(Task* task, ProductLine& line);

	virtual ~ProductLineInteractor();
};

#endif /* PRODUCTLINEINTERACTOR_H_ */
