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
#include "domain/interactors/ISprintInteractor.h"
#include "domain/interactors/ITaskInteractor.h"
#include "domain/interactors/IProductLineInteractor.h"
#include "domain/interactors/IStoryInteractor.h"

class Sprint;
class ProductLine;

using namespace std;

class ScrumMaster : public User {
	ISprintInteractor& _sprintactor;
	IProductLineInteractor& _lineactor;
	string _name;
public:
	ScrumMaster(ISprintInteractor& sprintactor, IProductLineInteractor& lineactor,
			ITaskInteractor& actor, IStoryInteractor& storyActor, string name);
	Sprint* createSprint();
	ProductLine* createProductLine();
};

#endif /* SCRUMMASTER_H_ */
