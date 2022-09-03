//4-5. return_by_reference.cpp   4.4.4 reference에 의한 함수 return 값
#include<iostream>
using namespace std;

int vvalue(int n);
int& rvalue(int &n);
int& sum(int a, int b);
int& maxInt(int &a, int &b);
int main(){
    //1번 주석
    
    cout << "pass by value & return by value" << endl;
    int a = 5;
    int n = 0;
    cout <<"Before vvalue()::&a : "<<&a<<", a : "<<a
		<<", &n : "<<&n<<", n : " <<n<<endl; //vvalue 호출 전
    n = vvalue(a);
    cout <<"After vvalue()::&a : "<<&a<<", a : "<<a
		<<", &n : "<<&n<<", n : " <<n<<endl; //vvalue 호출 후
    cout<<endl;
    cout<<endl;
    

    //2번 주석
    
    cout << "pass by reference & return by reference" << endl;
    int b = 5;
    cout<<"Before rvalue()::&b : "<<&b<<", b : "<<b<<endl;
    int &m = rvalue(b);
    cout <<"After rvalue()::&b : "<<&b<<", b : "<<b
		<<", &m : "<<&m<<", m : "<<m<<endl;
    cout << endl;
    

    //3번 주석
    
    cout << "pass by value & return by reference" << endl;
    int c = 10, d = 15, e = 17;
    cout <<"Before sum():: &c : "<<&c<<", c : "<<c<<", &d : "<<&d
		<<", d : "<<d<<endl;
    int &k = sum(sum(c, d), e);
    cout<<"After sum():: &c : "<<&c<<", c : "<<c<<", &d : "<<&d
		<<", d : "<<d<<", &k : "<<&k<<", k : "<<k<<endl;
    cout << endl;
    

    //4번 주석
    
    cout << "pass by reference & return by reference" << endl;
    int f = 10, g = 15, h = 19;
    cout<<"Before maxInt():: &f : "<<&f<<", f : "<<f
		<<", &g : "<<&g<<", g : "<<g<<endl;
    int &t = maxInt(maxInt(f, g), h);
    cout<<"After maxInt():: &f : "<<&f<<", f : "<<f
		<<", &g : "<<&g<<", g : "<<g<<", &t : "<<&t<<", t : "<<t<<endl;
    cout << endl;
    
    system("pause");
}

int vvalue(int i){
    i = i + 3;
    cout<<"Inside vvalue()::&i : "<<&i<<", i : "<<i<<endl;
    return i;
}

int& rvalue(int &v){
    v = v + 3;
    cout<<"Inside rvalue()::&v  : "<<&v<<",  v : "<<v<<endl; 
    return v;
}

int& sum(int a, int b){
    int tmp;
    tmp = a + b;
    cout<<"Inside sum():: &a  : "<<&a<<", &b : "<<&b<<",&tmp : "<<&tmp<<",tmp : "<<tmp<<endl;
    return tmp;
}
int& maxInt(int &a, int &b){
    int *max = new int[1];
    if (a>b)
        *max = a;
    else
        *max = b;
    cout<<"Inside maxInt():: &a  : "<<&a<<", &b : "<<&b<<",max : "<<max<<",*max : "<<*max<<endl;
    return *max;
}
