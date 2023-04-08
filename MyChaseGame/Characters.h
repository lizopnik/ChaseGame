#pragma once
#include <iostream>
#include "Point2D.h"

class Prey {
    
private:
    friend class Arena;
    std::string name;
    Point2D location;

public:
    Prey(const std::string& name, const Point2D& location) : name(name), location(location) {   }

    void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }

    void AutoMove(const Arena&, int z);

    
    int get_x() {
        return location.x;
    }
    int get_y() {
        return location.y;
    }
};



class Predator {
private:
    std::string name;
    Point2D location;

public:
    Predator(const std::string& name, const Point2D& location) : name(name), location(location) {   }

    void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }
    void AutoMove(const Arena&, int z);
    friend bool check(const Prey& prey, const Predator& predator);
    friend bool check1(const Prey& prey, const Predator& predator);
};

