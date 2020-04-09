#include "Matrix.h"

int Matrix::counter = 0;    //Инициализация статичской переменной счетчика

int main(){
    srand(time(0));
    //system("chcp 1251");
    int tmp;
    Matrix mtrx_1, mtrx_2;
    Matrix *res;

    cout << "Матрица 1:\n";
    mtrx_1.Matrix_print();
    cout << "Матрица 2:\n";
    mtrx_2.Matrix_print();

    cout << "Сумма Матрицы 1 и Матрицы 2:\n";
    mtrx_1.Matrix_sum(mtrx_2, res);

    cout << "Умножение Матрицы 1 на Матрицу 2:\n";
    mtrx_1.Matrix_inc(mtrx_2, res);

    tmp = rand()%51;
    cout << "Сложение Марицы 1 и числа " << tmp << endl;
    mtrx_1.Matrix_sum(tmp, res);

    tmp = rand()%51;
    cout << "Умножение Марицы 1 на число " << tmp << endl;
    mtrx_1.Matrix_inc(rand()%51, res);

    if (mtrx_1.Matrix_cmp(mtrx_2) == 1)
        cout << "Матрица 1 равна Матрице 2\n";
    else
        cout << "Матрица 1 не равна Матрице 2\n";
    cout << endl;

    cout << "Определитель Матрицы 1 = " << mtrx_1.Matrix_det() << endl;
    cout << "Определитель Матрицы 2 = " << mtrx_2.Matrix_det() << endl;
    cout << endl;

    cout << "Транспонированая Матрица 1:\n";
    mtrx_1.Matrix_transp();
    cout << "Транспонированая Матрица 2:\n";
    mtrx_2.Matrix_transp();

    Matrix def, def2;           //Объект создан с помощю конструктора по умолчанию

    Matrix param(51);           //Объект создан с помощю конструктора с параметрами

    Matrix init(2, 26);         //Объект создан с помощю конструктора с параметрами и списком инициализации

    Matrix cpy(init);           //Объект создан с помощю конструктора копирования

    cout << "Matrix which created with default constructor:\n" << def;

    cin >> init;

    cout << "Def before equal with init:\n" << def;
    def = param;
    cout << "Def after equal with init:\n" << def;

    cout << "Def before sum with num:\n" << def;
    def+10;
    cout << "Def after sum with num:\n" << def;

    cout << "Def before sum with def2:\n" << def;
    def+def2;
    cout << "Def after sum with def2:\n" << def;

    cout << "Def before increasing:\n" << def;
    def*2;
    cout << "Def after increasing:\n" << def;

    Matrix::get_counter();
}
