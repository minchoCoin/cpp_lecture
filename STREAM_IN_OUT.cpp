#include <iostream>
using namespace std;

class Person{
	ostream & operator<<(char);	
	ostream & operator<<(short);	
	ostream & operator<<(int);	
	ostream & operator<<(long);	
	ostream & operator<<(float);	
	ostream & operator<<(double);
	friend ostream& operator<<(ostream& stream, const Person &p);
	
	private:
		int idNum;
		int age;
	public:
		Person() {}
			
	
}
