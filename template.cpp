#include <iostream>
using namespace std;

template<class T>
class Stack{
	private:
		T data [50];
		int nElements;
	public:
		Stack() : nElements(0) {}
		void Push(T elem);
		T Pop();
		int Number();
		int Empty();
	
};

template <class T>
void Stack <T>::Push(T elem){
	data[nElements] = elem;
	nElements++;	
}
template <class T>
T Stack <T>::Pop() {
	nElements--;
	return data[nElements];	
}

template <class T>
int Stack <T>::Number(){
	return nElements;
}
template <class T>
int Stack <T>::Empty(){
	return (nElements ==0);	
}
int main(void)
{
	Stack <int> intStack;
	
	intStack.Push(50);
	intStack.Push(19);
	intStack.Push();
	
	cout<<"--------int type stack"<<endl;
	while(!intStack.Empty()){
		cout<<intStack.Pop()<<endl;	
	}
	return 0;	
}
