#ifndef PHOTO_H
#define PHOTO_H

#include "Date.h"

class Photo{

    friend ostream& operator<<(ostream& ost, const Photo& photo);
    
    public:
        //constructors
        Photo();
        Photo(const string& title,const string& category, const Date& dateTaken, const string& content);

        //copy constructor
        Photo(const Photo& photo);

        //destructor
        ~Photo();

        //getters
        const string& getCategory() const;
        const Date& getDateTaken() const;

        //other
        bool equals(const string& title) const;
        void print(ostream& ost) const;
        void display(ostream& ost) const;
        
    private:
        string title;
        string content;
        string category;
        const Date* dateTaken;
};

#endif