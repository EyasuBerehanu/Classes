// Eyasu Berehanu 
// 11/18/2024
// This is a program that stores searches and deltes diffrent forms of media (Video Games, Movies and Music)
// Help From: 
// C++ - Programming Language | Tutorial Playlist - https://www.youtube.com/watch?v=rNa_aobriXo, C++ CRUDS - https://www.youtube.com/watch?v=xNJLe3m03Y4
// Virtual Destructor - https://www.geeksforgeeks.org/virtual-destructor/, Pure Virtual Functions/Abstract Classes - https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
// https://stackoverflow.com/questions/25757350/what-should-go-in-my-header-file-in-c, C++ Header Files & Inheritance Review

#include <iostream>
#include <vector>
#include <memory>
#include <cstring> 
//#include <iomanip> 

#include "VideoGame.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

//Function Prototypes allow code to read these funtions even if not at top
void add(vector<DigitalMedia*>& mediaData);
void search(const vector<DigitalMedia*>& mediaData);
void deletee(vector<DigitalMedia*>& mediaData);

//Prompts the user with diffrent options
void menu() {
    cout << "Enter Add, Search, Delete, or Quit " << endl;
}

//main recives the inputed responses and respond accorinding running
// the add funtion if add is type in a so on.
int main() {
    vector<DigitalMedia*> mediaData; 
    char choice[80];
    bool start = true;
    
    menu();
    while(start) { //while stament used to allow Quit to stop the project
        cin.getline(choice, 80);
        if(strcmp(choice, "Add") == 0) {
            add(mediaData);
        } 
        else if (strcmp(choice, "Search") == 0) {
            search(mediaData);
        }
        else if (strcmp(choice, "Delete") == 0) {
            deletee(mediaData);
        }
        else if (strcmp(choice, "Quit") == 0) {
            start = false; 
        }
       // else {
          //  cout << "Invalid choice so try again." << endl;
           // menu();
        //}
    }

    
    for (size_t i = 0; i < mediaData.size(); ++i) { //this helps clean up and make sure theres no memory leaks
        delete mediaData[i];  
    }
        mediaData.clear();
    
}

void add(vector<DigitalMedia*>& mediaData) { //adds media according to the chosen tyoe and attributes, This data is then stored until deltion
    char type[20];
    cout << "Do you want to add info for Video Game, Music, or Movie: " << endl;
    //cin.ignore();
    cin.getline(type, 20);
    
    if (strcmp(type, "Video Game") == 0) { //contains importantion asked regarding if you chose video games
        char title[80];
        char publisher[80];
        int year;
        int rating;

        cout << "Title: " << endl; 
        cin.getline(title, 80);  
        
        cout << "Year: " << endl; 
        cin >> year;  
        cin.ignore(); 
        
        cout << "Publisher: " << endl; 
        cin.getline(publisher, 80); 
        
        cout << "Rating (1-10): " << endl; 
        cin >> rating; 
        cin.ignore(); 
        
        mediaData.push_back(new VideoGame(title, year, publisher, rating));  
        cout << "Added Video Game: " << title << endl; //This was just for dubugging data was acutally storing
        menu();
        
    } else if (strcmp(type, "Music") == 0) { //contains importantion asked regarding if you chose music
        char title[80]; 
        char artist[80]; 
        char publisher[80];
        int year;
        int duration;
        
        cout << "Title: " << endl; 
        cin.getline(title, 80);  
        
        cout << "Year: " << endl; 
        cin >> year;
        
        cout << "Artist: " << endl;
        cin.ignore(); 
        cin.getline(artist, 80);
        
        
        cout << "Publisher: " << endl; 
        cin.getline(publisher, 80);  
        
        
        cout << "Duration in Min: " << endl;
        cin >> duration;

        mediaData.push_back(new Music(title, year, artist, publisher, duration));
        cout << "Added Music: " << title << endl; //This was just for dubugging data was acutally storing
        //menu();
        
    }
    else if (strcmp(type, "Movie") == 0) { //contains importantion asked regarding if you chose movie
        char title[80]; 
        char director[80];
        int year; 
        int duration; 
        int rating;
        
        cout << "Title: " << endl; 
        cin.getline(title, 80);
        
        cout << "Year: " << endl; 
        cin >> year;
        
        cout << "Director: " << endl; 
        cin.ignore(); 
        cin.getline(director, 80);
        
        cout << "Duration (minutes): " << endl; 
        cin >> duration;
        
        cout << "Rating (1-10): " << endl; 
        cin >> rating;

        mediaData.push_back(new Movie(title, year, director, duration, rating));
        cout << "Added Movie: " << title << endl; //This was just for dubugging data was acutally storing
        menu();
        
    }
    else {
        cout << "Invalid type.\n" << endl;;
        menu();
    }
    
    
}

void search(const vector<DigitalMedia*>& mediaData) { //searchs throught the stored data using key words or numbers used in the search 
    char choice[80];
    cout << "Search by Title or Year (Type it in to choose): ";
    cin.getline(choice, 80);

    bool found = false;

    if (strcmp(choice, "Title") == 0) { // title is one of the options of searching methods
        char keyword[80];
        cout << "Enter title to search: ";
        cin >> ws;  
        cin.getline(keyword, 80);

        for (DigitalMedia* media : mediaData) {
            if (strcmp(media->getTitle(), keyword) == 0) {  
                media->displayInfo();
                found = true;
            }
        }
    } else if (strcmp(choice, "Year") == 0) { //year is the other option of searching methods
        int keyyear;
        cout << "Enter year to search: ";
        cin >> keyyear;

        for (DigitalMedia* media : mediaData) {
            if (media->getYear() == keyyear) {  
                media->displayInfo();
                found = true;
            }
        }
    } else {
        cout << "Invalid choice try a difftrent command.\n";
        return;  
    }

    if (!found) { // if no search was found this will pop up
        cout << "Search not found.\n";
    }
}

void deletee(vector<DigitalMedia*>& mediaData) { //This function lets the user to delete one of the media item from the vector
    char keyword[80];
    
    cout << "Enter title to delete: ";
    cin >> ws;  
    cin.getline(keyword, 80);  

    for (size_t i = 0; i < mediaData.size(); ++i) { //  iterates through the mediaData vector to find a media  that matches the title entered
                                                    // vector contains pointers to DigitalMedia objects like video game, music, or movie
        if (strcmp(mediaData[i]->getTitle(), keyword) == 0) {  
            mediaData[i]->displayInfo();  
            
            char confrim[80];
            cout << "Are you sure you want to delete this? (Yes/No): ";
            cin >> confrim;
            
            if (strcmp(confrim, "Yes") == 0) {
                delete mediaData[i];  
                mediaData.erase(mediaData.begin() + i);  //decreasing the size of the vector by one or the i idenx deleting the the media from the vector and also the memory
                cout << "Item deleted.\n";
                return;  
            } else {
                cout << "Deletion failed.\n";
                return;  
            }
        }
    }

    cout << "Nothing matches with your serach.\n";  
}
