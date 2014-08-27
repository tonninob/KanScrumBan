/*
 * StoryTest.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: twiik
 */
#include <gtest/gtest.h>
//#include "hippomocks.h"
#include "../src/User.h"
#include "../src/domain/models/Story.h"
#include "../src/domain/models/ProductLine.h"
#include "../src/temporaryInteractors/TaskInteractor.h"
#include "../src/temporaryInteractors/StoryInteractor.h"
#include "../src/domain/exceptions/NoSuchTaskResponsible.h"
#include "../src/domain/exceptions/NoSuchTaskInStory.h"
#include "../src/domain/status/all.h"

TEST(StoryTest, EmptyStoryHasStatusOfNoTasks) {
	Story story("Buy whiskey for birthday guy", 2);

	ASSERT_STREQ("No tasks", story.tellStatus().c_str());
}

TEST(StoryTest, IfStoryHasStartedTasksItIsAlsoStarted) {
	TaskInteractor taskActor;
	StoryInteractor storyActor;
	User user(taskActor, storyActor, "Bobby");
	Story story("Buy whiskey for birthday guy", 2);
	Task* task = user.createTask("Collect money", 1, "", "", &story);

	user.setTaskStatus(task, new ScrumWorkStatus::Started());

	ASSERT_STREQ("Started", story.tellStatus().c_str());
}


