#include <iostream>
using namespace std;

class Date{
	int month;
	int day;
	int year;
	public:
	Date(int m, int d, int y):month(m), day(d),year(y) {}
	Date():month(1), day(1),year(1900) {}
	int Day();
	int Month();
	int Year();
	int LeapYear();
	void printDate();
	int operator>(Date d);	
	Date& operator++(){
		day++;
		return *this;	
	}
	Date& operator++(int){
		day++;
		return *this;
	}
	friend ostream& operator <<(ostream& os, Date& d);
};
int Date::Day(){return day;}
int Date::Month() {return month;}
int Date::Year() {return year;};
int Date::LeapYear(){
	return 1;	
}
void Date::printDate(){
	cout<<day<<"/"<<month<<"/"<<year<<endl;	
}

int Date::operator>(Date d){
	if(year == d.year){
		if(month == d.month){
			return day>d.day;
		}
		else
			return month>d.month;	
	}
	else
		return year>d.year;
}
ostream& operator <<(ostream&os, Date& d){
	d.printDate();
	//os<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
	return os;	
}
int main(void){
	Date d1(1,1,2000);
	Date d2(1,2,2000);
	d1.printDate();
	d2.printDate();
	cout<<(d1>d2)<<endl;
	cout<<d1++<<endl;
	cout<<++d2<<endl;
}
