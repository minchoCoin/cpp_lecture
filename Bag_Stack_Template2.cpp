#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T, int nE1>
class Bag{
	public:
		Bag();
		~Bag();
		virtual void Add(T elem);
		T* Delete(T& elem);
		bool IsFull();
		bool IsEmpty();
		int Top();
		
		template <class U, int n>
		friend ostream& operator<< (ostream& stream, Bag<U,n>& b);
	protected:
	void Full(); // bag이 포화상태일 때의 조치
	void Empty(); // bag이 공백 상태일 때의 조치
	T *arr;
	int MaxSize; // 배열의 크기
	int top; // 배열에서 원소가 들어 있는 가장 높은 위치
};
template <class T, int nE1>
class Stack : public Bag<T,nE1>{
	public:
	Stack();
	~Stack();
	T* Pop(T& elem);
	
	template <class U, int n>
	friend ostream& operator<< (ostream& os, Stack<U,n>&s);
		
};
template <class T, int nE1>
Bag <T,nE1>::Bag() : MaxSize(nE1){
	arr = new T[nE1];
	top = 0;	
}
template <class T,int nE1>
Bag <T,nE1>::~Bag() {delete arr;}

template <class T,int nE1>
void Bag<T,nE1>::Add(T elem){
	if(IsFull())
		Full();
	else{
		arr[top] = elem;
		top++;
	}
}
template <class T,int nE1>
T* Bag<T,nE1>::Delete(T& elem){
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

template <class T,int nE1>
bool Bag<T,nE1>::IsFull() {return top == MaxSize;}

template <class T,int nE1>
bool Bag<T,nE1>::IsEmpty() {return top==0;}

template <class T,int nE1>
int Bag<T,nE1>::Top() {return top;}

template <class U, int n>
ostream& operator <<(ostream& os, Bag<U,n>& b)
{
	int i;
	for(i=0;i<b.Top();++i){
		os<<(b.arr)[i]<<"\t";	
	}
	os<<endl;
	return os;
}

template <class T, int nE1>
void Bag<T,nE1>::Full() {cout<<"Full. no empty space."<<endl;}

template <class T, int nE1>
void Bag<T,nE1>::Empty() {cout<<"Empty. no value."<<endl;}


template <class T,int nE1>
Stack<T,nE1>::Stack():Bag<T,nE1>() {}

template <class T, int nE1>
Stack<T,nE1>::~Stack() {}

template <class T, int nE1>
T* Stack<T,nE1>::Pop(T& elem){
	if(Bag<T,nE1>::IsEmpty()){
		Bag<T,nE1>::Empty();
		return NULL;	
	}
	elem = Bag<T,nE1>::arr[--(Bag<T,nE1>::top)];
	return 	&elem;
}

template <class U, int n>
ostream& operator<< (ostream& os, Stack<U,n>&s) {
	Bag<U,n> b = (Bag<U,n>)s;
	os<<b;
	return os;
}

int main(void)
{
	srand(time(NULL));
	Bag<int,20> b;
	int i;
	for(i=0;i<20;++i){
		b.Add(i);	
	}
	cout<<b;
	for(i=0;i<20;++i){
		int j;
		cout<<*(b.Delete(j))<<endl;	
	}
	
}
