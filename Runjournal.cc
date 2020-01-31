/*
Josh Mencsik
30 January 2020

The implementation of the Runjournal class
*/
#include<iostream>
#include<cctype>
#include "Runjournal.h"

using namespace std;

Runjournal::Runjournal() {
    used = 0;
}

void Runjournal::record(const Runtime& rt) {
    data[used] = rt;
    used++;
}

void Runjournal::display() const {
    for (int i = 0; i < used; i++) {
        cout << data[i] << endl;
    }
}

//IN PROGRESS
void Runjournal::find_remove(const Runtime& rt) {
    char option;
    for (int i = 0; i < used; i++) {
        //find the match
        if (data[i] == rt) {
            cout << data[i] << " Pace: " << data[i].pace() <<endl;
            cout << "Would you like to remove this entry? y/n";
            cin >> option; 
            //if yes, then shift all the rt's down 
            if (tolower(option) == 'y') {
                for(int j = i; j < used - 1; j++) {
                    data[j] = data[j+1];
                }
                used--;
                //you'll have one floating outside the used
                //but it should be changed when the next one is added
            }
            return;
        }
    }
}

void Runjournal::distance_view(double d) const {

    for (int i = 0; i < used; i++) {
        if (data[i].distance_equal(d)) {
            cout << data[i] << endl;
        }
    }
}

void Runjournal::distance_sort() {
    double min;
    Runtime tmp;

    for (int i = 0; i < used; i++) {
        min = data[i].get_distance();
        for (int j = i + 1; j < used; j++) {
            if (min > data[j].get_distance()) {
                tmp = data[i];
                data[i] = data[j];
                data [j] = tmp;
            }
        }
    }
}

void Runjournal::time_sort() {
    MyTime min;
    Runtime tmp;
    for (int i = 0; i < used; i++) {
        min = data[i].get_time();
        for (int j = i + 1; j < used; j++) {
            if (data[j].get_time() < min) {
                tmp = data[i];
                data[i] = data[j];
                data [j] = tmp;
            }
        }
    }
}

MyTime Runjournal::total_time() const {
    MyTime total;
    for (int i = 0; i < used; i++) {
        total = total + data[i].get_time();
    }
    return total;
}

double Runjournal::total_distance() const {
    double total = 0;
    for (int i = 0; i < used; i++) {
        total += data[i].get_distance();
    }
    return total;
}

MyTime Runjournal::average_pace() const {
    MyTime average;
    for (int i = 0; i < used; i++) {
        average = average + data[i].pace();
    }
    return average / used;
}


