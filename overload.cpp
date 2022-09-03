#include <iostream>
using namespace std;

struct Complex{
	int r;
	int i;
	Complex(){
		r=0;
		i=0;
	}
	
	void Add(Complex c){
		r+=c.r;
		i+=c.i;	
	}
	void Add(Complex *pc){
		r=(*pc).r;
		i=(*pc).i;	
	}
	void Add(int a, int b){
		r+=a;
		i+=b;	
	}
};

Complex Multiply(Complex c1, Complex c2){
	Complex c3;
	c3.r = c1.r*c2.r - c1.i*c2.i;
	c3.i = c1.r*c2.i + c1.i*c2.r;
	return c3;	
}

Complex Multiply(Complex c, int n){
	c.r *=n;
	c.i*=n;
	return c;	
}
