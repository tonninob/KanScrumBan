/*
 * User.cpp
 *
 *  Created on: Aug 5, 2014
 *      Author: twiik
 */
//bool User::User() {
//
//}
#include "User.h"

Task* User::createTask(std::string name, int initialEstimation,
											 std::string featureId, std::string internalId, Story* story) {
	Task* task = _taskActor.createTask(name, initialEstimation, featureId, internalId);
	if (story) {
		addTaskToStory(story, task);
	}
	return task;
}

void User::renameTask(Task& task, std::string name) {
	_taskActor.renameTask(task, name);
}

void User::deleteTask(Task& task) {
	_taskActor.deleteTask(task);
}

void User::setTaskWorkDoneAmount(Task& task, int amount) {
	_taskActor.setTaskWorkDoneAmount(task, amount);
}

void User::addResponsibleToTask(Task& task, IResponsible* responsible) {
	_taskActor.addResponsibleToTask(task, responsible);
}

void User::removeResponsibleFromTask(Task& task, IResponsible* responsible) {
	_taskActor.removeResponsibleFromTask(task, responsible);
}

bool User::operator== (IResponsible& compareto) {
	return compareto.tellName().compare(compareto.tellName()) == 0;
}

void User::assignTaskToProductLine(Task* task, ProductLine& line,
		IProductLineInteractor& actor) {
	actor.assignTaskToLine(task, line);
}

Story* User::createStory(std::string name, int initialEffortEstimation) {
	return _storyActor.createStory(name, initialEffortEstimation);
}

void User::addTaskToStory(Story* story, Task* task) {
	_storyActor.addTaskToStory(story, task);
}

void User::removeTaskFromStory(Story* story, Task* task) {
	_storyActor.removeTaskFromStory(story, task);
}

void User::completeStory(Story* story) {
	_storyActor.setStoryStatus(story, new ScrumWorkStatus::Completed);
}

void User::setTaskStatus(Task* task, ScrumWorkStatus::WorkStatus* status) {
	_taskActor.setTaskStatus(task, status);
}

void User::setTaskInitialEffortEstimation(Task& task, int amount) {
	_taskActor.setTaskInitialEffortEstimation(task, amount);
}

void User::setStoryInitialEffortEstimation(Story* story, int amount) {
	_storyActor.setStoryInitialEffortEstimation(story, amount);
}
