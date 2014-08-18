#include <gtest/gtest.h>
//#include "hippomocks.h"
#include "../src/ScrumMaster.h"
#include "../src/interactors/SprintInteractor.h"
#include "../src/interactors/TaskInteractor.h"
#include "../src/interactors/ProductLineInteractor.h"
#include "../src/exceptions/NoSuchTaskResponsible.h"

//using namespace std;
class ScrumMasterTest : public testing::Test {
protected:

	virtual void SetUp() {
		master = new ScrumMaster(actor, lineActor, taskActor, storyActor, "Bobby");
	}

	virtual void TearDown() {
		delete master;
	}

	SprintInteractor actor;
	ProductLineInteractor lineActor;
	TaskInteractor taskActor;
	StoryInteractor storyActor;
	ScrumMaster* master;
};

TEST_F(ScrumMasterTest, CanCreateSprint) {
  ASSERT_EQ(0, actor.getSprintCount());
	master->createSprint();
  ASSERT_EQ(1, actor.getSprintCount());
}

TEST_F(ScrumMasterTest, CanCreateProductionLine) {
  ASSERT_EQ(0, lineActor.getLineCount());
  master->createProductLine();
  ASSERT_EQ(1, lineActor.getLineCount());
}

TEST_F(ScrumMasterTest, CanAssignTaskToProductLine)
{
	ProductLine line;
	ProductLineInteractor lineActor;
	master->assignTaskToProductLine(master->createTask("Task1"), line, lineActor);
  ASSERT_EQ(1, line.getTasks().size());
	ASSERT_STREQ("Task1", line.getTasks()[0]->describe().c_str());
}
