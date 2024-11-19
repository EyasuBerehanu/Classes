#ifndef MUSIC_H
#define MUSIC_H

#include "DigitalMedia.h"

class Music : public DigitalMedia { //defins Music and calls back to parent DigitalMedia
protected:
    char* artist;
    char* publisher;
    int duration; 

public:
    Music(); 
    Music(char* t, int y, char* a, char* p, int d);  //constructor for all the charateristics of Music
    virtual ~Music(); //destructor for the Music letting it be destoryed if chosen to delete

    char* getArtist() ;
    char* getPublisher() ;
    int getDuration() ;

    void displayInfo() override; //override lets displayInfo be overiden by parent class
};

#endif
