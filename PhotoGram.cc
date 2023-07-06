#include "PhotoGram.h"

//constructor
PhotoGram::PhotoGram(){}

//destructor
PhotoGram::~PhotoGram(){
    for (int i = 0; i < masterPhotos.size(); ++i){
        delete masterPhotos[i];
    }
    for (int i = 0; i < albums.size(); ++i){
        delete albums[i];
    }
}

//getters
void PhotoGram::getPhotos(const Criteria& criteria, Array<Photo*>& photos) const{
    int matches = 0;
    for (int i = 0; i < masterPhotos.size(); ++i){
        if(criteria.matches(*(masterPhotos[i]))){
            matches++;
            photos.add(masterPhotos[i]);
        }
    }
    if (matches == 0){
        cerr << "No photos that match the criteria found!" << endl;
    }
}

//add functions
void PhotoGram::addAlbum(const string& title, const string& description){
    if (albums.isFull()){
        cerr << "Not enough space for new Albums. Album not added!" << endl;
        return;
    }
    Album* album = mediaFactory.createAlbum(title, description);
    albums.add(album);
}

bool PhotoGram::addToAlbum(int index, Array<Photo*>& photos){
    //range check
    if (index < 0 || index >= albums.size()){
        cerr << "Album not found!" << endl;
        return false;
    }
    //check if album is full or will be full
    if(albums.size() + photos.size() > MAX_ARRAY){
        cerr << "Photos not added to album!" << endl;
        return false;
    }
    //add photos to album
    for (int i = 0; i < photos.size(); ++i){
        albums[index]->addPhoto(photos[i]);
    }
    return true;
}

bool PhotoGram::uploadPhoto(const string& title){
    // check if masterPhotos is full
    if(masterPhotos.isFull()){
        cerr << "Master list full. Photo not added!" << endl;
        return false;
    }
    //create photo
    Photo* photo = mediaFactory.uploadPhoto(title);

    //add photo to masterPhotos
    masterPhotos.add(photo);

    return true;
}

//remove functions
bool PhotoGram::deleteAlbum(int index){
    //range check
    if(index < 0 || index >= albums.size()){
        cerr << "Cannot delete album. Index out of bounds!" << endl;
        return false;
    }
    //delete album
    Album* album = albums[index];
    albums.remove(album);
    delete album;
    return true;
}

//toString functions that use View class
void PhotoGram::displayAlbum(int index, View& view) const{
    //range check
    if(index < 0 || index >= albums.size()){
        cerr << "Cannot display album. Index out of bounds!" << endl;
        return;
    }
    //display album
    view.displayAlbum(*albums[index]);
}

int PhotoGram::printAlbums(View& view) const {
    if(albums.size() == 0){
        cerr << "No albums to print!" << endl;
        return 0;
    }
    view.printAlbums(albums);
    return albums.size();
}

void PhotoGram::displayPhoto(int index, View& view) const{
    //range check
    if(index < 0 || index >= masterPhotos.size()){
        cerr << "Cannot display photo. Index out of bounds!" << endl;
        return;
    }
    //display photo
    view.displayPhoto(*(masterPhotos[index]));
}

int PhotoGram::printPhotos(View& view) const {
    if(masterPhotos.size() == 0){
        cerr << "No photos to print!" << endl;
        return 0;
    }
    view.printPhotos(masterPhotos);
    return masterPhotos.size();
}

