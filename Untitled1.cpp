#include <iostream>
using namespace std;
class Base{
public:
	Base(int elem) :a(elem){}
	virtual void print() {cout<<"a : "<<a<<endl;};	
protected:
	int a;
};
class Derived : public Base{
public:
	Derived(int elem) : Base(elem) {}
	void print() {cout<<"a_dervied : "<<a<<endl;}	
};
int main(void)
{
	Base* b = new Derived(3);
	b->print();
	//b= Derived(3);
}
