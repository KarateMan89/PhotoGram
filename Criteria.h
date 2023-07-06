#ifndef CRITERIA_H
#define CRITERIA_H

#include "Photo.h"
#include <iostream>

using namespace std;

class Criteria {

    friend ostream& operator<<(ostream& os, const Criteria& criteria);

public:
    virtual bool matches(const Photo& photo) const = 0;
    virtual void print(ostream& os) const = 0;

};

class Cat_Criteria: public virtual Criteria {
    public:
        // Constructor
        Cat_Criteria(const string& category);
        
        //getters
        const string& getCategory() const;

        //virtual functions
        bool matches(const Photo& photo) const override;
        void print(ostream& os) const override;

    private:
        string category;
};

class Date_Criteria : public virtual Criteria {
    public:
        // Constructor
        Date_Criteria(const Date& start, const Date& end);

        //getters
        const Date& getStart() const;
        const Date& getEnd() const;

        //virtual functions
        bool matches(const Photo& photo) const override;
        void print(ostream& os) const override;

    private:
        Date start;
        Date end;
};


class CandD_Criteria : public Date_Criteria, public Cat_Criteria {
    public:
        // Constructor
        CandD_Criteria(const Date& start, const Date& end, const string& category);

        // Override the matches and print functions
        bool matches(const Photo& photo) const override;
        void print(ostream& os) const override;

        //no members(we inherit from Date_Criteria and Cat_Criteria)
};

#endif