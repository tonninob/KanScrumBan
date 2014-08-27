#include <gtest/gtest.h>
//#include "hippomocks.h"
#include "../src/User.h"
#include "../src/domain/models/ProductLine.h"
#include "../src/domain/models/Story.h"
#include "../src/temporaryInteractors/TaskInteractor.h"
#include "../src/temporaryInteractors/ProductLineInteractor.h"
#include "../src/temporaryInteractors/StoryInteractor.h"
#include "../src/domain/exceptions/NoSuchTaskResponsible.h"
#include "../src/domain/exceptions/NoSuchTaskInStory.h"
#include "../src/domain/status/all.h"

//using namespace std;
class UserTest : public testing::Test {
protected:

	virtual void SetUp() {
		//actor = TaskInteractor();
		user = new User(taskActor, storyActor, "Bobby");
	}

	virtual void TearDown() {
		delete user;
	}

	TaskInteractor taskActor;
	StoryInteractor storyActor;
	User* user;
};

TEST_F(UserTest, UserCanCreateTask)
{

  ASSERT_EQ(0, taskActor.getTaskCount());

  user->createTask("Task1");

  ASSERT_EQ(1, taskActor.getTaskCount());
}

TEST_F(UserTest, UserCanCreateTaskWithInitialEstimation)
{
  Task* task = user->createTask("Task1", 5);
	ASSERT_EQ(5, task->tellInitialEstimation());
}

TEST_F(UserTest, UserCanEditTaskInitialEffortEstimation) {
  Task* task  = user->createTask("Some task", 1, "", "");
	user->setTaskInitialEffortEstimation(*task, 3);
	ASSERT_STREQ("Some task | (0/3)", task->describe().c_str());
}

TEST_F(UserTest, UserCanCreateTaskWithFeatureID)
{
  Task* task = user->createTask("Task1", 5, "LTE1757-a-e3");

  ASSERT_EQ(1, taskActor.getTaskCount());
	ASSERT_STREQ("LTE1757-a-e3, Task1 | (0/5)", task->describe().c_str());
}

TEST_F(UserTest, UserCanCreateTaskWithInternalID)
{
  Task* task = user->createTask("Task1", 5, "LTE1757-a-e3", "B1_234");

  ASSERT_EQ(1, taskActor.getTaskCount());
	ASSERT_STREQ("LTE1757-a-e3, B1_234, Task1 | (0/5)", task->describe().c_str());

}

TEST_F(UserTest, UserCanDeleteTask)
{
	Task* task = user->createTask("Task1");
  user->deleteTask(*task);
  ASSERT_EQ(0, taskActor.getTaskCount());
}

TEST_F(UserTest, UserCanRenameTask)
{
	Task* task = user->createTask("Task1");
	user->renameTask(*task, "Task2");

	ASSERT_STREQ("Task2", task->describe().c_str());
}

TEST_F(UserTest, CanCreateUserWithName)
{
	ASSERT_STREQ("Bobby", user->tellName().c_str());
}

TEST_F(UserTest, UserCanAttachResponsibleToTask)
{
	User responsible(taskActor, storyActor, "Arnold");

	Task* task = user->createTask("Task1");
	user->addResponsibleToTask(*task, &responsible);

	ASSERT_STREQ("Task1 | Arnold", task->describe().c_str());
}

TEST_F(UserTest, UserCanAttachSecondResponsibleToTask)
{
	User responsible(taskActor, storyActor, "Arnold");
	User responsible2(taskActor, storyActor, "Timmy");

	Task* task = user->createTask("Task1");
	user->addResponsibleToTask(*task, &responsible);
	user->addResponsibleToTask(*task, &responsible2);

	ASSERT_STREQ("Task1 | Arnold, Timmy", task->describe().c_str());
}

TEST_F(UserTest, UserCanRemoveResponsibleFromTask)
{
	Task* task = user->createTask("Task1");
	user->addResponsibleToTask(*task, user);
	user->removeResponsibleFromTask(*task, user);
	ASSERT_STREQ("Task1", task->describe().c_str());

}

TEST_F(UserTest, UserCantRemoveResponsibleIfNotAdded)
{
	User responsible(taskActor, storyActor, "Arnold");
	Task* task = user->createTask("Task1");

	user->addResponsibleToTask(*task, &responsible);
	ASSERT_THROW(user->removeResponsibleFromTask(*task, user), ScrumExceptions::NoSuchTaskResponsible);
//	ASSERT_STREQ("Task1", task->describe().c_str());
}

