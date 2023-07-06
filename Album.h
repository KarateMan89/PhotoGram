#ifndef ALBUM_H
#define ALBUM_H

#include "Array.h"

class Album{

    friend ostream& operator<<(ostream& ost, const Album& album);
    
    public:
        //constructor
        Album(const string& title, const string& description);

        //copy constructor(deep copy)
        Album(const Album& other);

        //destructor
        ~Album();

        //getters
        string getTitle() const;
        Photo* getPhoto(int index) const;
        int size() const;


        //add functions
        void addPhoto(Photo* photo);

        //remove functions
        Photo* removePhoto(const string& title);
        Photo* removePhoto(int index);

        //compare functions
        bool equals(const string& title) const;
        bool lessThan(const Album& alb) const;

        //toString functions
        void print(ostream& ost) const;
        void display(ostream& ost) const;

    private:
        string title;
        string description;
        Array<Photo*>* photos;
};

#endif