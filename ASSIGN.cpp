#include <iostream>
#include <string>
using namespace std;

class String{
	public:
		String();
		String(const String&);
		String & operator = (const String &);
		String(char*);
		
		~String();
		char* string;
};

String::String(){
	cout<<"default 생성자 호출 "<<endl;
	string = new char[10];	
	strcpy(string,7,"default");
}
String::String(char* _string){
	cout<<"parameter constructor"<<endl;
	string = new char[strlen(_string+1)];
	strcpy(string, strlen(_string + 1),_string);	
}
String::String(const String& str){
	cout<<"복사 생성자 "<<endl;
	string=new char[strlen(str.string) + 1];
	strcpy(string,strlen(str.string) + 1,str.string);	
}
String& String::operator =(const String &str){
	cout<<"재정의 호출"<<endl;
	string = new char[strlen(str.string)+1];
	strcpy(string,strlen(str.string)+1,str.string);
	return *this;
}

String::~String(){
	cout<<"소멸자"<<endl;
	delete[]string;	
}

int main(void){
	String s1;
	String s2("Programming");
	String s3(s2);
	
	cout<<"string of s1 : "<<s1.string<<endl<<endl;
	cout<<"string of s2 : "<<s2.string<<endl<<endl;
	cout<<"string of s3 : "<<s3.string<<endl<<endl;
	s1=s2;
	cout<<"string of s1 : "<<s1.string<<endl<<endl;
		
}
