/*
 * TaskInteractor.cpp
 *
 *  Created on: Aug 5, 2014
 *      Author: twiik
 */

#include "TaskInteractor.h"

Task* TaskInteractor::createTask(std::string name, int initialEstimation,
		std::string featureId, std::string internalId) {
	Task* task = new Task(name, initialEstimation, featureId, internalId);
	_tasks.push_back(task);
	return task;
};

void TaskInteractor::renameTask(Task& task, std::string name) {
	task.setName(name);
}

void TaskInteractor::deleteTask(Task& task) {
	for(std::vector<Task*>::iterator it = _tasks.begin(); it != _tasks.end(); it++)
		 if (*(*it) == task) {
			 delete (*it);
			 it = _tasks.erase(it);
			 break;
		 }
}
void TaskInteractor::setTaskWorkDoneAmount(Task& task, int amount) {
	task.setWorkDoneAmount(amount);
}

void TaskInteractor::addResponsibleToTask(Task& task, IResponsible* responsible) {
	task.addResponsible(responsible);
}

void TaskInteractor::removeResponsibleFromTask(Task& task, IResponsible* responsible) {
	task.removeResponsible(responsible);
}

void TaskInteractor::setTaskStatus(Task* task,
		ScrumWorkStatus::WorkStatus* status) {
	task->setStatus(status);
}

void TaskInteractor::setTaskInitialEffortEstimation(Task& task, int amount) {
	task.setInitialEffortEstimation(amount);
}
