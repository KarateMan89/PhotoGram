#include "Album.h"

ostream& operator<<(ostream& ost, const Album& album) {
    album.print(ost);
    return ost;
}

//constructor
Album::Album(const string& title, const string& description) 
    //dynamically allocate memory for a new Array<Photo*>
    : title(title), description(description), photos(new Array<Photo*>()) {}

//destructor
Album::~Album() { delete photos; } // delete only the array of photos not the photos themselves

//getters
string Album::getTitle() const { return title; }
Photo* Album::getPhoto(int index) const { return photos->get(index); }
int Album::size() const { return photos->size(); }

//add functions
void Album::addPhoto(Photo* photo) { photos->add(photo); }

//compare functions
bool Album::equals(const string& title) const { return this->title == title; }

//toString functions
void Album::print(ostream& ost) const {
    ost << "Album: " << title << endl;
    ost << "Description: " << description << endl;
}

void Album::display(ostream& ost) const {
    print(ost);
    //Photos know how to print themselves
    for(int i = 0; i < size(); ++i){
        cout << "Photo " << i << ":" << endl;
        getPhoto(i)->display(ost);
    }
}