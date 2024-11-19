#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class DigitalMedia { //defins of the DigitalMedia
protected:
    char* title;
    int year;

public:
    DigitalMedia(); 
    DigitalMedia(char* t, int y); //constructor that takes char pointer and the int
    virtual ~DigitalMedia(); 

    char* getTitle();
    int getYear();

    virtual void displayInfo() = 0; //overridden in child classes
    //the 0 means it has to  be implemented by child class making 
    //it pure virtual function
};

#endif
