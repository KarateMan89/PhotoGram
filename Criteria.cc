#include "Criteria.h"

ostream& operator<<(ostream& os, const Criteria& criteria) {
    criteria.print(os);
    return os;
}

//------------------------------------------------------------------------------------------------------------------
// Constructor
Cat_Criteria::Cat_Criteria(const string& category) : category(category) {}

// getters
const string& Cat_Criteria::getCategory() const { return category; }

bool Cat_Criteria::matches(const Photo& photo) const {
    return photo.getCategory() == category;
}

void Cat_Criteria::print(ostream& os) const {
    os << "Category Criteria: matches if Photo::category == " << category;
}

//------------------------------------------------------------------------------------------------------------------
// Constructor
Date_Criteria::Date_Criteria(const Date& start, const Date& end) : start(start), end(end) {}

// Override the matches function
bool Date_Criteria::matches(const Photo& photo) const {
    const Date& photoDate = photo.getDateTaken();
    return photoDate >= start && photoDate <= end; // we override the >= and <= operators in Date
}

// getters
const Date& Date_Criteria::getStart() const { return start; }
const Date& Date_Criteria::getEnd() const { return end; }

// Override the print function
void Date_Criteria::print(ostream& os) const {
    os << "Date Criteria: matches if start <= Photo::date <= end. Start: ";
    start.print(os);
    os << ", End: ";
    end.print(os);
}

//------------------------------------------------------------------------------------------------------------------
// Constructor
CandD_Criteria::CandD_Criteria(const Date& start, const Date& end, const string& category)
    : Date_Criteria(start, end), Cat_Criteria(category) {}

// Override the matches function
bool CandD_Criteria::matches(const Photo& photo) const {
    return Date_Criteria::matches(photo) && Cat_Criteria::matches(photo);
}

// Override the print function
void CandD_Criteria::print(ostream& os) const {
    os << "Category and Date Criteria: matches if Photo::category == ";
    os << Cat_Criteria::getCategory() << " and start <= Photo::date <= end. Start: ";
    Date_Criteria::getStart().print(os);
    os << ", End: ";
    Date_Criteria::getEnd().print(os);
}