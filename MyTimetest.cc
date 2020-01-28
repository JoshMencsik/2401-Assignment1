#include<iostream>
#include "MyTime.h"
using namespace std;

int main(){
    double dist;
    MyTime tm;
    MyTime pace;
    cout<<"Enter your time in the format h:m:s - ";
    cin>>tm;
    cout<<"Enter your distance -  ";
    cin>>dist;
    pace = tm / dist;
    cout<<"Your average pace was: "<<pace<<endl;

return 0;
}
