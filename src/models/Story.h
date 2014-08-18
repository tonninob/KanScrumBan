/*
 * Story.h
 *
 *  Created on: Aug 14, 2014
 *      Author: twiik
 */

#ifndef STORY_H_
#define STORY_H_

#include <string>
#include "Task.h"

using namespace std;

class Story {
	string _name;
	int _initialEffortEstimation;
	vector<Task*> _tasks;

	string includeEstimationToDescription();
	string includeTaskCountToDescription();
public:
	Story(string name, int initialEffortEstimation);
	virtual ~Story();

	string describe();
	void addTask(Task *task);
};

#endif /* STORY_H_ */
