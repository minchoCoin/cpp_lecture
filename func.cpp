#include <iostream>
using namespace std;
int Triple1(int number){
	return number *3;	
}

class Number{
	private:
		int n;
	public:
		Number(int num):n(num) {}
		void Triple2() {
			n*=3;
		}
		int value(){
			return n;	
		}
		static int Triple3(int num){
			return num*3;	
		}
};

int main(void)
{
	int intNum = 5;
	Number objNum(5);
	int triple;
	
	cout<<"function result"<<endl;
	triple = Triple1(intNum);
	cout<<triple<<endl;
	objNum.Triple2();
	cout<<objNum.value()<<endl;
	cout<<Number::Triple3(5)<<endl;
		
}
