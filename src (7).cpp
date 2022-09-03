#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Bag;
template <class T>
void Sort(Bag<T>& b, int num);


class Err {
public:
	virtual void print() = 0;
};
class ZeroNumber : public Err {
public:
	void print() { cout << "Zero Bag is no meaning..." << endl; }
};
class overflow : public Err {
public:
	void print() { cout << "Err : overflow" << endl; }
};

class underflow : public Err {
public:
	void print() { cout << "Err : underflow" << endl; }
};
template <class T>
class Bag {
public:
	Bag(int n = 10);
	~Bag();
	bool IsEmpty();
	bool IsFull();
	void Add(T);
	void Print();
	virtual T* Delete(T&);
	int top_value() { return Top; }
	template <class U>
	friend void Sort(Bag<U>& b, int num);
protected:
	int Max;
	int Top;
	T* arr;
};
template <class T>
class Set :public Bag<T>{
public:
	Set(int n = 10);
	~Set();
	T* Delete(T&);
	template <class U>
	friend void Sort(Bag<U>& b, int num);

};
template <class T>
Set<T>::Set(int n) :Bag<T>(n){}
template <class T>
Set<T>::~Set() {}

template <class T>
T* Set<T>::Delete(T& elem) {
	if (Bag<T>::IsEmpty())
		throw(underflow());
	//int DeletePos = --
	elem = Bag<T>::arr[--Bag<T>::Top];
	return &elem;

}
template <class T>
Bag<T>::Bag(int n) : Max(n), Top(0) {
	if (Max == 0)
		throw(ZeroNumber());
	arr = new T[n];
}

template <class T>
Bag<T>::~Bag() {}

template <class T>
bool Bag<T>::IsEmpty() { return Top == 0; }

template <class T>
bool Bag<T>::IsFull() { return Top == Max - 1; }

template <class T>
void Bag<T>::Add(T elem) {
	if (IsFull())
		throw(overflow());
	arr[Top] = elem;
	cout << elem << " is added" << endl;
	Top++;
}
template <class T>
T* Bag<T>::Delete(T& elem) {
	if (IsEmpty())
		throw(underflow());
	int target = rand() % Top;
	elem = arr[target];
	for (int i = target; i < Top - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	cout << elem << "is deleted" << endl;
	Top--;
	return &elem;
}
template <class T>
void Bag<T>::Print() {
	int i;
	for (i = 0; i < Top; ++i)
		cout << arr[i] << endl;
}

template <class T>
void Sort(T* arr, int num) {
	int temp;
	for (temp = 0; temp < num; ++temp) {
		int temp2 = temp;
		for (int temp3 = temp + 1; temp3 < num; temp3++) {
			if (arr[temp3] < arr[temp2]) {
				temp2 = temp3;
			}
		}
		T arg = arr[temp];
		arr[temp] = arr[temp2];
		arr[temp2] = arg;
	}
}

template <class T>
void Sort(Bag<T>& b, int num) {
	int temp;
	for (temp = 0; temp < num; ++temp) {
		int temp2 = temp;
		for (int temp3 = temp + 1; temp3 < num; temp3++) {
			if (b.arr[temp3] < b.arr[temp2]) {
				temp2 = temp3;
			}
		}
		T arg = b.arr[temp];
		b.arr[temp] = b.arr[temp2];
		b.arr[temp2] = arg;
	}
}




int main(void) {
	try {
		Bag<int> b(10);
		Set<double> s(10);
		//Bag<int> b(0);
		int elem;
		//b.Delete(elem);
		b.Add(1);
		b.Add(2);
		b.Add(3);
		b.Add(5);
		b.Add(4);
		b.Add(10);
		b.Add(8);
		b.Print();
		int arr[10] = { 1,4,8,2,6,3,10,3,9,-1 };
		Sort(arr,10);
		for (int i = 0; i < 10; ++i)
			cout << arr[i] << "\t";
		cout << endl;
		Sort(b, b.top_value());
		b.Print();

		s.Add(1.1);
		s.Add(1.4);
		s.Add(0.8);
		s.Add(2.5);
		s.Add(0.7);
		Sort(s, s.top_value());
		s.Print();
	}
	catch (Err& a) {
		a.print();
	}
}