
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date {

	friend ostream& operator<<(ostream& ost, const Date& date);

	public:
		//constructor
		Date();
		Date(int year, int month, int day);
		Date(const Date&);
		
		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(Date&);
		
		//getters
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		string getMonthName() const;

		//operators
		bool operator>(const Date& otherDate) const;
		bool operator<(const Date& other) const;
        bool operator==(const Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator>=(const Date& other) const;
		
		//other
		void incDate();
		void addDays(int);
		void print(ostream& ost) const;
		
	
	private:
		//functions
		int getMaxDay() const;	
	
		//variables
		int day;
		int month;
		int year;
	
};
#endif
