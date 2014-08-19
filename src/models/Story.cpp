/*
 * Story.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: twiik
 */

#include "Story.h"
#include "../utils/string.cpp"
#include "../exceptions/NoSuchTaskInStory.h"

Story::Story(string name, int initialEffortEstimation) :
	_name(name), _initialEffortEstimation(initialEffortEstimation) {
	_status = NULL;
}

Story::~Story() {
	_tasks.clear();
	delete _status;
}

string Story::describe() {
	return _name + includeEstimationToDescription()
							 + includeTaskCountToDescription();
}

string Story::includeEstimationToDescription() {
	return " (" + patch::to_string(_initialEffortEstimation) + ")";
}

string Story::includeTaskCountToDescription() {
	return " | Tasks: " + patch::to_string(_tasks.size());
}

void Story::addTask(Task* task) {
	_tasks.push_back(task);
}

void Story::removeTask(Task* task) {
	for(std::vector<Task*>::iterator it = _tasks.begin(); it != _tasks.end(); it++)
		 if ((*it) == task) {
			 it = _tasks.erase(it);
			 return;
		 }
	throw ScrumExceptions::NoSuchTaskInStory();
}

string Story::tellStatus() {
	if (_status == NULL)
		return "No tasks";

	return _status->describe();
}
