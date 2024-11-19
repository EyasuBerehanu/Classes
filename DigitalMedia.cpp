#include "DigitalMedia.h"
#include <iostream>
#include <cstring>

using namespace std;

DigitalMedia::DigitalMedia(char* t, int y) { //constructor for the DigitalMedia
    title = new char[80];  
    strcpy(title, t);  //copys t into the array
    year = y;
}

DigitalMedia::~DigitalMedia() { //destructor for the DigitalMedia
    delete[] title;  
}

char* DigitalMedia::getTitle() { //getter for the tittle
    return title;  
}

int DigitalMedia::getYear() { //getter for the year
    return year;
}
