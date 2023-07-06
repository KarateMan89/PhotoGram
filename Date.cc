
#include "Date.h"

ostream& operator<<(ostream& ost, const Date& d){
	d.print(ost);
	return ost;
}

Date::Date(){
	setDate(1901,1,1);
}

Date::Date(int y, int m, int d){
	//cout<<endl<<"in Date ctor"<<endl;
	setDate(y,m,d);
}


Date::Date(const Date& d){
	setDate(d.year,d.month,d.day);
	//cout<<endl<<"in Date COPY ctor"<<endl;
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d){
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day);
}


//getters
int Date::getDay() const{ return day; }
int Date::getMonth() const{ return month; }
int Date::getYear() const{ return year; }
string Date::getMonthName() const{
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	return months[month-1];
}

//operators
bool Date::operator>(const Date& otherDate) const {
	if (year > otherDate.year) return true;
	if (year < otherDate.year) return false;
	if (month > otherDate.month) return true;
	if (month < otherDate.month) return false;
	if (day > otherDate.day) return true;
	return false;
}

bool Date::operator<(const Date& otherDate) const {
	return !(*this > otherDate || *this == otherDate); // if this is not greater than otherDate, then it is less than otherDate
}

bool Date::operator==(const Date& otherDate) const {
	return (year == otherDate.year && month == otherDate.month && day == otherDate.day);
}

bool Date::operator<=(const Date& otherDate) const {
	return !(*this > otherDate); // if this is not greater than otherDate, then it is less than or equal to otherDate(reusing the > operator)
}

bool Date::operator>=(const Date& otherDate) const {
	return !(*this < otherDate); // if this is not less than otherDate, then it is greater than or equal to otherDate(reusing the < operator)
}


//other
void Date::incDate(){
	day += 1;
	if (day > getMaxDay()){
		day = 1;
		month += 1;
	}

	if (month > 12){
		month = 1;
		year += 1;
	}
}

void Date::addDays(int num){
	for (int i = 0; i < num; ++i){
		incDate();
	}
}

void Date::print(ostream& ost) const{
	ost << getMonthName()<<" "<<day<<", "<<year;
}

int Date::getMaxDay() const{
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

