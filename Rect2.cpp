#include <iostream>
using namespace std;
class Rectangle{
	private:
		int base;
		int height;
		int x_pos;
		int y_pos;
	public:
		Rectangle(int b, int h, int x=0, int y=0):base(b),height(h),x_pos(x),y_pos(y) {}
		int Base(){
			return base;
		}
		int Height(){
			return height;	
		}
		int Perimeter(){
			return (base+height)*2;	
		}
		int Area(){
			return base*height;	
		}
		void Moves(int delta_x, int delta_y){
			x_pos+=delta_x;
			y_pos+=delta_y;	
		}
		void Scalse(float scale){
			base*=scale;
			height*=scale;	
		}
		int X() {return x_pos;}
		int Y() {return y_pos;}
		
		
};
ostream& operator <<(ostream& os, Rectangle r){
	os<<"base : "<<r.Base()<<"\theight : "<<r.Height()<<"\nArea : "<<r.Area()<<"\tPerimeter"<<r.Perimeter();
	os<<"\nx_pos : "<<r.X()<<" y_pos : "<<r.Y()<<endl;
	return os;	
}

class Square : public Rectangle{
	public:
		Square(int side, int x_pos = 0, int y_pos = 0):Rectangle(side,side,x_pos,y_pos) {asdf=0;}
		
		int Perimeter(){
			cout<<"Square::Perimeter È£Ãâ"<<endl; 
			return (Base()*4);	
		}
		
		float Diagonal(){
			return Base()*1.4142;
		}
	private:
		int asdf;
};
ostream& operator <<(ostream& os, Square sq){
	os<<(Rectangle)sq;
	os<<"\nDiagonal() : "<<sq.Diagonal()<<endl;	
	return os;
}
int main(void)
{
	Rectangle rect(10,18);
	Rectangle squ(22,22,12,35);
	cout<<"1"<<endl;
	cout<<rect;
	cout<<"2"<<endl;
	cout<<squ;
	Square squ2(33,1,2);
	cout<<"3"<<endl;
	cout<<squ2;
	return  0;	
}

