#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <cstdlib>

#include "Characters.h"
#include "Arena.h"

using namespace std;


int main() {
    system("chcp 65001");

    srand(time(NULL));

    Prey prey("prey", Point2D(5, 20), true);
    Predator predator("predator", Point2D(3, 10), true);

    Arena arena(30, 30, &prey, &predator);

    cout << arena;
    return 0;
}