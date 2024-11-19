#include "Music.h"
#include <iostream>
#include <cstring>

using namespace std;

Music::Music(char* t, int y, char* a, char* p, int d) : DigitalMedia(t, y){ //constructor for Music that which has to refrence DigitalMedia
    title = new char[80];   
    artist = new char[80];  
    publisher = new char[80]; 

    strcpy(title, t);  
    strcpy(artist, a);
    strcpy(publisher, p);

    year = y;    
    duration = d; 
}

Music::~Music() { //destructor for the Music
    //delete[] title;  
    delete[] artist;  
    delete[] publisher;  
}

char* Music::getArtist() { //getter for the artist 
    return artist;  
}

char* Music::getPublisher() { //getter for the publisher
    return publisher;  
}

int Music::getDuration() { //getter for the duration
    return duration;  
}

void Music::displayInfo() { //how info is displayed when searched (after atrubiutes are added for music) 
    cout << "Music: (Title: " << title << " Artist: " << artist << " Year: " << year << " Publisher: " << publisher << " Duration: " << duration << " minutes)" << endl;
}
