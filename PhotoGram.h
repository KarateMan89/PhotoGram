#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include "View.h"
#include "Album.h"
#include "Array.h"
#include "MediaFactory.h"
#include "defs.h"

class PhotoGram{
    public:
        //constructor
        PhotoGram();

        //destructor
        ~PhotoGram();
        
        //getters
        void getPhotos(const Criteria& criteria, Array<Photo*>& photos) const;
        
        //add functions
        void addAlbum(const string& title, const string& description);
        bool addToAlbum(int index, Array<Photo*>& photos);
        bool uploadPhoto(const string& title);

        //remove functions
        bool deleteAlbum(int index);

        //toString functions that use View class
        void displayAlbum(int index, View& view) const;
        int printAlbums(View& view) const;
        void displayPhoto(int index, View& view) const;
        int printPhotos(View& view) const;

    private:
        Array<Album*> albums;
        Array<Photo*> masterPhotos;
        MediaFactory mediaFactory;
};

#endif