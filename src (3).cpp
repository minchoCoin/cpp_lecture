#include <iostream>
#include <cstring>
using namespace std;

class Err {
public:
	virtual void print()=0;
};
class overflow : public Err {
public:
	void print() { cout << "Overflow Error" << endl; }
};
class underflow : public Err {
public:
	void print() { cout << "underflow Error" << endl; }
};
class typeErr : public Err {
public:
	void print() { cout << "different Type" << endl; }
};
class Person {
public:
	Person();
	Person(const char* n, int age);
	~Person();
	virtual void Print();
	virtual void find() = 0;
	friend ostream& operator<< (ostream& os, Person& p);
	Person& operator = (Person& p);
private:
	char Name[20];
	int Age;
};
Person::Person() : Age(20) { strcpy_s(Name, 20,"Name"); }
Person::Person(const char* n, int age) : Age(age) { strcpy_s(Name,20,n); }
void Person::Print() { cout << "Name : " << Name << " Age : " << Age << endl; }
Person::~Person() {}
ostream& operator << (ostream& os, Person& p) { p.Print(); return os; }
Person& Person::operator=(Person& p) { strcpy_s(Name, 20, p.Name); Age = p.Age; return *this; }

class Student :public Person {
public:
	Student();
	Student(const char* n, int age, int id);
	~Student();
	void Print();
	void find();
	char* Key() { return key; }
	Student& operator = (Student& s);
private:
	int ID;
	char key[10];
};
Student::Student() : Person(), ID(201912345) { strcpy_s(key, 10, "Student"); }
Student::Student(const char* n, int age, int id) :Person(n,age), ID(id){ strcpy_s(key, 10, "Student"); }
Student::~Student() {}
void Student::Print() { Person::Print(); cout << "ID : " << ID << endl; }
void Student::find() { return; }
Student& Student::operator=(Student& s) { Person::operator=(s); ID = s.ID; return *this; }

class Employee : protected Person {
public:
	Employee();
	Employee(const char* n, int age, const char* company);
	~Employee();
	void Print();
	void find();
	char* Key() { return key; }
	Employee& operator = (Employee& e);
private:
	char Company[30];
	char key[10];
};
Employee::Employee() :Person() { strcpy_s(Company, 30, "Company"); strcpy_s(key, 10, "Employee"); }
Employee::Employee(const char* n, int age, const char* company) : Person(n, age) { strcpy_s(Company, 30, company); strcpy_s(key, 10, "Employee");}
Employee::~Employee() {}
void Employee::Print() { Person::Print(); cout << "Company : " << Company << endl; }
void Employee::find() { cout << "Company::find()"<<endl; }
Employee& Employee:: operator  = (Employee& e) { Person::operator=(e); strcpy_s(Company, 30, e.Company); return *this; }

template <class T>
class Stack {
public:
	Stack(int n = 10);
	T* Push(T elem);
	T* Pop(T& elem);
	bool IsEmpty();
	bool IsFull();
	int Top();
private:
	T* arr;
	T type;
	int top;
	int Max;
};
template <class T>
Stack<T>::Stack(int n) :Max(n), top(0){ arr = new T[n]; }
template <class T>
T* Stack<T>:: Push(T elem) {
	if (IsFull()) {
		throw(overflow());
	}
	if (strcmp(type.Key(),elem.Key())!=0) {
		throw(typeErr());
	}
	arr[++top] = elem;
	return NULL;
}
template <class T>
T* Stack<T>::Pop(T& elem) {
	if (IsEmpty()) {
		throw(underflow());
	}
	elem = arr[--top];
	return &elem;
}
template <class T>
int Stack<T>::Top() { return top; }
template <class T>
bool Stack<T>::IsEmpty() { return top == 0; }
template <class T>
bool Stack<T>::IsFull() { return top == Max; }
int main(void) {
	Stack<Student> s(10);
	Student ss;
	try {
		s.Push(Student());
		s.Push(Student("Stu",20,2019));
		s.Push(Student("Stu2", 21, 2018));
		s.Pop(ss);
		cout << ss;
		return 0;
	}
	catch(Err& a){
		a.print();
	}
	
}