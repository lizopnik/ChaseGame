#pragma once

#include <iostream>
#include "Characters.h"


class Arena {

    int length, width;
    Prey* prey;
    Predator* predator;

    int view_length, view_width;
    char** field;

public:

    Arena(int l, int w, Prey* prey, Predator* predator); // онструктор

    void clearStep();  //удаление хищника и жертвы с арены
    bool checkOverRun(); //проверка на выход за пределы арены

    ~Arena(); //ƒеструтор

    friend std::ostream& operator<<(std::ostream&, const Arena&); //перегрузка оператора вывода

};
