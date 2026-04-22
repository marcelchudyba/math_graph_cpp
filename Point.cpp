//
// Created by XXX on 22.04.2026.
//

#include "Point.h"


Point::Point(int x, int y) : x(x), y(y){};
int Point::GetX() const {
    return x;
}
int Point::GetY() const {
    return y;
}