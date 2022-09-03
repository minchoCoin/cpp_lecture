#include <iostream>
#include <cstdlib>
using namespace std;
template <class T>
class Bag;
template <class T>
ostream& operator <<(ostream& os, Bag<T>& b);

class Err {
public:
	virtual void print() = 0;
};
class Overflow  : public Err{
public:
	void print() { cout << "Overflow : " << endl; }
};
class Underflow : public Err {
public:
	void print() { cout << "Underflow : " << endl; }

};
class Person {
public:
	Person();
	~Person();
	Person(char*, int);
	void operator = (Person& p);
	int operator >(Person& p);
private:
	char* name;
	int age;
};
Person::Person() : age(20) { name = new char[20]; strcpy_s(name, 20, "Name"); }
Person::~Person() {}
Person::Person(char* n, int Age) : age(Age) { name = new char[20]; strcpy_s(name, 20, n); }
void Person:: operator = (Person& p) { strcpy_s(name, 20, p.name); age = p.age; }
int Person::operator >(Person& p) { return (strcmp(name, p.name) <0) ; }

template <class T>
class Bag {
public:
	Bag(int n = 10);
	~Bag();
	void Add(T elem);
	virtual T* Delete(T& elem);
	void Print();
	bool IsEmpty();
	bool IsFull();
	friend ostream& operator <<(ostream& os, Bag<T>& b);
protected:
	T* arr;
	int Top;
	int Max;
};
template <class T>
Bag<T>::Bag(int n) :Max(n), Top(0){ arr = new T[n]; }
template <class T>
Bag<T>::~Bag() {}
template <class T>
void Bag<T>::Add(T elem) {
	if (IsFull())
		throw(new Overflow());

		arr[++Top] = elem;
}

template <>
void Bag<char*>::Add(char* elem) {
	if (IsFull())
		throw(new Overflow());
	cout << "Hello11" << endl;
	arr[++Top] = elem;
}
template <class T>
T* Bag<T>::Delete(T& elem) {
	if (IsEmpty())
		throw(new Underflow());
	
	int DeletePos = rand() % Top;
	elem = arr[DeletePos];
	for (int i = DeletePos; i < Top - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	return &elem;

}
template <class  T>
bool Bag<T>::IsEmpty() { return Top == 0; }
template <class T>
bool Bag<T>::IsFull() { return Top == Max; }
template <class T>
void Bag<T>:: Print() { 
	for (int i = 0; i < Top; ++i) 
		cout << arr[i] << "\t"; 
	cout << endl;
}
template <class T>
ostream& operator << (ostream& os, Bag<T>& b) {
	b.Print();
}
template <class T>
class Stack : public Bag<T> {
public:
	Stack(int n = 10);
	~Stack();
	T* Delete(T& elem);
};
template <class T>
Stack<T>::Stack(int n)  : Bag<T>(n){}
template <class T>
Stack<T>::~Stack() {}
template <class T>
T* Stack<T>::Delete(T& elem) {
	if (Stack<T>::IsEmpty())
		throw(new Underflow());
	elem = Stack<T>::arr[Stack<T>::Top--];
}
int main(void) {
	try {
		Stack<int> s;
		s.Add(1);
		Stack<char*> e;
		e.Add(const_cast<char*>("HELLO"));
	}
	catch (Err* e) {
		e->print();
		delete e;
	}
	return 0;
}