/*
Josh Mencsik
30 January 2020
Implementation of the runtime class
*/
#include <iostream>
#include "runtime.h"

using namespace std;

Runtime::Runtime() {
    MyTime tmp;
    distance = 0;
    rtime = tmp;
}

Runtime Runtime::operator +(const Runtime& rhs)const {
    Runtime tmp; 
    tmp.set_time(rtime + rhs.rtime);
    tmp.set_distance(distance + rhs.distance);

    return tmp;

}

Runtime Runtime::operator -(const Runtime& rhs)const {
    Runtime tmp;
    tmp.set_time(rtime - rhs.rtime);
    tmp.set_distance(distance + rhs.distance);

    return tmp;
}

Runtime Runtime::operator *(const double& rhs) const {
    Runtime tmp;
    tmp.set_time(rtime * rhs);
    tmp.set_distance(distance * rhs);

    return tmp;
}

Runtime Runtime::operator /(const double& rhs) const {
    Runtime tmp;
    tmp.set_time(rtime * rhs);
    tmp.set_distance(distance * rhs);

    return tmp;
}

bool Runtime::operator == (const Runtime& rhs) const {
    return (distance_equal(rhs.distance) && rtime == rhs.rtime);
}
 
bool Runtime::operator != (const Runtime& rhs) const {
    return (!distance_equal(rhs.distance) || !(rtime == rhs.rtime));
 
}

bool Runtime::distance_equal(double d) const {
    return (abs(distance - d) < .01);
}

void Runtime::input(istream& ins) {
    ins >> rtime;
    ins >> distance;
}

void Runtime::output(ostream& outs) const {
    outs << rtime;
    outs << " " << distance;
}

Runtime operator *(const double& lhs, const Runtime& rhs) {
    Runtime tmp;
    tmp.set_time(rhs.get_time() * lhs);
    tmp.set_distance(rhs.get_distance() * lhs);

    return tmp;
}

ostream& operator <<(ostream& outs, const Runtime& rhs) {
    rhs.output(outs);
    return outs;
}

istream& operator >>(istream& ins, Runtime& rhs) {
    rhs.input(ins);
    return ins;
}




