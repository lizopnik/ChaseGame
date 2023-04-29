#pragma once

#include "../Characters.h"


struct PreyTest : public testing::Test {

	Prey* prey;

	void SetUp() {
		prey = new Prey("Poozik", Point2D(7, 5), true);
	}

	void TearDown() {
		delete prey;
	}
};


TEST_F(PreyTest, init_class) {

	EXPECT_STREQ(prey->getName().c_str(), "Poozik");

	EXPECT_TRUE(prey->isNPC());
	ASSERT_TRUE(Point2D(7, 5) == prey->getLocation());
}

TEST(PreyTest, move_prey) {

	int x[] = { 0, 10, 100, 1000, -10, -100, -1000 };
	int y[] = { 78, 10234567, 112, -1000, -6789, 0, 35 };

	for (int i = 0; i < std::size(x); i++) {
		for (int j = 0; j < std::size(y); j++) {
			Point2D point(x[i], y[j]);
			prey->moveTo(point);
			EXPECT_EQ(prey->getLocation(), point);
		}
	}
}
TEST(PreyTest, move_prey_steps) {

	int x[] = { 0, 10, 100, 1000, -10, -100, -1000 };
	int y[] = { 78, 10234567, 112, -1000, -6789, 0, 35 };

	for (int i = 0; i < std::size(x); i++) {
		for (int j = 0; j < std::size(y); j++) {
			Point2D point(x[i], y[j]);
			prey->moveTo(x[i], y[i]);
			EXPECT_EQ(prey->getLocation(), point);
		}
	}
}