#include <iostream>
using namespace std;
#define COLS 5
int main(void){
	int a[COLS] = {10,11,12,13,14};
	int *pa[COLS];
	int (*ap)[COLS] =&a;	
	cout <<"<<ap 출력>>"<<endl;
	for(int i=0;i<COLS;i++){
		cout<<&a[i]<<"\t"<<&(*ap)[i]<<"\t"<<(*ap)+i<<"\t"
		<<a[i]<<"\t"<<(*ap)[i]<<"\t"<<endl;
	}
	cout <<endl;
	
	int b[2];
	int (&ar)[COLS]=a;
	cout <<"<<ar 출력>>"<<endl;
	for(int i=0;i<COLS;i++){
		cout<<"ar[i] = "<<ar[i]<<"\t"<<"*(ar+i) = "
		<<*(ar+i)<<endl;
	}
	cout <<endl;
	cout<<"ar[1] 대입 결과 출력>>"<<endl;
	cout<<"*(ar+1) = "<<*(ar+1)<<"\t" <<"*(ar+2) = "
	<<*(ar+2)<<"\t" 
	<<"ar[1] = "<<ar[1]<<"\t" <<"ar[2] = "<<ar[2]<<endl;
	
	cout<<endl<<"reference 변수 rfrn 출력>>"<<endl;
	int* const&rfrn = a;
	rfrn[1] = rfrn[0] + 5;
	cout<<"&a[0] = "<<&a[0]<<"\t"<<"&a[1] = "<<&a[1]<<endl;
    cout<<"*(rfrn+1) = "<<*(rfrn+1)<<"\t" <<"rfrn[1] = "<<rfrn[1]<<endl;
    cout<<"(rfrn+1) = "<<(rfrn+1)<<"\t" <<"&rfrn[1] = "<<&rfrn[1]<<endl;
    return 0;
}
