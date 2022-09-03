#include <iostream>
using namespace std;

class parent{
	public:
	parent();
	~parent();
	virtual void print() {cout<<"hello!"<<endl;}
	private:
		int elem;
};
parent::parent() : elem(0) {}
parent::~parent() {}

class child : protected parent{

	public:
		child();
		~child();
		void print() {cout<<"nice to meet you!"<<endl;}
	private:
		int elem2;	
};
child::child() : parent(), elem2(1) {}
child::~child() {}
int main(void)
{
	parent* p;
	p = reinterpret_cast<parent*>(new child());
	p->print();
}
