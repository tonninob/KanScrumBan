/*
 * Task.cpp
 *
 *  Created on: Aug 5, 2014
 *      Author: twiik
 */
#include "Task.h"
#include "../utils/string.cpp"
#include "../exceptions/NoSuchTaskResponsible.h"

Task::Task(string name, int initialEstimation, string featureId, string internalId) :
						 _name(name),
						 _initialEstimation(initialEstimation),
						 _featureId(featureId),
						 _internalId(internalId),
						 _workDoneAmount(0) {
	_status = new ScrumWorkStatus::NotStarted();
}

string Task::describe() {
	string description = "";
	description += includeFeatureIdInDescription()
							+ includeInternalIdInDescription()
							+ includeNameInDescription()
							+ includeEstimationInDescription()
						  + includeResponsiblesInDescription();
	return description; //_name + ", (" + _initialEstimation; + ")";
}

string Task::includeFeatureIdInDescription() {
	string description = _featureId;
	if (_featureId.length() > 0)
		description += ", ";
	return description;
}

string Task::includeInternalIdInDescription() {
	string description = _internalId;
	if (_internalId.length() > 0)
		description += ", ";
	return description;
}

string Task::includeNameInDescription() {
	string description = _name;
	return description;
}

string Task::includeEstimationInDescription() {
	if (_initialEstimation > 0)
		return " | (" + patch::to_string(_workDoneAmount) + "/"
									+ patch::to_string(_initialEstimation) + ")";
	return "";
}

string Task::includeResponsiblesInDescription() {
	string description = _responsibles.size() == 0 ? "": " | ";
	for(std::vector<IResponsible*>::iterator it = _responsibles.begin(); it != _responsibles.end(); it++)
	{
		description += (*it)->tellName();
		if (it+1 != _responsibles.end())
			description += ", ";
	}
	return description;
}

void Task::addResponsible(IResponsible* responsible) {
	_responsibles.push_back(responsible);
}

void Task::setWorkDoneAmount(int amount) {
	_workDoneAmount = amount;
}

void Task::removeResponsible(IResponsible * responsible) {
	for(std::vector<IResponsible*>::iterator it = _responsibles.begin(); it != _responsibles.end(); it++)
		 if ((*it) == responsible) {
			 it = _responsibles.erase(it);
			 return;
		 }
	throw ScrumExceptions::NoSuchTaskResponsible();
}

string Task::describeStatus() {
	return _status->describe();
}

void Task::setStatus(ScrumWorkStatus::WorkStatus* status) {
	delete _status;
	_status = status;
}
