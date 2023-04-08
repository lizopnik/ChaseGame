#pragma once

#include <iostream>
#include "Characters.h"

class Arena {

    int length, width;
    Prey* prey;
    Predator* predator;

public:
    Arena(int l, int w, Prey* prey, Predator* predator);

    friend std::ostream& operator<<(std::ostream&, const Arena&);

};
