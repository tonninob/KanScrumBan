/*
 * IStoryInteractor.h
 *
 *  Created on: Aug 26, 2014
 *      Author: twiik
 */

#ifndef ISTORYINTERACTOR_H_
#define ISTORYINTERACTOR_H_

#include "../models/Story.h"
class Task;

#include "../status/all.h"

class IStoryInteractor {
public:
	virtual Story* createStory(std::string name, int initialEffortEstimation) = 0;
	virtual void addTaskToStory(Story* story, Task* task) = 0;
	virtual void removeTaskFromStory(Story* story, Task* task) = 0;
	virtual void setStoryInitialEffortEstimation(Story* story, int amount) = 0;
	virtual void setStoryStatus(Story* story, ScrumWorkStatus::WorkStatus* status) = 0;
	virtual ~IStoryInteractor() {}
};

#endif /* ISTORYINTERACTOR_H_ */
