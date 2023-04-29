#pragma once

#include "../Arena.h"
#include "Predator_test.h"
#include "Prey_test.h"

Prey* prey = new Prey("Poozik", Point2D(7, 5), true);
Predator* predator = new Predator("Kozyavik", Point2D(3, 2), true);

struct ArenaTest : public testing::Test {

	Arena* arena;

	void SetUp() {
		arena = new Arena(6, 7, prey, predator);
	}

	void TearDown() {
		delete arena;
	}
};

TEST(ArenaTest, heck_Over_Run) {

	int x[] = { 300, 500, 3456, 123456 };
	int y[] = { 782, 2345, -2345, 344 };
	Arena* arena = new Arena(6, 7, prey, predator);

	for (int i = 0; i < std::size(x); i++) {
		for (int j = 0; j < std::size(y); j++) {
			Point2D point(x[i], y[j]);
			predator->moveTo(x[i], y[i]);
			EXPECT_EQ(arena->checkOverRun(), true);
		}
	}
}