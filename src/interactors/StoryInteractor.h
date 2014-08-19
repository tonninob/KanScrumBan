/*
 * StoryInteractor.h
 *
 *  Created on: Aug 14, 2014
 *      Author: twiik
 */

#ifndef STORYINTERACTOR_H_
#define STORYINTERACTOR_H_

#include "../models/Story.h"

class Task;

using namespace std;

class StoryInteractor {
public:
	virtual ~StoryInteractor();
	Story* createStory(string name, int initialEffortEstimation);
	void addTaskToStory(Story* story, Task* task);
	void removeTaskFromStory(Story* story, Task* task);
	void setStoryInitialEffortEstimation(Story* story, int amount);
	void setStoryStatus(Story* story, ScrumWorkStatus::WorkStatus* status);
};

#endif /* STORYINTERACTOR_H_ */
