/*
 * User.h
 *
 *  Created on: Aug 5, 2014
 *      Author: twiik
 */

#ifndef USER_H_
#define USER_H_

#include <string>
#include "interactors/TaskInteractor.h"
#include "interactors/ProductLineInteractor.h"
#include "interactors/StoryInteractor.h"
#include "operators/IResponsible.h"
#include "operators/IProductLineOperator.h"

class Task;
class ProductLine;
class Story;

class User : public IResponsible, public IProductLineOperator
{
protected:
	TaskInteractor& _actor;
	StoryInteractor& _storyActor;
	std::string _name;
public:
	User(TaskInteractor& actor, StoryInteractor& storyActor, std::string name) : _actor(actor), _name(name), _storyActor(storyActor) {};
	Task* createTask(std::string name, int initialEstimation=0, std::string featureId="", std::string internalId="", Story* story=NULL);
	void renameTask(Task& task, std::string name);
	void addResponsibleToTask(Task& task, IResponsible* responsible);
	void removeResponsibleFromTask(Task& task, IResponsible* responsible);
	void deleteTask(Task& task);
	void setTaskWorkDoneAmount(Task& task, int amount);

	virtual void assignTaskToProductLine(Task* task, ProductLine& line, ProductLineInteractor& actor);

	virtual std::string tellName() { return _name; }
	virtual bool operator== (IResponsible& compareto);

	Story* createStory(std::string name, int initialEffortEstimation=0);
	void addTaskToStory(Story* story, Task* task);
	void removeTaskFromStory(Story* story, Task* task);
};



#endif /* USER_H_ */
