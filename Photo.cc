#include "Photo.h"

ostream& operator<<(ostream& ost, const Photo& photo) {
    photo.print(ost); // this will add the title, category, and dateTaken to ost using the print function
    return ost;
}

//default constructor
Photo::Photo() : title("No title"){
    content = "No content";
    dateTaken = new Date();
}

//constructor
Photo::Photo(const string& title, const string& category, const Date& dateTaken, const string& content)
    : title(title), category(category), dateTaken(new Date(dateTaken)), content(content) {}

//copy constructor
Photo::Photo(const Photo& photo)
    : title(photo.title), category(photo.category), dateTaken(new Date(*photo.dateTaken)), content(photo.content) {}

//destructor
Photo::~Photo() { delete dateTaken; }

//getters
const string& Photo::getCategory() const { return category; }
const Date& Photo::getDateTaken() const { return *dateTaken; }

//other
bool Photo::equals(const string& title) const { return this->title == title; }

void Photo::print(ostream& ost) const {
    ost << "Title: " << title << endl;
    ost << "Category: " << category << endl;
    ost << "Date Taken: ";
    dateTaken->print(ost);
    ost << endl;
}

void Photo::display(ostream& ost) const {
    print(ost);
    ost << content << endl;
}