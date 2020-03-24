#pragma once
#include <iostream>
#include <time.h>
using namespace std;

class Matrix {
    const int size = 3;
    int random;
    int counter;
public:
    int **Mtrx;

    Matrix();                                           //Конструктор по умолчанию
    Matrix(int);                                        //конструктор с параметром
    Matrix(int s, int rand);                            //Конструктор с параметрами и списком инциализации

    void Matrix_create();                               //Создание матрицы
    void Matrix_print();                                //Вывод Матрицы в консоль
    void Matrix_sum (Matrix&, Matrix&);                 //Сумма Матриц
    void Matrix_inc (Matrix&, Matrix&);                 //Умножение Матриц
    void Matrix_sum (int, Matrix&);                     //Сумма матрицы и числа
    void Matrix_inc (int, Matrix&);                     //Умножение матрицы на число
    bool Matrix_cmp (Matrix&);                          //Сравнение матриц
    int Matrix_det ();                                  //Определитель матрицы
    void Matrix_transp();                               //Транспонирование матрицы
    void get_counter();

    ~Matrix();                                          //Деструктор
};