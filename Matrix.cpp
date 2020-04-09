#include "Matrix.h"
#include <cassert>

/*
 * КОНСТРУКТОРЫ
 */
//Конструктор по умолчанию
Matrix::Matrix() {
    random = 26;
    Matrix_create();
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j]=rand()%random;
    counter++;
}

/*
 * Конструктор с параметром
 * При вызове позволяет указать в каком диапазоне буду элементы матрицы
 */
Matrix::Matrix(int r) {
    random = r;
    Matrix_create();
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j]=rand()%random;
    counter++;
}

/*
 * Конструктор с параметрами и списком инциализации
 * При вызове позволяет указать размер матрицы, в каком диапазоне буду её элементы
 * и проинициальзировать переменные size и random соответственно
 */
Matrix::Matrix(int s, int r) : size(s), random(r) {
    Matrix_create();
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j] = rand()%random;
    counter++;
}

/*
 * Конструктор копирования
 * Используется для копирования полей из другого объекта исходного класса
 * Для переменной size используется инициализация так как это поле константное
 * random инициализируется в теле конструктора
 */
Matrix::Matrix(const Matrix &matrix) {
    random = matrix.random;
    Matrix_create();
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j] = rand() % random;
    cout << "Copy constructor worked here!\n";
    counter++;
}

/*
 * МЕТОДЫ КЛАССА Matrix
 */
//Создание динамической матрицы
void Matrix::Matrix_create() {
    Mtrx = new int*[size];
    for (int j = 0; j < size; j++)
        Mtrx[j] = new int[size];
}

//Вывод матрицы в консоль
void Matrix::Matrix_print() {
    for (int i(0); i < size; i++) {
        for (int j(0); j < size; j++)
            cout<<Mtrx[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

//Сумма матриц
void Matrix::Matrix_sum(Matrix& b, Matrix& res) {
    if(!(size == b.size && size == res.size && b.size == res.size)) {
        cout << "Sizes doesn't match -> Sum imposible" << endl;
        return;
    }
        for (int i(0); i < size; i++)
            for (int j(0); j < size; j++)
                res.Mtrx[i][j] = Mtrx[i][j] + b.Mtrx[i][j];
        res.Matrix_print();

}

//Сумма матрицы и числа
void Matrix::Matrix_sum (int num, Matrix& res) {
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            res.Mtrx[i][j] = Mtrx[i][j] + num;
    res.Matrix_print();
}

//Умножение матриц
void Matrix::Matrix_inc (Matrix& b, Matrix& res) {
    if(!(size == b.size && size == res.size && b.size == res.size)) {
        cout << "Sizes doesn't match -> Increase imposible" << endl;
        return;
    }
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++) {
            res.Mtrx[i][j] = 0;
            for(int k(0); k < size; k++)
                res.Mtrx[i][j] += Mtrx[i][k] * b.Mtrx[k][j];
        }
    res.Matrix_print();
}

//Умножение матрицы на число
void Matrix::Matrix_inc (int num, Matrix& res) {

    for (int i(0); i < 3; i++)
        for (int j(0); j < 3; j++)
            res.Mtrx[i][j] = Mtrx[i][j] * num;
    res.Matrix_print();
}

//Сранвнение мтариц
bool Matrix::Matrix_cmp (Matrix& b) {
    if(size != b.size) {
        cout << "Sizes doesn't match -> Sum imposible" << endl;
        return 0;
    }
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            if (Mtrx[i][j] != b.Mtrx[i][j])
                return 0;
    return 1;
}

//Определитель матрицы
int Matrix::Matrix_det() {
    if(size != 3) {
        cout << "Size must be equal 3 to find deterine" << endl;
        return 0;
    }
    return Mtrx[0][0]*Mtrx[1][1]*Mtrx[2][2] + Mtrx[0][1]*Mtrx[1][2]*Mtrx[2][0] + Mtrx[0][2]*Mtrx[1][0]*Mtrx[2][1]
           - Mtrx[0][2]*Mtrx[1][1]*Mtrx[2][0] - Mtrx[0][0]*Mtrx[1][2]*Mtrx[2][1] - Mtrx[0][1]*Mtrx[1][0]*Mtrx[2][2];
}

//Транспонирование матрицы
void Matrix::Matrix_transp() {
    int tmp;
    for (int i(1); i < size; i++)
        for (int j(0); j < size-1; j++) {
            tmp = Mtrx[i][j];
            Mtrx [i][j] = Mtrx[j][i];
            Mtrx[j][i] = tmp;
        }
    Matrix_print();
}

//Вывод счетчика в консоль
void Matrix::get_counter() {
    cout << "Всего объектов класса Matrix:" << counter << endl;
}

/*
 * ПЕРЕГРУЗКИ ОПЕРАЦИЙ
 */
//
ostream& operator<<(ostream &out, const Matrix &m) {
    for (int i(0); i < m.size; i++) {
        for (int j(0); j < m.size; j++)
            out<<m.Mtrx[i][j]<<" ";
        out<<endl;
    }
    out<<endl;

    return out;
}

//
istream& operator>>(istream &in, Matrix &m) {
    cout << "Введите Матрицу " << m.size << "x" << m.size << ":\n";
    for (int i(0); i < m.size; i++) {
        for (int j(0); j < m.size; j++)
            in >> m.Mtrx[i][j];
    }
    cout << endl;

    return in;
}

//
Matrix& Matrix::operator=(Matrix &matrix) {
    if(size == matrix.size)
        for (int i(0); i < size; i++)
            for (int j(0); j < size; j++)
                Mtrx[i][j] = matrix.Mtrx[i][j];
    else
        cout << "Sizes doesn't match" << endl;

    return *this;
}

//
void Matrix::operator+ (int num) {
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j] += num;
}

//
void Matrix::operator+ (const Matrix &matrix) {
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j] += matrix.Mtrx[i][j];
}

//
void Matrix::operator* (int num) {
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j] *= num;
}

//
void Matrix::operator* (const Matrix &Matrix) {

}

//Деструктор
Matrix::~Matrix() {
    for (int i(0); i < size; i++)
        delete[] Mtrx[i];
    delete[] Mtrx;
}
