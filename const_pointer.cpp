#include <iostream>
using namespace std;

void square(const int *const width);
void square1(int *const j);
void square2(int* j);

int main(){
	int i=10;
	int *const j = &i;
	square1(&i);
	square(j);	
	cout <<"i = "<<i<<", j = "<<*j<<endl;
	
	int k=10;
	const int *const width = &k;
	square(width);
	//square1(width);
	
	int a[]={12,46,58,27};
	const int *p=a;
	//*p=10;
	//p[1]=55;
	a[1]=44;
	p++;
	int *q=a;
	//q=p;
	
	int m=10;
	const int n=20;
	int *pm=&m;
	int *const pn=&m;
	const int *const e=&m;
	//m=n;m=*pn;m=*e;
	//pm=&m; pm=&n;pm=pn; pm=e;
	
}
void square(const int* const width){
		int value;
		value = (*width) * (*width);
			
}
void square1(int *const j){
	int v;	
}
