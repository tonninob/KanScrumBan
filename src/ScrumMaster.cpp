/*
 * ScrumMaster.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: twiik
 */

#include "ScrumMaster.h"

using namespace std;

ScrumMaster::ScrumMaster(SprintInteractor& sprintactor, ProductLineInteractor& lineactor,
		TaskInteractor& taskactor, StoryInteractor& storyActor, string name) : User(taskactor, storyActor, name),
		_sprintactor(sprintactor),
		_lineactor(lineactor),
		_name(name) {
}

Sprint* ScrumMaster::createSprint() {
	return _sprintactor.createSprint();
}

ProductLine* ScrumMaster::createProductLine() {
	return _lineactor.createLine();
}
