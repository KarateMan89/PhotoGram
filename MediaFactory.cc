
#include "MediaFactory.h"
#include <fstream>
#include <sstream>
#include <limits>

Date MediaFactory::toDate(const string& d){
    stringstream ss;
    ss<<d;
    int year, month, day;
    ss>>year>>month>>day;
    return Date(year, month, day);
}

// 'upload' a photo 
Photo* MediaFactory::uploadPhoto(const string& t){
    ifstream mediaFile;
    mediaFile.open("media/photos.txt");
    string temp, title, date, description, category;
    stringstream content;

    // We are assuming there is at least one record.
    // TBH not a great assumption to make
    cout<<"Searching for photo title: "<<t<<endl;
    while( getline(mediaFile, title)){
        if (t == title){
            getline(mediaFile, category);
            getline(mediaFile, date);
            getline(mediaFile, temp);
            while (temp!="!!endrecord!!"){
                content<<temp<<endl;
                getline(mediaFile, temp);
            }
            mediaFile.close();
            return new Photo(title, category, toDate(date), content.str());
        }

        // wrong title, advance to next photo
        while (temp!="!!endrecord!!"){
            getline(mediaFile, temp);
        }
    }

    mediaFile.close();
    return nullptr;
}

// create Criteria
Criteria* MediaFactory::dateCriteria(const Date& start, const Date& end){
    return new Date_Criteria(start, end);
}
Criteria* MediaFactory::categoryCriteria(const string& cat){
    return new Cat_Criteria(cat);
}
Criteria* MediaFactory::dateAndCatCriteria(const Date& start, const Date& end, const string& cat){
    return new CandD_Criteria(start, end, cat);
}

Album* MediaFactory::createAlbum(const string& title, const string& description){
    return new Album(title, description);
}