TEST_F(UserTest, UserCanEditWorkDoneAmount)
{
	Task* task = user->createTask("Task1", 20);
	user->setTaskWorkDoneAmount(*task, 10);
	ASSERT_STREQ("Task1 | (10/20)", task->describe().c_str());
}

TEST_F(UserTest, UserCanAssignTaskToProductLine)
{
	ProductLine line;
	ProductLineInteractor lineActor;
	user->assignTaskToProductLine(user->createTask("Task1"), line, lineActor);
  ASSERT_EQ(1, line.getTasks().size());
	ASSERT_STREQ("Task1", line.getTasks()[0]->describe().c_str());
}

TEST_F(UserTest, UserCanCreateTaskWithNotStartedStatus)
{
  Task* task = user->createTask("Buy coffee", 1, "", "");
	ASSERT_STREQ("Not started", task->describeStatus().c_str());
}

TEST_F(UserTest, UserCanChangeStatusToStarted)
{
  Task* task = user->createTask("Buy coffee", 1, "", "");
  user->setTaskStatus(task, new ScrumWorkStatus::Started());
	ASSERT_STREQ("Started", task->describeStatus().c_str());
}

TEST_F(UserTest, UserCanChangeStatusToOnHold)
{
  Task* task = user->createTask("Buy coffee", 1, "", "");
  user->setTaskStatus(task, new ScrumWorkStatus::OnHold());
	ASSERT_STREQ("On hold", task->describeStatus().c_str());
}

TEST_F(UserTest, UserCanChangeStatusToCompleted)
{
  Task* task = user->createTask("Buy coffee", 1, "", "");
  user->setTaskStatus(task, new ScrumWorkStatus::Completed());
	ASSERT_STREQ("Completed", task->describeStatus().c_str());
}

TEST_F(UserTest, UserCanChangeStatusToRemoved)
{
  Task* task = user->createTask("Buy coffee", 1, "", "");
  user->setTaskStatus(task, new ScrumWorkStatus::Removed());
	ASSERT_STREQ("Removed", task->describeStatus().c_str());
}

TEST_F(UserTest, UserCanCreateStoryWithNameAndInitialEffortEstimation)
{
  Story* story = user->createStory("Buy whiskey for birthday guy", 2);
	ASSERT_STREQ("Buy whiskey for birthday guy (2) | Tasks: 0", story->describe().c_str());
}

TEST_F(UserTest, UserCanCreateTaskToStory)
{
  Story* story = user->createStory("Buy whiskey for birthday guy", 2);
  user->createTask("Collect money from team", 1, "", "", story);
	ASSERT_STREQ("Buy whiskey for birthday guy (2) | Tasks: 1", story->describe().c_str());
}

TEST_F(UserTest, UserCanAddTaskToStory)
{
  Story* story = user->createStory("Buy whiskey for birthday guy", 2);
  user->createTask("Collect money from team", 1, "", "", story);
  Task* task = user->createTask("Buy the bottle", 1, "", "");
	ASSERT_STREQ("Buy whiskey for birthday guy (2) | Tasks: 1", story->describe().c_str());
	user->addTaskToStory(story, task);
	ASSERT_STREQ("Buy whiskey for birthday guy (2) | Tasks: 2", story->describe().c_str());
}

TEST_F(UserTest, UserCanRemoveTaskFromStory)
{
  Story* story = user->createStory("Buy whiskey for birthday guy", 2);
  Task* task  = user->createTask("Collect money from team", 1, "", "", story);
  user->removeTaskFromStory(story, task);
	ASSERT_STREQ("Buy whiskey for birthday guy (2) | Tasks: 0", story->describe().c_str());
}

TEST_F(UserTest, UserCantRemoveTaskFromStoryIfNotAdded)
{
  Story* story = user->createStory("Buy whiskey for birthday guy", 2);
  Task* task  = user->createTask("Collect money from team", 1, "", "");

	ASSERT_THROW(user->removeTaskFromStory(story, task), ScrumExceptions::NoSuchTaskInStory);
//	ASSERT_STREQ("Task1", task->describe().c_str());
}

TEST_F(UserTest, UserCanChangeStoryStatusToCompleted) {
	Story* story = user->createStory("Buy whiskey for birthday guy", 2);
	user->completeStory(story);

	ASSERT_STREQ("Completed", story->tellStatus().c_str());
}

TEST_F(UserTest, UserEditStoryInitialEffortEstimation) {
  Story* story = user->createStory("Buy whiskey for birthday guy", 2);
  user->setStoryInitialEffortEstimation(story, 3);
	ASSERT_STREQ("Buy whiskey for birthday guy (3) | Tasks: 0", story->describe().c_str());
}

