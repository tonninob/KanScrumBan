/*
 * ScrumMaster.h
 *
 *  Created on: Aug 11, 2014
 *      Author: twiik
 */

#ifndef SCRUMMASTER_H_
#define SCRUMMASTER_H_

#include <string>
#include "User.h"
#include "interactors/SprintInteractor.h"
#include "interactors/TaskInteractor.h"
#include "interactors/ProductLineInteractor.h"
#include "interactors/StoryInteractor.h"

class Sprint;
class ProductLine;

using namespace std;

class ScrumMaster : public User {
	SprintInteractor& _sprintactor;
	ProductLineInteractor& _lineactor;
	string _name;
public:
	ScrumMaster(SprintInteractor& sprintactor, ProductLineInteractor& lineactor,
			TaskInteractor& actor, StoryInteractor& storyActor, string name);
	Sprint* createSprint();
	ProductLine* createProductLine();
};

#endif /* SCRUMMASTER_H_ */
