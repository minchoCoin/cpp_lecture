#include <iostream>
using namespace std;
class Test{
	private:
		int a;
		int* b;
	public:
		Test(int num1, int num2);
		Test(int num1);
		Test& operator ++();
		Test operator ++(int);
		~Test();
		Test();
		 Test& operator+(const Test& T) ;
		 Test& operator-(const Test& T) ;
		int A();
		int B();
		int operator >(Test T);
		int operator <(Test T);
		Test& operator =(const Test &T);
		friend ostream& operator <<(ostream& os, Test& T);
		friend istream& operator >>(istream& is,Test& T);
		Test(Test& T){
			a = T.a;
			b=new int;
			*b = *(T.b);	
			
		}
			
};
Test::Test(int num1 ,int num2){
	a=num1;
	b=new int;
	*b=num2;	
}
Test::Test(int num1){
	a=num1;
	b=new int;
	*b=num1;	
}
Test& Test:: operator ++(){
	(this->a)++;
	(*b)++;
	return *this;
		
}
Test Test::operator ++(int){
	Test oldOne = *this; //Test(Test& T) call 
	a++;
	(*b)++;
	return oldOne;	
}
Test::~Test(){
	delete b;	
}
Test::Test(){
	a=0;
	b=new int;
	*b=0;	
}
Test& Test::operator+(const Test& T) {
	a+=T.a;
	*b+=*(T.b);
	return *this;
}
Test& Test::operator-(const Test& T){
	a-=T.a;
	*b-=*(T.b);
	return *this;
}
int Test::A(){
	return a;	
}
int Test::B(){
	return *b;	
}
int Test::operator <(Test T){
	return (this->a + *(this->b))< (T.a + *(T.b));
}
int Test::operator >(Test T){
	return (this->a + *(this->b))> (T.a + *(T.b));
}
Test& Test:: operator =(const Test &T){
	a=T.a;
	*b = *(T.b);
	return *this;	
}

ostream& operator<< (ostream& os, Test& T){
	os<<T.a<<","<<*(T.b)<<endl;
	return os;
}
istream& operator>> (istream& is, Test& T){
	is>>T.a>>*(T.b);
	return is;
}

int main(void)
{
	Test t1(2,4);
	Test t2, t3;
	Test t4(10,10);
	t2=t1;
	cout<<t2;
	cin>>t3;
	cout<<(t1>t4)<<endl;
	cout<<(t1<t4)<<endl;
	t3 = t1 + t2 + t3;
	cout<<t3;
	t3 = t1-t2-t3;
	cout<<t3;
	t3 = Test(1);
	cout<<t3.A()<<" "<<t3.B()<<endl;
	t4 = t3++;
	cout<<t3;
	cout<<t4;
	t4=++t3;
	cout<<t4;
	return 0;
		
}
