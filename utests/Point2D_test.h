#pragma once

#include "../Point2D.h"

TEST(TestPoint2D, TestConst1) {

	int x[] = { 0, 10, 100, 1000, -10, -100, -1000 };
	int y[] = { 78, 10234567, 112, -1000, -6789, 0, 35 };

	for (int i = 0; i < std::size(x); i++) {
		for (int j = 0; j < std::size(y); j++) {
			Point2D point(x[i], y[j]);

			EXPECT_EQ(point.getX(), x[i]);
			EXPECT_EQ(point.getY(), y[j]);
		}
	}

}

TEST(TestPoint2D, TestConst2) {

	int x[] = { 0, 10, 100, 1000, -10, -100, -1000 };
	int y[] = { 78, 10234567, 112, -1000, -6789, 0, 35 };

	for (int i = 0; i < std::size(x); i++) {
		for (int j = 0; j < std::size(y); j++) {

			Point2D point1(x[i], y[j]);
			Point2D point2(x[i], y[j]);

			ASSERT_TRUE(point1 == point2);

			Point2D point3(x[i] + 1, y[j]);
			Point2D point4(x[i], y[j] + 1);

			ASSERT_TRUE(point3 == point4);
		}
	}
}
