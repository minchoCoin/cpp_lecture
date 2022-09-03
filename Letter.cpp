#include <iostream>
#include <stdlib.h>
using namespace std;

class Letters{
	private:
		char ch;
		static int num;
	public:
		Letters(char c);
		~Letters();
		char Value();
		static int Number(){
			return num;	
		}
		
};

Letters::Letters(char c):ch(c){
	num++;
	cout<<"New letter"<<c<<", the total number is"<<num<<endl;	
}

Letters::~Letters(){
	num--;
	cout<<"Letter "<<ch<<"destoryed, ";
	if(num==1)
		cout <<"1 letter remains"<<endl;
	else
		cout<<num<<"letters remain"<<endl;	
}
char Letters::Value(){
	return ch;	
}
int Letters::num=0;

int main(void)
{
	cout<<"Program begins..."<<endl;
	cout<<"Number of letters at the beginning: "<<Letters::Number()<<endl;	
	Letters A('a');
	Letters B('b');
	Letters C('c');
	Letters D('d');
	
	
}
