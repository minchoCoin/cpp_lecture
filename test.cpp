#include <iostream>
using namespace std;

class Base{
	private:
		int *data;
	public:
		Base() {data = new int(0);}
		Base(int a) {data = new int(a);}
		virtual ~Base() {delete data;}
		virtual void print() {cout<<*data<<endl;}
};
ostream& operator <<(ostream& os, Base& b){
	b.print();	
	return os;
}

class derived : public Base{
	private:
		int *data2;
	public:
		derived() : Base() {data2 = new int(1);}
		derived(int a, int b) :  Base(a){data2 = new int(b);}
		virtual ~derived() {delete data2;}
		virtual void print() {Base::print(); cout<<*data2<<endl;}
};
class derived2 : public derived{
	private:
		int *data3;
	public:
		derived2() : derived() {data3 = new int(2);}
		derived2(int a, int b, int c): derived(a,b) {data3 = new int(c);}
		virtual ~derived2() {delete data3;}
		virtual void print() {derived::print(); cout<<*data3<<endl;}
};
int main(void)
{
	Base* a[10];
	a[0] = new Base();
	a[1] = new Base(10);
	a[2] = new derived();
	a[3] = new derived(100,101);
	a[4] = new derived2();
	a[5] = new derived2(11,12,13);
	
	int i;
	for(i=0;i<=5;++i)
		cout<<*(a[i])<<endl;
	return 0;
}
