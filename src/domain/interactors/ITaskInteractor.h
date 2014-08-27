/*
 * ITaskInteractor.h
 *
 *  Created on: Aug 26, 2014
 *      Author: twiik
 */

#ifndef ITASKINTERACTOR_H_
#define ITASKINTERACTOR_H_

class IResponsible;

#include "../models/Task.h"
#include "../status/all.h"

#include <vector>

class ITaskInteractor {
protected:
	std::vector<Task*> _tasks;
	//std::map<int, std::vector<IResponsible> _tasksResponsibles>;  //should we use pointers or not?
public:
	virtual int getTaskCount() = 0;
	virtual Task* createTask(std::string name, int initialEstimation, std::string featureId, std::string internalId) = 0;
	virtual void renameTask(Task& task, std::string name) = 0;
	virtual void deleteTask(Task& task) = 0;
	virtual void setTaskWorkDoneAmount(Task& task, int amount) = 0;
	virtual void setTaskStatus(Task* task, ScrumWorkStatus::WorkStatus* status) = 0;
	virtual void setTaskInitialEffortEstimation(Task& task, int amount) = 0;

	virtual void addResponsibleToTask(Task& task, IResponsible* responsible) = 0;
	virtual void removeResponsibleFromTask(Task& task, IResponsible* responsible) = 0;

	virtual ~ITaskInteractor() {
		for(std::vector<Task*>::const_iterator it = _tasks.begin(); it != _tasks.end(); it++)
		{
		    delete *it;
		}
		_tasks.clear();
	};
};

#endif /* ITASKINTERACTOR_H_ */
