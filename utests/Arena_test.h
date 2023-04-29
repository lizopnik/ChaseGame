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
