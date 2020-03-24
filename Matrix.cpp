#include "Matrix.h"

//Конструктор по умолчанию
Matrix::Matrix(){
    Matrix_create();
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j]=rand()%26;
    counter++;
}

/*
 * Конструктор с параметром
 * При вызове позволяет указать в каком диапазоне буду элементы матрицы
 */
Matrix::Matrix(int r) {
    Matrix_create();
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j]=rand()%r;
    counter++;
}

/*
 * Rонструктор с параметрами и списком инциализации
 * При вызове позволяет указать размер матрицы и в каком диапазоне буду её элементы
 * и проинициальзировать переменные size и random соответственно
 */
Matrix::Matrix(int s, int r) : size(s), random(r) {
    Matrix_create();
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j] = rand()%random;
    counter++;
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

//Создание динамической матрицы
void Matrix::Matrix_create() {
    Mtrx = new int*[size];
    for (int j = 0; j < size; j++)
        Mtrx[j] = new int[size];
}

//Сумма матриц
void Matrix::Matrix_sum(Matrix& b, Matrix& res) {
    for (int i(0); i < 3; i++)
        for (int j(0); j < 3; j++)
            res.Mtrx[i][j] = Mtrx[i][j] + b.Mtrx[i][j];
    res.Matrix_print();
}

//Умножение матриц
void Matrix::Matrix_inc (Matrix& b, Matrix& res) {
    for (int i(0); i < 3; i++)
        for (int j(0); j < 3; j++) {
            res.Mtrx[i][j] = 0;
            for(int k(0); k < 3; k++)
                res.Mtrx[i][j] += Mtrx[i][k] * b.Mtrx[k][j];
        }
    res.Matrix_print();
}

//Сумма матрицы и числа
void Matrix::Matrix_sum (int num, Matrix& res) {
    for (int i(0); i < 3; i++)
        for (int j(0); j < 3; j++)
            res.Mtrx[i][j] = Mtrx[i][j] + num;
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
    for (int i(0); i < 3; i++)
        for (int j(0); j < 3; j++)
            if (Mtrx[i][j] != b.Mtrx[i][j])
                return 0;
    return 1;
}

//Определитель матрицы
int Matrix::Matrix_det() {
    return Mtrx[0][0]*Mtrx[1][1]*Mtrx[2][2] + Mtrx[0][1]*Mtrx[1][2]*Mtrx[2][0] + Mtrx[0][2]*Mtrx[1][0]*Mtrx[2][1]
           - Mtrx[0][2]*Mtrx[1][1]*Mtrx[2][0] - Mtrx[0][0]*Mtrx[1][2]*Mtrx[2][1] - Mtrx[0][1]*Mtrx[1][0]*Mtrx[2][2];
}

//Транспонирование матрицы
void Matrix::Matrix_transp() {
    int tmp;
    for (int i(1); i < 3; i++)
        for (int j(0); j < 2; j++) {
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

//Деструктор
Matrix::~Matrix(){
    for (int i(0); i < size; i++)
        delete[] Mtrx[i];
    delete[] Mtrx;
}