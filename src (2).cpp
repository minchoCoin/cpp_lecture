#include <iostream>
using namespace std;
class A {
public:
	A() : a(0) {}
	A(int elem) : a(elem) { cout << "Hello"; }
	void operator = (int obj) { a = obj; cout << "inserting operator";  }
	A(int& elem) { a = elem; cout << "change operator"; }
private:
	int a;
};
template <class T>
void Sort(T* arr, int size);

void Sort(char** arr, int size);
template <class T>
void Sort(T* arr, int size) {
	int i, j;
	for (i = 0; i < size; ++i) {
		for (j = 0; j < size - 1 - i; ++j) {//for(j=0;j<size-1;++j)
			if (arr[j] > arr[j + 1]) {
				T temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
				//swap((a + j), a + j + 1);
		}
	}
}

template <>
void Sort(const char** arr, int size) {
	int i, j;
	for (i = 0; i < size; ++i) {
		for (j = 0; j < size - 1 - i; ++j) {//for(j=0;j<size-1;++j)
			if (strcmp(arr[j] , arr[j + 1])>0) {
				const char *temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			//swap((a + j), a + j + 1);
		}
	}
}


int main(void) {
	int a[6] = { 1,2,4,3,2,5 };
	const char* arr[3] = { "hello","binary","aaa" };
	Sort(a, 6);
	Sort(arr, 3);
	for (int i = 0; i < 6; ++i)
		cout << a[i] << endl;
	cout << endl;
	for (int i = 0; i < 3; ++i) {
		cout << arr[i] << endl;
	
	}
	cout << endl;
	A elem = 4;
	elem = 0;

	return 0;
}