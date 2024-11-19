#include "VideoGame.h"
#include <iostream>
#include <cstring>

using namespace std;

VideoGame::VideoGame(char* t, int y, char* p, int r) : DigitalMedia(t, y) { //constructor for VideoGame that which has to refrence DigitalMedia
    title = new char[80];
    publisher = new char[80];
    strcpy(title, t);  

    strcpy(publisher, p);  

    year = y;
    rating = r;
}

VideoGame::~VideoGame() { //destructor for the VideoGame
   // delete[] title;  
    delete[] publisher;  
}

char* VideoGame::getPublisher() { //getter for the Publisher
    return publisher;  
}

int VideoGame::getRating() { //getter for the Rating
    return rating;  
}

void VideoGame::displayInfo() { //how info is displayed when searched (after atrubiutes are added for VideoGame) 
    cout << "Video Game: (Title: " << title << " Year: " << year << " Publisher: " << publisher << " Rating: " << rating << "/10)" << endl;
}
