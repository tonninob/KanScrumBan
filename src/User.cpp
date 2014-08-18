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
	Task* task = _actor.createTask(name, initialEstimation, featureId, internalId);
	if (story) {
		addTaskToStory(story, task);
	}
	return task;
}

void User::renameTask(Task& task, std::string name) {
	_actor.renameTask(task, name);
}

void User::deleteTask(Task& task) {
	_actor.deleteTask(task);
}

void User::setTaskWorkDoneAmount(Task& task, int amount) {
	_actor.setTaskWorkDoneAmount(task, amount);
}

void User::addResponsibleToTask(Task& task, IResponsible* responsible) {
	_actor.addResponsibleToTask(task, responsible);
}

void User::removeResponsibleFromTask(Task& task, IResponsible* responsible) {
	_actor.removeResponsibleFromTask(task, responsible);
}

bool User::operator== (IResponsible& compareto) {
	return compareto.tellName().compare(compareto.tellName()) == 0;
}

void User::assignTaskToProductLine(Task* task, ProductLine& line,
		ProductLineInteractor& actor) {
	actor.assignTaskToLine(task, line);
}

Story* User::createStory(std::string name, int initialEffortEstimation) {
	return _storyActor.createStory(name, initialEffortEstimation);
}

void User::addTaskToStory(Story* story, Task* task) {
	_storyActor.addTaskToStory(story, task);
}

void User::removeTaskFromStory(Story* story, Task* task) {
}
