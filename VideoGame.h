#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "DigitalMedia.h"

class VideoGame : public DigitalMedia { //defins VideoGame and calls back to parent DigitalMedia
protected:
    char* publisher;
    int rating; 

public:
    VideoGame(); 
    VideoGame(char* t, int y, char* p, int r); //constructor for all the charateristics of VideoGame
    virtual ~VideoGame(); //destructor for the VideoGame letting it be destoryed if chosen to delete

    char* getPublisher();
    int getRating();

    void displayInfo() override; //override lets displayInfo be overiden by parent class 
};

#endif
