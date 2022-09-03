#include <iostream>
#include <stdlib.h>
using namespace std;
//20.4.21 060 class
// implement the functions : add, sub, display matrix
#define ROWS 2
#define COLS 3
class Err {};
class Matrix {
public:
    Matrix(int row, int col);
    Matrix();
    //~Matrix() { delete[]Term; }
    int InputMatrix();
    int DisplayMatrix();
    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator=(Matrix);
private:
    int rows, cols;
    //Do not use "int Term[rows][cols];"
    int* Term;
};

Matrix::Matrix(int row, int col) : rows(row), cols(col)
{
    Term = new int[rows * cols];
}
Matrix::Matrix() : rows(ROWS), cols(COLS) { Term = new int[rows * cols]; }

int Matrix::InputMatrix() {
    int input_value;
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
int Matrix::DisplayMatrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << Term[i*rows+j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
Matrix Matrix::operator + (Matrix m) {
    if (rows != m.rows || cols != m.cols)
        throw(Err());
    Matrix temp(rows, cols);
    for (int i = 0; i < rows * cols; ++i) {
        temp.Term[i] = Term[i] + m.Term[i];
    }
    return temp;
    
}
Matrix Matrix::operator - (Matrix m) {
    if (rows != m.rows || cols != m.cols)
        throw(Err());
    Matrix temp(rows, cols);
    for (int i = 0; i < rows * cols; ++i) {
        temp.Term[i] = Term[i] - m.Term[i];
    }
    return temp;
}
Matrix Matrix::operator=(Matrix m) {
    if (rows != m.rows || cols != m.cols)
        throw(Err());
    for (int i = 0; i < rows * cols; ++i) {
        Term[i] = m.Term[i];
    }
    return *this;
}
int main(void) {
    Matrix a, b, c, d;
    Matrix e;
    int is_input = 0;
    try {
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
                is_input = 1;
                break;
            case 2:
                if(is_input)
                    e = a + b + c + d;
                break;

            case 3:
                if(is_input)
                    e = a - b - c - d;
                break;
            case 4:
                if (is_input) {
                    a.DisplayMatrix();
                    b.DisplayMatrix();
                    c.DisplayMatrix();
                    d.DisplayMatrix();
                    e.DisplayMatrix();
                }
                
                break;
            default:
                exit(0);
                break;
            }
        }
    }
    catch(Err){
        cout << "rows and cols is not match!!" << endl;
    }
    system("pause");
    return 1;
}

