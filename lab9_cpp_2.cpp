#include <iostream>
#include <string>
using namespace std;

class Time{

    int hours, minutes, seconds;

public:
    class TimeError{
        string message;
    public:
        TimeError(){message="Something went wrong...";}
        void printMessage(){cout << message << endl;}
    };
    Time(){
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Time(int h, int m, int s){
        if(h < 0 || m < 0 || s < 0){
            throw TimeError();
        }
        m += s / 60;
        s %= 60;
        h += m / 60;
        m %= 60;
        hours = h;
        minutes = m;
        seconds = s;
    }
    void printTime() const{
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
    static Time sumTimes(Time t1, Time t2){
        Time t3 = Time(t1.hours + t2.hours, t1.minutes + t2.minutes, t1.seconds + t2.seconds);
        return t3;
    }
};

int main(){
    try{Time t1;
        Time t2(1, 34, 70);
        Time t3 = Time::sumTimes(t1, t2);
        t1.printTime();
        t2.printTime();
        t3.printTime();}
    catch(Time::TimeError& error){
        error.printMessage();
    }
}