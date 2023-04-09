#pragma once
#include <iostream>
#include "Point2D.h"
#include "Arena.h"

class Character {

private:

    std::string name;        // имя персонажа
    Point2D location;   // текущее положение персонажа
    bool npc;           // признак NPC

public:

    Character(const std::string& name, const Point2D& location, bool npcFlag = 0);

    int loc_x() { return location.get_x(); };
    int loc_y() { return location.get_y(); };

    void moveTo(Point2D point);

    //двигаемся по оси x и y
    void moveTo(int x, int y, Arena& a);

    Point2D getLocation();

    bool isNPC();

    //virtual void autoMove() = 0;
};

class Prey : public Character {

private:

    const int maxRange = 1;

public:

    Prey(const std::string& name, const Point2D& location, bool npcFlag = 0);

    void autoMove(Predator& pred, Arena& a) {
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
    }
};

class Predator : public Character {
private:

    const int maxRange = 5;

public:
    Predator(const std::string& name, const Point2D& location, bool npcFlag = 0)
        : Character(name, location, npcFlag) {   }


    void autoMove(Prey& prey, Arena& a) {
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
    }

};