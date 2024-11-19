#ifndef MOVIE_H
#define MOVIE_H

#include "DigitalMedia.h"
#include <cstring>
#include <iostream>

class Movie : public DigitalMedia { //defins Movie and calls back to parentDigitalMedia
protected:
    char* director;
    int duration; 
    int rating;   

public:
    Movie(); 
    Movie(char* t, int y, char* d, int dur, int r); //constructor for all the charateristics of Movie
    virtual ~Movie(); //destructor for the Movie letting be destoryed if chosen to delete

    char* getDirector() ;
    int getDuration() ;
    int getRating() ;

    void displayInfo() override; //override lets displayInfo be overiden by parent class
};

#endif
