#include <iostream>
using namespace std;

int main(void){
	int i1=5;
	int i2=10;
	int i3=15;
	int i4=20;
	int *pi=&i1;
	const int* pc_a = &i2;
	const int* pc_b = &i2;
	int* const cp_a = &i3;
	int* const cp_b = &i3;
	const int* const cpc_a = &i4;
	const int* const cpc_b = &i4;
	
	cout << "�ʱⰪ"<<endl;
	cout <<"*pi : "<<*pi<<"\t"<<"*pc_a : "<<*pc_a<<"\t";
	cout << "*cp_a : "<<*cp_a<<"\t"<<"*cpc_a : "<< *cpc_a<<endl<<endl;
	
	//pi=pc_a;	
	pc_a=pi;//int*->const int* 
	pi=cp_a;//int* const ->int*
	
}
