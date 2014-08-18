/*
 * TaskInteractor.h
 *
 *  Created on: Aug 5, 2014
 *      Author: twiik
 */

#ifndef TASKINTERACTOR_H_
#define TASKINTERACTOR_H_

#include <vector>
#include <string>
#include <algorithm>
#include <map>
//#include "../operators/IResponsible.h"
#include "../models/Task.h"

class IResponsible;

class TaskInteractor {
	std::vector<Task*> _tasks;
	//std::map<int, std::vector<IResponsible> _tasksResponsibles>;  //should we use pointers or not?

public:
	int getTaskCount() {return _tasks.size();};
	Task* createTask(std::string name, int initialEstimation, std::string featureId, std::string internalId);
	void renameTask(Task& task, std::string name);
	void deleteTask(Task& task);
	void setTaskWorkDoneAmount(Task& task, int amount);

	void addResponsibleToTask(Task& task, IResponsible* responsible);
	void removeResponsibleFromTask(Task& task, IResponsible* responsible);

	virtual ~TaskInteractor() {
		for(std::vector<Task*>::const_iterator it = _tasks.begin(); it != _tasks.end(); it++)
		{
		    delete *it;
		}
		_tasks.clear();
	};
};

#endif /* TASKINTERACTOR_H_ */
