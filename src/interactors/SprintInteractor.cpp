/*
 * SprintInteractor.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: twiik
 */

#include "SprintInteractor.h"

Sprint* SprintInteractor::createSprint() {
	Sprint* sprint = new Sprint();
	_sprints.push_back(sprint);
	return sprint;
}

int SprintInteractor::getSprintCount() {
	return _sprints.size();
}
