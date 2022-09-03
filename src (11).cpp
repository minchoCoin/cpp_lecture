#include <iostream>
#include <cstring>
using namespace std;
template <class T>
class Bag;
template <class T>
ostream& operator <<(ostream& os, Bag<T>& b);
class Err {
public:
	virtual void print() = 0;
};
class Overflow : public Err {
public:
	void print() { cout << "Overflow" << endl; }
};
class Underflow : public Err {
public:
	void print() { cout << "Underflow" << endl; }
};
template <class T>
class Bag {
public:
	Bag(int num =10);
	~Bag();
	void Add(T elem);
	virtual T* Delete(T& elem,int pos = -1);
	virtual void Print();
	bool IsFull() { return top == Max; }
	bool IsEmpty() { return top == 0; }
	friend ostream& operator << (ostream& os, Bag<T>& b);
private:
	T* collection;
	int top;
	int Max;
};
template <class T>
ostream& operator <<(ostream& os, Bag<T>& b) { b.Print(); }
template <class T>
Bag<T>::Bag(int num) : top(0),Max(num) { collection = new T[num]; }
template <class T>
Bag<T>::~Bag() {}
template <class T>
void Bag<T>::Add(T elem) {
	if (IsFull())
		return;
	collection[top++] = elem;
}
template <class T>
T* Bag<T>::Delete(T& elem, int pos) {
	int deletePos;
	if (IsEmpty())
		return new T();
	if (pos == -1)
		deletePos = rand() % top;
	else
		deletePos = pos;
	elem = collection[deletePos];
	for (int i = 0; i < top - 1; ++i)
		collection[i] = collection[i + 1];
	return &elem;
}
template <class T >
void Bag<T>::Print() { for(int i = 0;i<top;++i) cout << Bag<T>::collection[i] << endl; }

template <class T>
class Queue : public Bag<T> {
public:
	Queue(int num = 10);
	~Queue();
	T* Delete(T& elem,int pos);

};
template <class T>
Queue<T>::Queue(int num)  : Bag<T>(num){}
template <class T>
Queue<T>::~Queue() {}
template <class T>
T* Queue<T>::Delete(T& elem, int pos) {
	Bag<T>::Delete(elem, 0);
	return &elem;
}
class Person {
public:
	Person(const char* name, int age);
	void operator = (Person p);
	bool operator == (Person p);
protected:
	char Name[20];
	int Age;
};
Person::Person(const char* name = "hello", int age = 20) : Age(age) { strcpy_s(Name, 20, name); }
void Person::operator=(Person p) { strcpy_s(Name, 20, p.Name); Age = p.Age; }
bool Person::operator==(Person p) { return ( strcmp(Name, p.Name) == 0 )&& (Age = p.Age); }
class Student : public Person {
public:
	Student(const char* name, int age, int id);
	void operator = (Student s);
	bool operator == (Student p);
	friend ostream& operator << (ostream& os, Student& s);
private:
	int ID;
};
ostream& operator << (ostream& os, Student& s) {
	os << s.Name << " " << s.Age << " " << s.ID;
	return os;
}
Student::Student(const char* name = "hello2", int age = 20, int id = 2019) :Person(name,age),ID(id){

}
void Student::operator=(Student s) {
	Person::operator=(s);
	ID = s.ID;
}
bool Student::operator ==(Student s) {
	bool a = Person::operator==(s);
	return a&& (ID = s.ID);
}
int main(void) {
	Queue<Student> qs(10);
	qs.Add(Student("name", 20, 2019));
	cout << qs;
}