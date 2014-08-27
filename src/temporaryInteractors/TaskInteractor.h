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
#include "../domain/interactors/ITaskInteractor.h"

class IResponsible;

class TaskInteractor : public ITaskInteractor {

public:
	int getTaskCount() {return _tasks.size();};
	Task* createTask(std::string name, int initialEstimation, std::string featureId, std::string internalId);
	void renameTask(Task& task, std::string name);
	void deleteTask(Task& task);
	void setTaskWorkDoneAmount(Task& task, int amount);
	void setTaskStatus(Task* task, ScrumWorkStatus::WorkStatus* status);
	void setTaskInitialEffortEstimation(Task& task, int amount);

	void addResponsibleToTask(Task& task, IResponsible* responsible);
	void removeResponsibleFromTask(Task& task, IResponsible* responsible);

};

#endif /* TASKINTERACTOR_H_ */
