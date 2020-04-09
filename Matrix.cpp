#include "Matrix.h"

/*
 * КОНСТРУКТОРЫ
 */

//Конструктор по умолчанию
Matrix::Matrix() {
    counter++;
    random = 26;
    Matrix_create();
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j]=rand()%random;
}

/*
 * Конструктор с параметром
 * При вызове позволяет указать в каком диапазоне буду элементы матрицы
 */
Matrix::Matrix(int r) {
    counter++;
    random = r;
    Matrix_create();
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j]=rand()%random;
}

/*
 * Конструктор с параметрами и списком инциализации
 * При вызове позволяет указать размер матрицы, в каком диапазоне буду её элементы
 * и проинициальзировать переменные size и random соответственно
 */
Matrix::Matrix(int s, int r) : size(s), random(r) {
    counter++;
    Matrix_create();
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j] = rand()%random;
}

/*
 * Конструктор копирования
 * Используется для копирования полей из другого объекта исходного класса
 * Для переменной size используется инициализация так как это поле константное
 * random инициализируется в теле конструктора
 */
Matrix::Matrix(const Matrix &matrix) {
    counter++;
    random = matrix.random;
    Matrix_create();
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j] = rand() % random;
    cout << "Copy constructor worked here!\n\n";
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
void Matrix::Matrix_sum(Matrix& b, Matrix* res) {
    if (size != b.size) {
        cout << "Sizes must be equal -> Sum imposible\n";
        return;
    }
    res = new Matrix(size, 1);

    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            res->Mtrx[i][j] = Mtrx[i][j] + b.Mtrx[i][j];

    res->Matrix_print();

    delete res;
    res = nullptr;
}

//Сумма матрицы и числа
void Matrix::Matrix_sum (int num, Matrix* res) {
    res = new Matrix(size, 1);

    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            res->Mtrx[i][j] = Mtrx[i][j] + num;

    res->Matrix_print();

    delete res;
    res = nullptr;
}

//Умножение матриц
void Matrix::Matrix_inc (Matrix& b, Matrix* res) {
    if (size != b.size) {
        cout << "Sizes doesn't match -> Increase imposible\n";
        return;
    }

    res = new Matrix(size, 1);

    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++) {
            res->Mtrx[i][j] = 0;
            for(int k(0); k < size; k++)
                res->Mtrx[i][j] += Mtrx[i][k] * b.Mtrx[k][j];
        }

    res->Matrix_print();

    delete res;
    res = nullptr;
}

//Умножение матрицы на число
void Matrix::Matrix_inc (int num, Matrix* res) {
    res = new Matrix(size, 1);

    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            res->Mtrx[i][j] = Mtrx[i][j] * num;

    res->Matrix_print();

    delete res;
    res = nullptr;
}

//Сранвнение мтариц
bool Matrix::Matrix_cmp (Matrix& b) {
    if(size != b.size) return 0;
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
//Перегрузка оператора << для вывода матрицы в консоль
ostream& operator<<(ostream &out, const Matrix &m) {
    out << "Overloaded operator << for outputting Mtrx\n";
    for (int i(0); i < m.size; i++) {
        for (int j(0); j < m.size; j++)
            out<<m.Mtrx[i][j]<<" ";
        out<<endl;
    }
    out << endl;

    return out;
}

//Перегрузка оператора >> для ввода матрицы с консоли
istream& operator>>(istream &in, Matrix &m) {
    cout << "Overloaded operator >> for inputting Mtrx\n";
    cout << "Введите Матрицу " << m.size << "x" << m.size << ":\n";
    for (int i(0); i < m.size; i++) {
        for (int j(0); j < m.size; j++)
            in >> m.Mtrx[i][j];
    }
    cout << endl;

    return in;
}

//Перегрузка оператора = для копирования значений матрицы из одного объекта в другой
Matrix& Matrix::operator=(Matrix &matrix) {
    if(size == matrix.size)
        for (int i(0); i < size; i++)
            for (int j(0); j < size; j++)
                Mtrx[i][j] = matrix.Mtrx[i][j];
    else
        cout << "Sizes doesn't match" << endl;

    cout << "Overloaded operator = for Matrix obj and Matrix obj\n";

    return *this;
}

//Перегрузка оператора + для суммирования матрицы с числом
void Matrix::operator+ (int num) {
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j] += num;
    cout << "Overloaded operator + for Matrix obj and num\n";
}

//Перегрузка оператора + для суммирования одной матрицы с другой
void Matrix::operator+ (const Matrix &matrix) {
    if (size != matrix.size) {
        cout << "Sizes must be equal -> Sum imposible\n";
        return;
    }
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j] += matrix.Mtrx[i][j];
    cout << "Overloaded operator + for Matrix obj and Matrix obj\n";
}

//Перегрузка оператора * для умножения матрицы на число
void Matrix::operator* (int num) {
    for (int i(0); i < size; i++)
        for (int j(0); j < size; j++)
            Mtrx[i][j] *= num;
    cout << "Overloaded operator * for Matrix obj and num\n";
}

//Деструктор
Matrix::~Matrix() {
    for (int i(0); i < size; i++)
        delete[] Mtrx[i];
    delete[] Mtrx;
}
