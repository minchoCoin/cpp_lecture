#include <iostream>

using namespace std;

 

template <typename T>

class Bag

{

protected:

        T *array;

        int capacity;

        int top;

public:

        Bag(int bagCapacity = 10) :capacity(bagCapacity)

        {

               array = new T[capacity];

               top = -1;

        }

        virtual ~Bag()

        {

               delete[]array;

        }

        virtual void Push(const T &item)

        {

               if (IsFull())

               {

                       cout << "꽉 차서 더 이상 Push 불가능" << endl;

               }

               array[++top] = item;

        }

        virtual T Pop() = 0; //가상함수 즉, Bag에서는 딱히 쓸모가 없지만 Stack에서 쓸모가 있기 때문에

        virtual void Del() //top을 지운다(Stack의 Pop과는 다르기 때문에 새로 정의)

        {

               if (IsEmpty())

               {

                       cout << "스택은 비었다" << endl;

               }

               for (int i = (top / 2); i < top; i++)

               {

                       array[i] = array[i + 1]; //한칸씩 땡긴다

               }

               top--;

        }

        virtual bool IsEmpty()

        {

               if (top == -1)

                       return true;

               else

                       return false;

        }

        virtual bool IsFull()

        {

               if (top >= capacity)

                       return true;

               return false;

        }

        template <typename T>

        friend ostream &operator<<(ostream &os, Bag<T> &b);

};

 

template <typename T>

ostream &operator<<(ostream &os, Bag<T> &b)

{

        for (int i = 0; i <= b.top; i++)

               os << b.array[i] << " ";

        os << endl;

        return os;

}

 

template <typename T>

class Stack :public Bag<T>

{

public:

        Stack(int stackCapacity = 10) :Bag<T>(stackCapacity)

        {

        }

        ~Stack()

        {

               //자동으로 ~Bag()

        }

        T Pop()

        {

               if (IsEmpty())

                       cout << "스택은 비어있다" << endl;

               T del=array[top--];

               return del;

        }

};

 

int main(void)

{

        Stack<int> intStack;

        for (int i = 0; i < 10; i++)

        {

               intStack.Push(i + 1);

        }

        cout << "현재 스택 출력" << endl;

        cout << intStack << endl;

        for (int i = 0; i < 5; i++)

        {

               cout << i + 1 << "번째 Pop: " << intStack.Pop() << endl;

        }

        cout << endl << "5번 Pop 후 스택 출력" << endl;

        cout << intStack << endl;

        return 0;

}



//출처: https://jaimemin.tistory.com/153 [꾸준함]
