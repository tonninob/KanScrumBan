/*
 * StoryInteractor.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: twiik
 */

#include "StoryInteractor.h"

StoryInteractor::~StoryInteractor() {
}

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
