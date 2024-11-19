#include "Movie.h"
#include <iostream>
#include <cstring>

using namespace std;

Movie::Movie(char* t, int y, char* d, int dur, int r) : DigitalMedia(t, y){ //constructor for Movie that which has to refrence DigitalMedia
    title = new char[80];
    strcpy(title, t); 

    year = y;

    director = new char[80];
    strcpy(director, d); 

    duration = dur;
    rating = r;
}

Movie::~Movie() {  //destructor for the Movie
    
    delete[] director;
}

char* Movie::getDirector() { //getter for the director
    return director;
}

int Movie::getDuration() { //getter for the duration
    return duration;
}

int Movie::getRating() { //getter for the rating
    return rating;
}

void Movie::displayInfo() { //how info is displayed when search after atrubiutes are added for movie
    cout << "Movie: (Title: " << title << ", Year: " << year << ", Director: " << director << ", Duration: " << duration << " minutes"<< ", Rating: " << rating << "/10)" << endl;
}
