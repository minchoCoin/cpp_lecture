#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class Bag{
	public:
		Bag(int MaxBagsize = 10);
		~Bag();
		virtual void Add(T elem);
		T* Delete(T& elem);
		bool IsFull();
		bool IsEmpty();
		int Top();
		
		template <class U>
		friend ostream& operator<< (ostream& stream, Bag<U>& b);
	protected:
	void Full(); // bag이 포화상태일 때의 조치
	void Empty(); // bag이 공백 상태일 때의 조치
	T *arr;
	int MaxSize; // 배열의 크기
	int top; // 배열에서 원소가 들어 있는 가장 높은 위치
};
template <class T>
class Stack : public Bag<T>{
	public:
	Stack(int MaxBagsize = 10);
	~Stack();
	T* Pop(T& elem);
	
	template <class U>
	friend ostream& operator<< (ostream& os, Stack<U>&s);
		
};
template <class T>
Bag <T>::Bag(int MaxBagsize) : MaxSize(MaxBagsize){
	arr = new T[MaxBagsize];
	top = 0;	
}
template <class T>
Bag <T>::~Bag() {delete arr;}

template <class T>
void Bag<T>::Add(T elem){
	if(IsFull())
		Full();
	else{
		arr[top] = elem;
		top++;
	}
}
template <class T>
T* Bag<T>::Delete(T& elem){
	if(IsEmpty()){
		Empty();
		return NULL;
	}
		
	else{
		int deletepos = rand()%top;
		elem = arr[deletepos];
	}
	return &elem;
}

template <class T>
bool Bag<T>::IsFull() {return top == MaxSize;}

template <class T>
bool Bag<T>::IsEmpty() {return top==0;}

template <class T>
int Bag<T>::Top() {return top;}

template <class U>
ostream& operator <<(ostream& os, Bag<U>& b)
{
	int i;
	for(i=0;i<b.Top();++i){
		os<<(b.arr)[i]<<"\t";	
	}
	os<<endl;
	return os;
}

template <class T>
void Bag<T>::Full() {cout<<"Full. no empty space."<<endl;}

template <class T>
void Bag<T>::Empty() {cout<<"Empty. no value."<<endl;}


template <class T>
Stack<T>::Stack(int MaxBagSize):Bag<T>(MaxBagSize) {}

template <class T>
Stack<T>::~Stack() {}

template <class T>
T* Stack<T>::Pop(T& elem){
	if(Bag<T>::IsEmpty()){
		Bag<T>::Empty();
		return NULL;	
	}
	elem = Bag<T>::arr[--(Bag<T>::top)];
	return 	&elem;
}

template <class U>
ostream& operator<< (ostream& os, Stack<U>&s) {
	Bag<U> b = (Bag<U>)s;
	os<<b;
	return os;
}

int main(void)
{
	srand(time(NULL));
	Bag<int> b(10);
	int i;
	for(i=0;i<10;++i){
		b.Add(i);	
	}
	cout<<b;
	for(i=0;i<10;++i){
		int j;
		cout<<*(b.Delete(j))<<endl;	
	}
	
}
