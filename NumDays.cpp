/*
	Name: NumDays
	Copyright: 2023
	Author: Bekbol Shiribaiev
	Date: 18/11/23 21:56
	Description: This program has a class that stores work hours
	value and converts to days. 8 hours of work are equal to 1 day of work.
	Overloaded operators are demonstrated in this program.
*/

#include <iostream>
using namespace std;

// Class definition
class NumDays {
	private:
		int hours;
		float days;
		void convertTime();

	public:
		NumDays(int);
		int getHours() const;
		float getDays() const;
		void setDays(float);
		void setHours(int);
		NumDays operator + (const NumDays &);
		NumDays operator - (const NumDays &);
		NumDays operator ++ ();
		NumDays operator ++ (int);
		NumDays operator -- ();
		NumDays operator -- (int);
};

// Converting hours to days
void NumDays::convertTime() {
	days = hours * 0.125;
}

// Constructor
NumDays::NumDays(int h = 0) {
	hours = h;
	convertTime();
}

// Hours accessor
int NumDays::getHours() const {
	return hours;
}

// Days accessor
float NumDays::getDays() const {
	return days;
}

// Days mutator
void NumDays::setDays(float d) {
	days = d;
	hours = days * 8;
}

// Hours mutator
void NumDays::setHours(int h) {
	hours = h;
	convertTime();
}

// Overloaded addition operator
NumDays NumDays::operator + (const NumDays &obj) {
	NumDays sum;
	sum.hours = hours + obj.hours;
	sum.convertTime();
	return sum;
}

// Overloaded substraction operator
NumDays NumDays::operator - (const NumDays &obj) {
	NumDays diff;
	diff.hours = hours - obj.hours;
	diff.convertTime();
	return diff;
}

// Overloaded prefix increment operator
NumDays NumDays::operator ++() {
	++hours;
	convertTime();
	return *this;
}

// Overloaded postfix increment operator
NumDays NumDays::operator ++(int) {
	NumDays temp(hours);
	hours++;
	convertTime();
	return temp;
}

// Overloaded prefix decrement operator
NumDays NumDays::operator --() {
	--hours;
	convertTime();
	return *this;
}

// Overloaded postfix decrement operator
NumDays NumDays::operator --(int) {
	NumDays temp(hours);
	hours--;
	convertTime();
	return temp;
}

// Function prototypes
void printTime(const NumDays&);
void mutatorTest(NumDays&, float, int);
void addTest(NumDays&, NumDays&);
void substractTest(NumDays&, NumDays&);
void prefixIncTest(NumDays&);
void postfixIncTest(NumDays&);
void prefixDecTest(NumDays&);
void postfixDecTest(NumDays&);

// Main test driver
int main() {
	NumDays day1(12), day2(10);
	mutatorTest(day1, 10, 20);
	addTest(day1, day2);
	substractTest(day1, day2);
	prefixIncTest(day1);
	postfixIncTest(day2);
	prefixDecTest(day1);
	postfixDecTest(day2);
	return 0;
}

// Function to display hours and days
void printTime(const NumDays& obj) {
	cout << "Work hours: "
	     << obj.getHours() << endl;
	cout << "Work days: "
	     << obj.getDays() << endl;
}

// Test constructor and mutators
void mutatorTest(NumDays& obj, float day, int hours) {
	cout << "Constructor test: \n";
	printTime(obj);
	cout << endl;
	cout << "Setting days to " << day
	     << " mutator test: \n";
	obj.setDays(day);
	printTime(obj);
	cout << "Setting hours to " << hours
	     << " mutator test: \n";
	obj.setHours(hours);
	printTime(obj);
	cout << endl;
}

// Test addition operator
void addTest(NumDays& obj1, NumDays& obj2 ) {
	NumDays sum;
	cout << "Time report for total work time "
	     << "in two days \n";
	cout << "Hours worked for day one: "
	     << obj1.getHours() << endl;
	cout << "Hours worked for day two: "
	     << obj2.getHours() << endl;
	cout << "Total time \n";
	sum = obj1 + obj2;
	printTime(sum);
	cout << endl;
}

// Test substraction operator
void substractTest(NumDays& obj1, NumDays& obj2 ) {
	NumDays diff;
	cout << "Time report for difference "
	     << " work time in two days \n";
	cout << "Hours worked for day one: "
	     << obj1.getHours() << endl;
	cout << "Hours worked for day two: "
	     << obj2.getHours() << endl;
	cout << "Difference time \n";
	diff = obj1 - obj2;
	printTime(diff);
	cout << endl;
}

// Test prefix ++ operator
void prefixIncTest(NumDays& obj) {
	cout << "Before prefix increment: \n";
	printTime(obj);
	cout << "Prefix increment is in process... \n";
	printTime(++obj);
	cout << "After prefix increment: \n";
	printTime(obj);
	cout << endl;
}

// Test postfix ++ operator
void postfixIncTest(NumDays& obj) {
	cout << "Before postfix increment: \n";
	printTime(obj);
	cout << "Postfix increment is in process... \n";
	printTime(obj++);
	cout << "After postfix increment: \n";
	printTime(obj);
	cout << endl;
}

// Test prefix -- operator
void prefixDecTest(NumDays & obj) {
	cout << "Before prefix decrement: \n";
	printTime(obj);
	cout << "Prefix decrement is in process... \n";
	printTime(--obj);
	cout << "After prefix decrement: \n";
	printTime(obj);
	cout << endl;
}

// Test postfix -- operator
void postfixDecTest(NumDays & obj) {
	cout << "Before postfix decrement: \n";
	printTime(obj);
	cout << "Postfix decrement is in process... \n";
	printTime(obj--);
	cout << "After postfix decrement: \n";
	printTime(obj);
}