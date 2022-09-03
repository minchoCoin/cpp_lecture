//4-6. PASS BY VALUE_POINTER_REFERENCE.cpp   4.4.4 reference�� ���� �Լ� return ��
#include <iostream>
#include <string.h>
using namespace std;

void swapByValue(int x, int y);
void swapByPointer(int* x, int* y);
void swapByReference(int& x, int& y);

int main(){
    //1�� �ּ�
    int a = 10, b = 20;
    cout << "[�Լ�ȣ����]" << endl;
    cout << "a = " << a << " , b = " << b << endl;

    swapByValue(a,b);//call by value 
    cout << "[pass by value �Լ� ȣ�� ��]" << endl;
    cout << "a = " << a << " , b = " << b << endl;
	
    swapByPointer(&a,&b);//call by reference 
    cout << "[pass by pointer �Լ� ȣ�� ��]" << endl;
    cout << "a = " << a << " , b = " << b << endl;
	a = 10; b = 20;

    swapByReference(a, b);//call by value 
    cout << "[pass by reference �Լ� ȣ�� ��]" << endl;
    cout << "a = " << a << " , b = " << b << endl << endl;
    return 0;
	system("pause");
}
void swapByValue(int x, int y) { 
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
void swapByPointer(int* x, int* y) { 
	//int *x = &a;
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
void swapByReference(int& x, int& y){
	// int &x = a;
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
