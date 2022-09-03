#include <iostream>
#include <cstring>
using namespace std;
bool compare(char* a, char* b);

template <class T>
bool compare(T a, T b){
	return a<b;	
}

template <>
bool compare(char* a, char* b){
	return strcmp(a,b);	
}
int main(void){
	cout<<compare(1.1,2.2);
	cout<<compare(1,1);
	cout<<compare("hello","abc");
}
