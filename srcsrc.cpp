/*
1. 기존 실습코드, 구글 등 모든 자료 이용 가능함
2. 아래 제시된 코드 기반이 아니면 0점 처리
3. 동료 학생이 제공한 소스코드에 대한 표절 검사는 plato 등에 의해 시행
4. 3,4학년이 대리 시험 치르는 경우에 적발시 홈페이지 공지 및 대학본부에 징계 요청
   (과제 및 코딩 시험 결과의 일관성 검사로 의심학생 소환하여 대면 검사 시행함)
*/
#include <iostream>
using namespace std;
class Vector
{
private:
    double x;          // horizontal value
    double y;          // vertical value
// private methods for setting values
    void set_x(double x1);
    void set_y(double y1);
public:
    Vector();
    Vector(double, double);
    ~Vector();
    Vector operator+(const Vector& b) const;
    Vector operator*(const Vector& b) const;
    Vector operator=(const Vector&);
    Vector& operator++(int);//x++, y++
    friend istream& operator>>(istream& is, Vector& v);
    friend ostream& operator<<(ostream& os, const Vector& v);
};
void Vector::set_x(double x1) { x = x1; }
void Vector::set_y(double y1) { y = y1; }

Vector::Vector() : x(0.0),y(0.0){}
Vector::Vector(double a, double b) : x(a),y(b) {}
Vector::~Vector() {}
Vector Vector::operator+(const Vector& b) const {
    Vector v(x + b.x, x + b.y);
    return v;
}
Vector Vector::operator*(const Vector& b) const {
    Vector v(this->x * b.x, this->y * b.y);
    return v;
}
Vector Vector::operator=(const Vector& b) {
    x = b.x;
    y = b.y;
    return b;
}
Vector& Vector::operator++(int) {
    x++;
    y++;
    return *this;
}
ostream& operator << (ostream& os, const Vector& v) {
    os << "(" << v.x << "," << v.y << ")" << endl;
    return os;
}
istream& operator >> (istream& is,  Vector& v) {
    cin >> v.x >> v.y;
    return is;
}
class VectorNumberSeries {
public:
    VectorNumberSeries(int t = 0);
    ~VectorNumberSeries();
    Vector Sum();//        Vector operator+(const Vector& b) const; 이용하여 구현
    Vector Multiply();//        Vector operator*(const Vector& b) const;이용하여 구현
    Vector Delete();
    VectorNumberSeries operator= (const VectorNumberSeries&);//        Vector operator=(const Vector&); 이용하여 구현
    VectorNumberSeries& operator++(int);//        Vector& operator++(int);이용하여 구현
    friend istream& operator >> (istream& s, VectorNumberSeries&);//reuse: friend istream& operator >> (istream& s, Vector& c);//istream& operator>>(istream& is, const Vector& v);이용하여 구현
    friend ostream& operator << (ostream& s, VectorNumberSeries&);//reuse: friend ostream& operator << (ostream& s, Vector c);//ostream& operator<<(ostream& os, const Vector& v);이용하여 구현
private:
    static int top;//Term의 갯수를 기록
    Vector* Term;
    int MaxSize;
};
VectorNumberSeries::VectorNumberSeries(int t) {
    Term = new Vector[t];
    MaxSize = t;
}
VectorNumberSeries::~VectorNumberSeries() { delete Term; }
Vector VectorNumberSeries::Sum()
{
	Vector temp(0, 0);
	for (int i = 0; i < top; i++)
		temp = temp + *(Term + i);
	return temp;
}
Vector VectorNumberSeries::Multiply() {
    int i;
    Vector v(1, 1);
    Vector temp;
    for (i = 0; i < top; ++i) {
        temp = v * Term[i];
        v = temp;
    }
    return v;

}
Vector VectorNumberSeries::Delete() {
    if (top == 0) return Vector(0, 0);
    Vector d = Term[0];
    int i;
    for (i = 0; i < top; ++i) {
        Term[i] = Term[i + 1];
    }
    top--;
    return d;
}
VectorNumberSeries VectorNumberSeries::operator=(const VectorNumberSeries& a) {
    int i;
    for (i = 0; i < top; ++i) {
        Term[i] = a.Term[i];
    }
    return *this;
}
VectorNumberSeries& VectorNumberSeries::operator++(int) {
    int i;
    for (i = 0; i < top; ++i) {
        Term[i]++;
    }
    return *this;
}
ostream& operator <<(ostream& s, VectorNumberSeries& v) {
    for (int i = 0; i < v.top; ++i)
        s << v.Term[i];
    return s;
}
istream& operator >> (istream& s, VectorNumberSeries& v) {
    //if(v)
    int Top = v.top;
    if (Top == v.MaxSize)
        return s;
    s >> v.Term[Top];
    (v.top)++;
    return s;
}
int VectorNumberSeries::top = 0;
int main() {
    int select;
    VectorNumberSeries ax(10), bx(10);
    Vector t;
    while (1)
    {

        cout << "\nSelect command 1: Add Vector number, 2: Delete first Vector number, 3. Display all,4. Sum, 5. Multiply, 6. IncreaseSeries, 7.Quit = > ";
            cin >> select;
        switch (select) {
        case 1:
            cout << "Add a new vector number" << endl;
            cin >> ax;//add a new Vector number
            break;

        case 2:
            cout << "Delete the first vector" << endl;
            t = ax.Delete();
            cout << "The deleted vector is : ";
            cout << t << endl;
            break;

        case 3:
            cout << "Display all the vectors: " << endl;
            cout << ax << endl;
            break;

        case 4:
            cout << "Summarize all the vectors: ";
            bx = ax;//        VectorNumberSeries operator= (const VectorNumberSeries&);구현 필요
            t = bx.Sum();
            cout << "The sum vector is : ";
            cout << t << endl;;
            break;
        case 5:
            cout << "Multiply all the vectors: ";// t = a * b * c * d;
            t = ax.Multiply();
            cout << "The multiply vector is : ";
            cout << t << endl;
            break;
        case 6:
            cout << "Increase all the vectors: ";
            ax++;
            cout << ax << endl;
            break;
        default:
            exit(0);
            break;
        }
    }//destructor 구현
    system("pause");
    return 0;
}
