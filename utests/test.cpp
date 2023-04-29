#include "pch.h"

#include "Point2D_test.h"
#include "Prey_test.h"
#include "Predator_test.h"
#include "Arena_test.h"


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}