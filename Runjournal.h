/*
Josh Mencsik
30 January 2020

The Runjournal class allows a user to manipulate an array containing
runtime objects
*/

#include<iostream>
#include "runtime.h"
#include "MyTime.h" 
#ifndef RUNJOURNAL_H
#define RUNJOURNAL_H

class Runjournal {
    public:
    Runjournal();
    //getters
    int getUsed() const {return used;}
    Runtime getData(int index) const {return data[index];}
    //setters
    void setUsed(int u) {used = u;}
    void setRun(int index, const Runtime& rt) {data[index] = rt;}

    //adds a runtime onto the list and increases used
    void record(const Runtime& rt);

    //output all the runs
    void display() const;

    //searches for a given Runtime and gives the user the option to remove
    void find_remove(const Runtime& rt);

    //search for all of a given distance and show it
    void distance_view(double d) const;

    //sort data by time
    void time_sort();

    //sort data by distance
    void distance_sort();

    //return a total for the time
    MyTime total_time() const;

    //return a total for the distance
    double total_distance() const;

    //return the average pace for all the runs
    MyTime average_pace() const;



    private:
    static const int CAPACITY = 200; 
    int used;
    Runtime data[CAPACITY];
};







#endif