/*
 * StoryTest.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: twiik
 */
#include <gtest/gtest.h>
//#include "hippomocks.h"
#include "../src/User.h"
#include "../src/models/ProductLine.h"
#include "../src/interactors/TaskInteractor.h"
#include "../src/interactors/StoryInteractor.h"
#include "../src/exceptions/NoSuchTaskResponsible.h"
#include "../src/exceptions/NoSuchTaskInStory.h"
#include "../src/status/all.h"

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


