/*
 * SprintInteractor.h
 *
 *  Created on: Aug 11, 2014
 *      Author: twiik
 */

#ifndef SPRINTINTERACTOR_H_
#define SPRINTINTERACTOR_H_

#include <vector>
#include "../models/Sprint.h"

class SprintInteractor {
	std::vector<Sprint*> _sprints;
public:
	Sprint* createSprint();
	int getSprintCount();

	virtual ~SprintInteractor() {
		for(std::vector<Sprint*>::const_iterator it = _sprints.begin(); it != _sprints.end(); it++)
		{
		    delete *it;
		}
		_sprints.clear();
	};
};

#endif /* SPRINTINTERACTOR_H_ */
