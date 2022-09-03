#include <iostream>
#include <cstring>
using namespace std;
template <class T>
void sort(T* data, int num);
void sort(char** data, int num);

template <class T>
void sort(T* data, int num){
	cout<<"sort 수행"<<endl;
	for(int temp = 0;temp<num;++temp){
		int temp2  = temp;
		for(int temp3 = temp+1;temp3<num;temp3++)
			if(data[temp3]<data[temp2])
				temp2 = temp3;
		T arg = data[temp];
		data[temp] = data[temp2];
		data[temp2]=arg;
	}
}

template<>
void sort(const char** data, int num){
	cout<<"sort 수행 : const char**"<<endl;
	for(int temp = 0;temp<num;++temp){
		int temp2  = temp;
		for(int temp3 = temp+1;temp3<num;temp3++)
			if(strcmp(data[temp3],data[temp2])<0)
				temp2 = temp3;
		const char* arg = data[temp];
		data[temp] = data[temp2];
		data[temp2]=arg;
	}
}
int main(void){
	int arr[10] = {110,8,3,2,8,2,7,1,6,4};
	const char* arr2[5] = {"hello","world","abc","BBC","congratuation"};
	sort(arr,10);
	sort(arr2,5);
	for(int i=0;i<10;++i)
		cout<<arr[i]<<endl;
	for(int i=0;i<5;++i)
		cout<<arr2[i]<<endl;
	return 0;
}
