/*
1. ���� �ǽ��ڵ�, ���� �� ��� �ڷ� �̿� ������
2. �Ʒ� ���õ� �ڵ� ����� �ƴϸ� 0�� ó��
3. ���� �л��� ������ �ҽ��ڵ忡 ���� ǥ�� �˻�� plato � ���� ����
4. 3,4�г��� �븮 ���� ġ���� ��쿡 ���߽� Ȩ������ ���� �� ���к��ο� ¡�� ��û
   (���� �� �ڵ� ���� ����� �ϰ��� �˻�� �ǽ��л� ��ȯ�Ͽ� ��� �˻� ������)
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
    Vector Sum();//        Vector operator+(const Vector& b) const; �̿��Ͽ� ����
    Vector Multiply();//        Vector operator*(const Vector& b) const;�̿��Ͽ� ����
    Vector Delete();
    VectorNumberSeries operator= (const VectorNumberSeries&);//        Vector operator=(const Vector&); �̿��Ͽ� ����
    VectorNumberSeries& operator++(int);//        Vector& operator++(int);�̿��Ͽ� ����
    friend istream& operator >> (istream& s, VectorNumberSeries&);//reuse: friend istream& operator >> (istream& s, Vector& c);//istream& operator>>(istream& is, const Vector& v);�̿��Ͽ� ����
    friend ostream& operator << (ostream& s, VectorNumberSeries&);//reuse: friend ostream& operator << (ostream& s, Vector c);//ostream& operator<<(ostream& os, const Vector& v);�̿��Ͽ� ����
private:
    static int top;//Term�� ������ ���
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
            bx = ax;//        VectorNumberSeries operator= (const VectorNumberSeries&);���� �ʿ�
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
    }//destructor ����
    system("pause");
    return 0;
}
