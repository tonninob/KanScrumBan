/*
 * ISprintInteractor.h
 *
 *  Created on: Aug 27, 2014
 *      Author: twiik
 */

#ifndef ISPRINTINTERACTOR_H_
#define ISPRINTINTERACTOR_H_

#include <vector>
#include "../models/Sprint.h"

class ISprintInteractor {
protected:
	std::vector<Sprint*> _sprints;
public:
	virtual Sprint* createSprint() = 0;
	virtual int getSprintCount() = 0;

	virtual ~ISprintInteractor() {
		for(std::vector<Sprint*>::const_iterator it = _sprints.begin(); it != _sprints.end(); it++)
		{
		    delete *it;
		}
		_sprints.clear();
	};
};

#endif /* ISPRINTINTERACTOR_H_ */
