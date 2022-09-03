#include <iostream>
#include <stdlib.h>
using namespace std;
//20.4.21 060 class
// implement the functions : add, sub, display matrix
#define ROWS 2
#define COLS 3
template <class T, int Row, int Col>
class Matrix {
public:
    //Matrix(int row, int col);
    Matrix();
    int InputMatrix();
    int DisplayMatrix();
    Matrix<T,Row,Col> operator+(Matrix<T,Row,Col>);
    Matrix<T,Row, Col>operator-(Matrix<T,Row,Col>);
    Matrix<T,Row, Col> operator = (Matrix<T,Row, Col>);
private:
    int rows, cols;
    //Do not use "int Term[rows][cols];"
    T* Term;
};
template <class T, int Row, int Col>
Matrix<T, Row, Col>::Matrix() : rows(Row), cols(Col)
{
    Term = new T[rows * cols];
}

template <class T,int Row, int Col>
int Matrix<T,Row, Col>::InputMatrix() {
    T input_value;
    cout << "rows = " << rows << "  cols = " << cols << endl;
    for (int j = 0; j < rows * cols; j++)
    {
        cout << "term value = ";
        cin >> input_value;
        cout << " " << endl;
        Term[j] = input_value;
    }
    return 0;
}
template <class T,int Row, int Col>
int Matrix<T, Row, Col>::DisplayMatrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << Term[i * rows + j]<<"\t";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
template <class T, int Row, int Col>
Matrix<T,Row, Col> Matrix<T, Row, Col>::operator+(Matrix<T,Row, Col> m) {
    Matrix<T,Row, Col> temp;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp.Term[rows * i + j] = Term[rows * i + j] + m.Term[rows * i + j];
        }
    }
    return temp;
}
template <class T, int Row, int Col>
Matrix<T,Row, Col> Matrix<T,Row, Col>::operator-(Matrix<T,Row, Col> m) {
    Matrix<T,Row, Col> temp;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp.Term[rows * i + j] = Term[rows * i + j] - m.Term[rows * i + j];
        }
    }
    return temp;
}
template <class T,int Row, int Col>
Matrix<T,Row, Col> Matrix<T,Row, Col>::operator=(Matrix<T,Row, Col> m) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Term[rows * i + j] = m.Term[rows * i + j];
        }
    }
    return m;
}
int main(void) {
    Matrix<double, 2,2> a, b, c, d;
    Matrix<double ,2, 2> e;
    while (1)
    {
        
        int select; // 1) input, 2) add, 3) subtract, 4) display, 5) quit
        cout << "\nSelect command 1: input, 2: Add, 3. Subtract, 4: display, 5. quit => ";
        cin >> select;
        switch (select) {
        case 1:
            a.InputMatrix();
            b.InputMatrix();
            c.InputMatrix();
            d.InputMatrix();
            break;
        case 2:
            e = a + b + c + d;
            break;

        case 3:
            e = a - b - c - d;
            break;
        case 4:
            a.DisplayMatrix();
            b.DisplayMatrix();
            c.DisplayMatrix();
            d.DisplayMatrix();
            e.DisplayMatrix();
            break;
        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
}

