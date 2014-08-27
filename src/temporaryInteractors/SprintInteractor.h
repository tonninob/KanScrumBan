/*
 * SprintInteractor.h
 *
 *  Created on: Aug 11, 2014
 *      Author: twiik
 */

#ifndef SPRINTINTERACTOR_H_
#define SPRINTINTERACTOR_H_

#include "../domain/interactors/ISprintInteractor.h"

class SprintInteractor : public ISprintInteractor {
public:
	Sprint* createSprint();
	int getSprintCount();
};

#endif /* SPRINTINTERACTOR_H_ */
