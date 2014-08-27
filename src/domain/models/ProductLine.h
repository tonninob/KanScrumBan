/*
 * ProductLine.h
 *
 *  Created on: Aug 12, 2014
 *      Author: twiik
 */

#ifndef PRODUCTLINE_H_
#define PRODUCTLINE_H_

#include <vector>
#include "Task.h"

using namespace std;

class ProductLine {
	vector<Task*> _tasks;
public:
	virtual ~ProductLine() {
		_tasks.clear();
	}
	const vector<Task*>& getTasks() const {
		return _tasks;
	}
	void assignTask(Task* task);
};

#endif /* PRODUCTLINE_H_ */
