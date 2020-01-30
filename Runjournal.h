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
    int getData() const {return data;}
    //setters
    void setUsed(int u) {used = u;}
    void setJournal(Runtime d[]) {data = d;}
    void setRun(int index, const Runtime& rt) {data[index] = rt;}

    //adds a runtime onto the list and increases used
    void addRun(const Runtime& rt);

    //output all the runs
    void seeAll() const;

    //searches for a given time and gives the user the option to remove
    void findTime(const Runtime& rt);

    //search for all of a given distance and show it
    void findDistance(double d) const;

    //sort data by time
    void sortByTime();

    //sort data by distance
    void sortByDistance();

    //return a total for the time
    MyTime findToalTime() const;

    //return a total for the distance
    double findTotalDistance() const;

    //return the average pace for all the runs
    MyTime findAveragePace() const;



    private:
    static const int CAPACITY = 200; 
    int used;
    Runtime data[CAPACITY];
};







#endif