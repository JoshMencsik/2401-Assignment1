/*
Josh Mencsik
30 January 2020
Implementation of the runtime class
*/
#include <iostream>
#include "runtime.h"

using namespace std;

Runtime::Runtime(const MyTime& myt, double d) {
    MyTime tmp;
    distance = d;
    rtime = tmp;
}

Runtime Runtime::operator +(const Runtime& rhs)const {
    MyTime mtmp;
    Runtime tmp(mtmp); 
    tmp.set_time(rtime + rhs.rtime);
    tmp.set_distance(distance + rhs.distance);

}
