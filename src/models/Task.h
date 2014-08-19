/*
 * Task.h
 *
 *  Created on: Aug 5, 2014
 *      Author: twiik
 */

#ifndef TASK_H_
#define TASK_H_

#include <string>
#include <vector>
#include <algorithm>
#include "../operators/IResponsible.h"
#include "../status/all.h"

using namespace std;

class Task
{
	string _name;
	int _initialEstimation;
	string _featureId;
	string _internalId;
	int _workDoneAmount;
	std::vector<IResponsible*> _responsibles;
	ScrumWorkStatus::WorkStatus* _status;

	string includeFeatureIdInDescription();
	string includeNameInDescription();
	string includeEstimationInDescription();
	string includeInternalIdInDescription();
	string includeResponsiblesInDescription();

public:
  Task(string name, int initialEstimation, string featureId, string internalId);
  virtual ~Task() {
		_responsibles.clear();
		delete _status;
	};
  void setName(string name) { _name = name; }
 // string tellName() { return _name; }
 // string tellFeatureId() { return _name; }
  string describe();
  int tellInitialEstimation() { return _initialEstimation; }
  void addResponsible(IResponsible* responsible);
  void removeResponsible(IResponsible* responsible);
  void setWorkDoneAmount(int amount);
  string describeStatus();
  void setStatus(ScrumWorkStatus::WorkStatus* status);
  void setInitialEffortEstimation(int amount) {_initialEstimation = amount;};

  bool operator== (Task& compareto) {
  	return _name.compare(compareto._name) == 0;
  }
};



#endif /* TASK_H_ */



