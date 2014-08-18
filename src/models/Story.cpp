/*
 * Story.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: twiik
 */

#include "Story.h"
#include "../utils/string.cpp"

Story::Story(string name, int initialEffortEstimation) :
	_name(name), _initialEffortEstimation(initialEffortEstimation) {
}

Story::~Story() {
	_tasks.clear();
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
