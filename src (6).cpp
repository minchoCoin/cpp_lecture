#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Department {
public:
	Department(string d) :depart(d) {}
	friend ostream& operator << (ostream& os, Department& d);
	friend istream& operator >> (istream& is, Department& d);
private:
	string depart;
};
ostream& operator << (ostream& os, Department& d) { os << "department : " << d.depart << endl; return os; }
istream& operator >> (istream& is, Department& d) { is >> d.depart; return is; }
class Person {
public:
	Person();
	~Person();
	Person(const string& s1, string& s2, int a);
	Person(const char* s1, const char* s2, int a);
	virtual void Insert();
	virtual void Print();
	virtual void find() = 0;
	virtual void operator  = (Person& p) { name = new string(*(p.name)); d = new Department(*(p.d)); age = p.age; }
private:
	string* name;
	Department* d;
	int age;

};
Person::Person() { name = new string("unknown"); d = new Department("unknown_company"); age = 0; }
Person::~Person() { delete name; delete d; }
Person::Person(const string& s1, string& s2, int a) { name = new string(s1); d = new Department(s2); age = a; }
Person::Person(const char* s1, const char* s2, int a) { name = new string(s1), d = new Department(s2); age = a; }
void Person::Insert() { 
	string temp;
	Department tempd("");
	cin >> temp >>tempd>> age;
	name = new string(temp);
	d = new Department(tempd);


}
void Person::Print() { cout <<"Name : "<< *name <<"\n"<< *d <<"Age : "<< age<<endl; }

class Student :virtual public Person {
public:
	Student() : Person(), id(0) {}
	Student(const string& s1, string& s2, int a, int id_value) : Person(s1, s2, a), id(id_value) {}
	Student(const char* s1, const char* s2, int a, int id_value) : Person(s1, s2, a), id(id_value) {}
	virtual void Insert() { Person::Insert(); cin >> id; }
	virtual void Print() { Person::Print(); cout << "id : " << id << endl; }
	virtual void find() { cout << "Student::find" << endl; }
	virtual void operator =(Student& p) {
		Person::operator=(p);
		id = p.id;
	}
private:
	int id;
};
class Employee : virtual protected Person {
public:
	Employee() : Person() { company = new string("unknown company"); }
	~Employee() { delete company; }
	Employee(const string& s1, string& s2, int a, string com) : Person(s1, s2, a) { company = new string(com); }
	Employee(const char* s1, const char* s2, int a, const char* com): Person(s1, s2, a) { company = new string(com); }
	virtual void Insert() { Person::Insert(); string temp; cin >> temp; company = new string(temp); }
	virtual void Insert_company() { string temp; cin >> temp; company = new string(temp); }
	virtual void Print() { Person::Print(); cout << "Company : " << *company << endl; }
	virtual void Print_company() { cout << "Company : " << *company << endl; }
	virtual void operator = (Employee& e) { Person::operator=(e); company = new string(*(e.company)); }
private:
	string* company;
};

class GradStudent : virtual protected Student {
public:
	GradStudent() : Student(), year(0) {}
	GradStudent(const char* s1, const char* s2, int a, int id_value, int year_value) :Student(s1,s2,a,id_value), year(year_value){}
	virtual void Insert() { Student::Insert(); cin >> year; }
	virtual void Print() { Student::Print(); cout << "Year : " << year << endl; }
	virtual void find() { cout << "GradStudent:: find()" << endl; }
	virtual void operator = (GradStudent& g) { Student::operator=(g); year = g.year; }
private:
	int year;
};
class StudentWorker :  public GradStudent, public Employee {
public:
	StudentWorker() : GradStudent(), Employee(){}
	StudentWorker(const char* s1, const char* s2, int a, int id, int year, const char* company) :GradStudent(s1,s2,a,id,year), Employee(s1,s2,a,company){}
	virtual void Insert() { GradStudent::Insert();Employee::Insert_company(); }
	virtual void Print() { GradStudent::Print(); Employee::Print_company(); }
	virtual void find() { cout << "StudentWorker::find()" << endl; }
	virtual void operator =(StudentWorker& s) { GradStudent::operator=(s); Employee::operator=(s); }
};
ostream& operator << (ostream& os, StudentWorker& s) {
	s.Print();
	return os;
}
ostream& operator <<(ostream& os, Person& p) {
	p.Print();
	return os;
}
template <class T, int num>
class Bag {
public:
	Bag();
	void Add(T* elem);
	virtual T* Delete(T& elem);
	bool IsEmpty();
	bool IsFull();
protected:
	int Top;
	int Max;
	T** arr;
};
template <class T, int num>
Bag<T, num>::Bag():Top(0) { arr = new T* [num]; }

template <class T, int num>
void Bag<T, num>::Add(T* elem) {
	if (IsFull()) {
		cout << "Full!" << endl;
		return;
	}
	arr[Top] = elem;
	cout << *elem << "is added" << endl;
	Top++;
		
}
template <class T, int num>
T* Bag<T, num>::Delete(T& elem) {
	if (IsEmpty()) {
		cout << "Empty!!" << endl;
		return new T();
	}
	int deletePos = rand() % Top;
	//cout << arr[deletePos] << "will deleted" << endl;
	elem = *arr[deletePos];
	for (int i = deletePos; i < Top; ++i) {
		arr[i] = arr[i + 1];
	}
	Top--;
	return &elem;
}
template <class T, int num>
bool Bag<T, num>::IsEmpty() { return Top == 0; }
template <class T, int num>
bool Bag<T, num>::IsFull() { return Top == Max - 1; }

template <class T, int num>
class Set : public Bag<T, num> {
public:
	virtual T* Delete(T& elem) {
		elem = *(Bag<T,num>::arr[--Bag<T,num>::Top]);
		return &elem;
	}
	
};
int main(void) 
{
	Set<StudentWorker,10> s_set;
	StudentWorker temp;
	StudentWorker s("name1", "depart", 26, 201512345, 2015, "company1");
	cout << "Name deart age id year company" << endl;
	s.Insert();
	s.Print();

	s_set.Add(new StudentWorker());
	s_set.Add(&s);
	s_set.Delete(temp);
	cout << "Delete::" << endl;
	cout << temp << endl;
	return 0;
}