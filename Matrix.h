#pragma once

#include <iostream>
#include <time.h>
using namespace std;

class Matrix {
    const int size = 3;
    int random;
    static int counter;     //Счетчик
public:
    int **Mtrx;

    Matrix();               //Конструктор по умолчанию
    Matrix(int);            //конструктор с параметром
    Matrix(int, int);       //Конструктор с параметрами и списком инциализации
    Matrix(const Matrix&);  //Конструктор копирования

    void Matrix_create();               //Создание матрицы
    void Matrix_print();                //Вывод Матрицы в консоль
    void Matrix_sum (Matrix&, Matrix*); //Сумма Матриц
    void Matrix_sum (int, Matrix*);     //Сумма матрицы и числа
    void Matrix_inc (Matrix&, Matrix*); //Умножение Матриц
    void Matrix_inc (int, Matrix*);     //Умножение матрицы на число
    bool Matrix_cmp (Matrix&);          //Сравнение матриц
    int Matrix_det ();                  //Определитель матрицы
    void Matrix_transp(Matrix*);        //Транспонирование матрицы
    static void get_counter();          //Вывод счетчика

    friend ostream& operator<< (ostream&, const Matrix&);   //Вывод матрицы
    friend istream& operator>> (istream&, Matrix&);         //Ввод матрицы
    Matrix& operator= (Matrix&);                            //Присваивание одной матрице значений другой
    void operator+ (const Matrix&);                         //Сумма Матриц
    void operator+ (int);                                   //Сумма матрицы и числа
    void operator* (int);                                   //Умножение матрицы на число

    ~Matrix();  //Деструктор
};
