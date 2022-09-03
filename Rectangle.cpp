#include <stdlib.h>
#include <iostream>
using namespace std;
class Rectangle{
	public:
		Rectangle() {};
		Rectangle(int x, int y, int h, int b);
		~Rectangle();
		int Height();
		int Base();
		int Perimeter();
		int Area();
		
		int operator==(const Rectangle& s);
		friend ostream& operator<< (ostream& os, Rectangle& r);
		
	private:
		int x_pos, y_pos, height, base;	
};
Rectangle::Rectangle(int x, int y, int h, int b)
	:x_pos(x), y_pos(y), height(h), base(b)
	{}
Rectangle::~Rectangle() {}
int Rectangle::Height() {return height;}
int Rectangle::Base() {return base;}
int Rectangle::Perimeter(){return 2*(height+base);}
int Rectangle::Area(){return height*base;}
int Rectangle::operator==(const Rectangle &s)
{
	if(this==&s) return 1;
	else if((x_pos==s.x_pos)&&(y_pos==s.y_pos)&&(height==s.height)&&(base==s.base)) return 1;
	return 0;	
}
ostream& operator<< (ostream& os, Rectangle& r)
{
	os<<"Position is: ("<<r.x_pos<<", "<<r.y_pos<<") :: ";
	os<<"Height is: "<<r.height<<" and Base is: "<<r.base<<endl;
	return os;
}	
int main(void)
{
	Rectangle a(2,3,5,6), b(2,3,5,5);
	Rectangle *c=&b;
	cout<<a<<b;
	if(a.Area()>c->Area()){
		cout<<a;
	}		
	else
		cout<<b;
	cout<<"가 더 넓은 면적을 가짐"<<endl;
	if(a==b)
		cout<<"a와 b 같음"<<endl;
	else
		cout<<"a와 b 다름"<<endl; 
}
