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

                       cout << "�� ���� �� �̻� Push �Ұ���" << endl;

               }

               array[++top] = item;

        }

        virtual T Pop() = 0; //�����Լ� ��, Bag������ ���� ���� ������ Stack���� ���� �ֱ� ������

        virtual void Del() //top�� �����(Stack�� Pop���� �ٸ��� ������ ���� ����)

        {

               if (IsEmpty())

               {

                       cout << "������ �����" << endl;

               }

               for (int i = (top / 2); i < top; i++)

               {

                       array[i] = array[i + 1]; //��ĭ�� �����

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

               //�ڵ����� ~Bag()

        }

        T Pop()

        {

               if (IsEmpty())

                       cout << "������ ����ִ�" << endl;

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

        cout << "���� ���� ���" << endl;

        cout << intStack << endl;

        for (int i = 0; i < 5; i++)

        {

               cout << i + 1 << "��° Pop: " << intStack.Pop() << endl;

        }

        cout << endl << "5�� Pop �� ���� ���" << endl;

        cout << intStack << endl;

        return 0;

}



//��ó: https://jaimemin.tistory.com/153 [������]
