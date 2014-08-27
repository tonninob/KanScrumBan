/*
 * StoryInteractor.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: twiik
 */

#include "StoryInteractor.h"

Story* StoryInteractor::createStory(std::string name,
		int initialEffortEstimation) {
	return new Story(name, initialEffortEstimation);
}

void StoryInteractor::addTaskToStory(Story* story, Task* task) {
	story->addTask(task);
}

void StoryInteractor::removeTaskFromStory(Story* story, Task* task) {
	story->removeTask(task);
}

void StoryInteractor::setStoryInitialEffortEstimation(Story* story, int amount) {
	story->setInitialEffortEstimation(amount);
}

void StoryInteractor::setStoryStatus(Story* story,
		ScrumWorkStatus::WorkStatus* status) {
	story->setStatus(status);
}
