#pragma once

#include <iostream>
#include "Point2D.h"

class Character {

private:

    std::string name;        // имя персонажа
    Point2D location;   // текущее положение персонажа
    bool npc;           // признак NPC

public:

    Character(const std::string& name, const Point2D& location, bool npcFlag = 0);

    void moveTo(Point2D point);

    //0 - вверх 1 - вправо 2 - вниз 3 - влево 4 - вверх-влево 
    //5 - вверх-вправо 6 - вниз-вправо 7 - вниз-влево
    void moveTo(int direction, int steps);

    Point2D getLocation();

    bool isNPC();

    virtual void autoMove() = 0;
};

class Prey : public Character {

private:

    const int maxRange = 1;

public:

    Prey(const std::string& name, const Point2D& location, bool npcFlag = 0);

    int askDirection();

    void autoMove() override;

};

class Predator : public Character {
private:

    const int maxRange = 5;

public:
    Predator(const std::string& name, const Point2D& location, bool npcFlag = 0)
        : Character(name, location, npcFlag) {   }

    int askRange() {

        do {
            int range;
            std::cout << "На сколько? (1-5) \n";
            std::cin >> range;

            if (range >= 1 && range <= maxRange) {
                return range;
            }
            else std::cout << "Некорректный ввод, попробуй ещё раз \n";

        } while (true);
    }

    int askDirection() {
        do {

            int direction(0);
            std::cout << "Куда идти?\n";
            std::cout << "0 - вверх, 1 - вправо, 2 - вниз, 3 - влево,\n";
            std::cin >> direction;

            if (direction <= 3 && direction >= 0) {
                return direction;
            }
            else std::cout << "Некорректный ввод, попробуй ещё раз \n";

        } while (true);

    }

    void autoMove() override {

        int direction = 0;
        int range = 0;

        if (isNPC()) {
            direction = rand() % 4;
            range = rand() % 5 + 1;
        }
        else {
            direction = askDirection();
            range = askRange();
        }

        moveTo(direction, range);
    }

};
/*void autoMove(Prey& prey, Arena& a) { //умный ход для жертвы
        if (abs(loc_x() - prey.loc_x()) >= abs(loc_y() - prey.loc_y())) {
            if (abs(loc_x() - prey.loc_x()) <= 5) moveTo(prey.loc_x(), loc_y(), a);
            else {
                if ((loc_x() - prey.loc_x()) > 0) moveTo(loc_x() - 5, loc_y(), a);
                else moveTo(loc_x() + 5, loc_y(), a);
            }
        }
        else {
            if (abs(loc_y() - prey.loc_y()) <= 5) moveTo(loc_x(), prey.loc_y(), a);
            else {
                if ((loc_y() - prey.loc_y()) > 0) moveTo(loc_x(), loc_y() - 5, a);
                else moveTo(loc_x(), loc_y() + 5, a);
            }
        }
    }*/

    /*void autoMove(Predator& pred, Arena& a) { // умный ход для хищника
          if (loc_x() == pred.loc_x()) {
              if (loc_x() >= (a.get_l() - loc_x())) moveTo(loc_x() - 1, loc_y(), a);
              else moveTo(loc_x() + 1, loc_y(), a);
          }
          else if (loc_y() == pred.loc_y()) {
              if (loc_y() >= (a.get_w() - loc_y())) moveTo(loc_x(), loc_y() - 1, a);
              else moveTo(loc_x(), loc_y() - 1, a);
          }
          else if (abs(loc_x() - pred.loc_x()) >= abs(loc_y() - pred.loc_y())) {
              if (((loc_y() - pred.loc_y()) < 0) && (pred.loc_y() != 1) && (pred.loc_y() != a.get_w())) moveTo(loc_x(), loc_y() - 1, a);
              else moveTo(loc_x(), loc_y() + 1, a);
          }
          else if (abs(loc_x() - pred.loc_x()) > abs(loc_y() - pred.loc_y())) {
              if (((loc_x() - pred.loc_x()) < 0) && (pred.loc_x() != 1) && (pred.loc_x() != a.get_l())) moveTo(loc_x() - 1, loc_y(), a);
              else moveTo(loc_x() + 1, loc_y(), a);
          }
      }*/