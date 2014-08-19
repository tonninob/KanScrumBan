/*
 * Story.h
 *
 *  Created on: Aug 14, 2014
 *      Author: twiik
 */

#ifndef STORY_H_
#define STORY_H_

#include <string>
#include "Task.h"
#include "../status/all.h"

using namespace std;

class Story {
	string _name;
	int _initialEffortEstimation;
	vector<Task*> _tasks;
	ScrumWorkStatus::WorkStatus* _status;

	string includeEstimationToDescription();
	string includeTaskCountToDescription();

	string determineStatusBasedOnTaskStatuses();
public:
	Story(string name, int initialEffortEstimation);
	virtual ~Story();

	string describe();
	void addTask(Task *task);
	void removeTask(Task *task);
	string tellStatus();

	void setStatus(ScrumWorkStatus::WorkStatus* status) {
		_status = status;
	}

	void setInitialEffortEstimation(int initialEffortEstimation) {
		_initialEffortEstimation = initialEffortEstimation;
	}
};

#endif /* STORY_H_ */
