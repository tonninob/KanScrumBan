/*
 * ProductLineInteractor.h
 *
 *  Created on: Aug 12, 2014
 *      Author: twiik
 */

#ifndef PRODUCTLINEINTERACTOR_H_
#define PRODUCTLINEINTERACTOR_H_

#include <vector>
#include "../domain/models/ProductLine.h"
#include "../domain/interactors/IProductLineInteractor.h"

class ProductLineInteractor : public IProductLineInteractor {
public:
	ProductLine* createLine();
	int getLineCount();
	void assignTaskToLine(Task* task, ProductLine& line);

};

#endif /* PRODUCTLINEINTERACTOR_H_ */
