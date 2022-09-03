#include <iostream>
using namespace std;
class A{
	private:
		int n;
	public:
		A(int num):n(num) {}
		int Read() const{
			cout<<"Read::n ="<<n<<endl;	
			return n;
		}
		int change(int num){
			cout<<"change()::n = "<<n<<endl;
			n=num;	
			return 1;
		}
};

int main(void)
{
	A a1(5);
	a1.change(10);
	a1.Read();
	
	const A a2(8);
	//a2.change(6);
	a2.Read();
	return 0;	
}
