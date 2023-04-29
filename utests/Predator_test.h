#pragma once

#include "../Characters.h"


struct PredatorTest : public testing::Test {

	Predator* predator;

	void SetUp() {
		predator = new Predator("Kozyavik", Point2D(3, 2), true);
	}

	void TearDown() {
		delete predator;
	}
};


TEST_F(PredatorTest, init_class) {

	EXPECT_STREQ(predator->getName().c_str(), "Kozyavik");

	EXPECT_TRUE(predator->isNPC());
	ASSERT_TRUE(Point2D(3, 2) == predator->getLocation());
}


TEST(PredatorTest, move_predator) {

	int x[] = { 0, 10, 100, 1000, -10, -100, -1000 };
	int y[] = { 78, 10234567, 112, -1000, -6789, 0, 35 };

	for (int i = 0; i < std::size(x); i++) {
		for (int j = 0; j < std::size(y); j++) {
			Point2D point(x[i], y[j]);
			predator->moveTo(point);
			EXPECT_EQ(predator->getLocation(), point);
		}
	}
}

TEST(PredatorTest, move_predator_steps) {

	int x[] = { 0, 10, 100, 1000, -10, -100, -1000 };
	int y[] = { 78, 10234567, 112, -1000, -6789, 0, 35 };

	for (int i = 0; i < std::size(x); i++) {
		for (int j = 0; j < std::size(y); j++) {
			Point2D point(x[i], y[j]);
			predator->moveTo(x[i], y[i]);
			EXPECT_EQ(predator->getLocation(), point);
		}
	}
}