#include <iostream>
using namespace std;
template <class T>
class OrdSingle{
    T data;
public:
    OrdSingle (int i = 0):data(i)  { }
    void Set (T el){
        data = el;
    }

    T Get (){
        return data;
    }

    bool operator > (int value){
		cout<<"OrdSingle::operator >() is called"<<endl;
        return (data > value);
    }
} ;

class Number{
public:
    int num;
	Number(int a): num(a) {}
	bool operator > (int k) {
		cout<<"Number::operator >() is called"<<endl;
		return (num > k);
	}
	void operator = (int& i) {cout<<" Number = call"<<endl;num = i;}
	//void operator = (Number& n) {cout<<"Number = Number& call"<<endl;num = n.num;}
} ;
int main (){
    OrdSingle <int> os1;
	Number n1(4);
    OrdSingle <Number> os2;
	os1.Set(10); 
	//Number n1(4);
	os2.Set(n1);
	os2.Set(5);
    if(os1 > 5)
        printf("\t os2 = %d\n",os1);
    if(os2 > 5)
        printf("\tos2 = %d\n",os2);
	system("pause");
}
