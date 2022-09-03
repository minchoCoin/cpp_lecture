#include <iostream>
#include <cstdlib>
using namespace std;
template <class T>
class Bag;

template <class T>
ostream& operator << (ostream& os, Bag<T>& b);
template <class T>
class Bag {
public:
	Bag(int n);
	~Bag();
	void Add(T);
	virtual T* Delete(T&);
	int Top();
	//void Input();
	void Print();
	bool IsEmpty();
	bool IsFull();
	friend ostream& operator << (ostream& os, Bag<T>& b);
private:
	int top;
	int max;
	T* arr;
};
template <class T>
Bag<T>::Bag(int n) {
	arr = new T[n];
	max = n;
	top = 0;
}
template <class T>
Bag<T>::~Bag() {}

template <class T>
void Bag<T>::Add(T elem) {
	if (IsFull()) {
		return;
	}
	arr[top++] = elem;
	cout << elem << " is added" << endl;
}
template <class T>
T* Bag<T>::Delete(T& elem) {
	if (IsEmpty()) {
		return NULL;
	}
	int deletePos = rand() % top;
	elem = arr[deletePos];
	for (int i = deletePos; i < top-1; ++i) {
		arr[i] = arr[i + 1];
	}
	top--;
	return &elem;
	
}
template <class T>
int Bag<T>::Top() { return top; }

template <class T>
bool Bag<T>::IsEmpty() { return top == 0; }

template <class T>
bool Bag<T>::IsFull() { return top == max; }

template <class T>
void Bag<T>::Print() {
	for (int i = 0; i < top; ++i) {
		cout << arr[i] <<" " <<endl;
	}
}
template <class T>
ostream& operator << (ostream& os, Bag<T>& b) {
	b.Print();
	return os;
}
template <class T>
class Queue : public Bag<T> {
	Queue(int n);
	~Queue();
	T* Delete(T&);
};
template <class T>
Queue<T>::Queue(int n) : Bag<T>(n) {}
template <class T>
Queue<T>::~Queue() {}
template <class T>
T* Queue<T>::Delete(T& elem) {
	if (Bag<T>::IsEmpty()) {
		return NULL;
	}
	elem = arr[0];
	for (int i = 0; i < top-1; ++i) {
		arr[i] = arr[i + 1];
	}
	return &elem;
}
int main(void) {
	return 0;
}