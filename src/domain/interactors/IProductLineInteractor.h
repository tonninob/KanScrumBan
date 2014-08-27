/*
 * IProductLineInteractor.h
 *
 *  Created on: Aug 26, 2014
 *      Author: twiik
 */

#ifndef IPRODUCTLINEINTERACTOR_H_
#define IPRODUCTLINEINTERACTOR_H_

#include <vector>
class ProductLine;
class Task;

class IProductLineInteractor {
protected:
	std::vector<ProductLine*> _lines;
public:
	virtual ProductLine* createLine() = 0;
	virtual int getLineCount() = 0;
	virtual void assignTaskToLine(Task* task, ProductLine& line) = 0;
	virtual ~IProductLineInteractor() {
		for(std::vector<ProductLine*>::const_iterator it = _lines.begin(); it != _lines.end(); it++)
		{
		    delete *it;
		}
		_lines.clear();
	}
};

#endif /* IPRODUCTLINEINTERACTOR_H_ */
