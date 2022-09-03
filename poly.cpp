#include <iostream>
using namespace std;

class abs{
	protected:
		int a;
		int b;
	public:
		abs(int a1, int b1):a(a1),b(b1) {}
		int Areturn(){
			cout<<"abs::Areturn() : "<<a<<endl;
			return a;	
		}
		virtual void print()=0;	
};
class A:public abs{
	
	protected:
		int c;
	public:
		A(int a1, int b1, int c1) : abs(a1,b1),c(c1) {}
	    void print() {
			cout<<"A::print() : "<<a<<" "<<b<<endl;	
		}
	    void print_ver2(){
			cout<<"A::print_abc() : "<<a<<" "<<b<<" "<<c<<endl;
		}
			
};

class B:public A{
	
	protected:
		int d;
	public:
		B(int a1, int b1, int c1, int d1) : A(a1,b1,c1), d(d1) {}
		void print(){
			cout<<"B::print() : "<<a<<" "<<b<<endl;	
		}
		void print_ver2(){
			cout<<"B::print_abc() : "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;	
		}
};
int main(void)
{
	A a(1,2,3);
	B b(10,11,12,13);
	A a2(11,22,33);
	A *a3 = new A(9,10,11);
	abs *c;
	
	a.Areturn();
	b.Areturn();
	a3->Areturn();
	
	a.print();
	b.print();
	a3->print();
	
	a.print_ver2();
	b.print_ver2();
	a3->print_ver2();
	cout<<"---------------"<<endl;
	a3=new B(12,13,14,15);
	a=b;
	a.print();
	b.print();
	a3->print();
	
	a.print_ver2();
	b.print_ver2();
	a3->print_ver2();
	c=&a;
	c->print();
	
	c=&a2;
	c->print();
	
	c=&b;
	c->print();
	
	return 0;
}
