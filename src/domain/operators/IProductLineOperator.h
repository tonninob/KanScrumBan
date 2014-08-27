/*
 * ProductLineOperator.h
 *
 *  Created on: Aug 12, 2014
 *      Author: twiik
 */

#ifndef PRODUCTLINEOPERATOR_H_
#define PRODUCTLINEOPERATOR_H_

class Task;
class ProductLine;
class IProductLineInteractor;

class IProductLineOperator {
public:
	virtual ~IProductLineOperator() {};
	virtual void assignTaskToProductLine(Task* task, ProductLine& line, IProductLineInteractor& actor) = 0;
};

#endif /* PRODUCTLINEOPERATOR_H_ */
