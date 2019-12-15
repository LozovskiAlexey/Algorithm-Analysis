#include "test.h"

using namespace std;


static string PATH = "C:\\Users\\mrado\\OneDrive\\Desktop\\Labs\\semester5\\AA\\lab_04\\lab_04\\";


void show(mtx_t *mtx)
{
    for (int i=0; i<mtx->r; i++)
    {
        for(int j=0; j<mtx->c; j++)
            cout << mtx->mtx[i][j] << " ";
        cout << endl;
    }
}

// ================== ЭКСПЕРИМЕНТАЛЬНЫЙ РЕЖИМ =====================

//счетчик времени
double timer(mtx_t *A, mtx_t *B, int n, mtx_t* (* mult)(mtx_t*, mtx_t*, int))
{
    mtx_t *res = nullptr;

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    res = mult(A, B, n);
    end = std::chrono::system_clock::now();

    double time = std::chrono::duration_cast<std::chrono::nanoseconds>
            (end-start).count();

    release_mtx(res);

    return time/1e9;
}


/*
 * На вход размер матрицы, количество потоков и функция, которой умножать
 * посчитает время для заданной размерности умножение 10 раз и
 * вернет усредненное значение.
*/
double test(int size, int n, mtx_t* (* mult)(mtx_t*, mtx_t*, int))
{
    int iterations = 10;
    double time = 0;

    mtx_t *A = generate_mtx(size, size);
    mtx_t *B = generate_mtx(size, size);

    fill_mtx(A);
    fill_mtx(B);

    for (int i=0; i<iterations; i++)
        time += timer(A, B, n, mult);

    time /= static_cast<double>(iterations);

    release_mtx(A);
    release_mtx(B);

    return time;
}


/*
 * Получает на вход имя файла, куда записывать информацию,
 * начальный и конечный размер матрицы, количество потоков и
 * функцию которой умножать.
 * Считает время работы умножения на матрицах разных размерностей.
*/
void test_wrapee(string file, int size, int limit, int n, mtx_t* (* mult)(mtx_t*, mtx_t*, int))
{
    double time = 0;

    ofstream fout;

    fout.open(file, ios::out);

    fout.setf(ios::fixed);
    while (size <= limit)
    {
        time = test(size, n, mult);
        fout << "(" << size << ", " << time << ") " << endl;
        size += 100;
    }

    fout.close();
    cout << "file " << file << " operation completed" << endl;
}


/*
 * Экспериментальный режим, для матриц размерностей от
 * 100...1000, с шагом 100, считает время работы алгоритма
 * умножения для 2...1024 потоков.
*/
void exp_mode()
{
    int st = 101;
    int fin = 1001;

    int thread_counter = 2;

    for (; thread_counter<=256; thread_counter*=2)
    {
        string num = to_string(thread_counter);
        string file = "parallel_vinograd" +  num + ".txt";
        test_wrapee(PATH + file, st, fin, thread_counter, vinograd);
    }
}


// ================== ПОЛЬЗОВАТЕЛЬСКИЙ РЕЖИМ =====================
/*
 * Функция считает время для умножения матриц, размера
 * заданного пользователем, при количестве потоков, заданных все
 * тем же пользователем.
*/
void user_time_mode()
{
    int n = 0;                      // Число потоков
    int size = 100;                 // Размер квадратной матрицы

    set(n, "thread number: ");      // Установить значения в n, size
    set(size, "matrix size(M): ");

    double time = 0.0;              // Время

    time = test(size, n, vinograd); // Считаем усредненное время

    cout << "size: " << size << "; time: " << time << endl;
}


/*
 * Пользователь задает количество потоков и размер матрицы
 * функция умножит две квадратные матрицы, выведет введенные
 * пользователем матрицы и результирующую
 * Зачем?
 * Ну чтобы удостовериться, что оно вообще работает
*/
void user_func_test()
{
    int n = 0;              // Число потоков
    int size = 100;         // Размер квадратной матрицы

    set(n, "thread number: ");
    set(size, "matrix size(M): ");


    int choice = 0;

    show_menu();
    set(choice, "number: ");


    mtx_t *A = nullptr;
    mtx_t *B = nullptr;

    switch(choice)
    {
    case 1:
        A = generate_mtx(size, size); // генерация единичных матриц
        B = generate_mtx(size, size); // во всяком случае, по задумке

        fill_mtx(A);
        fill_mtx(B);

        cout << "Matrix A:" << endl;
        show(A);

        cout << "Matrix B:" << endl;
        show(B);

        break;
    case 2:
        A = set_mtx(size, size);
        B = set_mtx(size, size);

        // Тут матрицы не отображаем, потому что
        // при вводе в консоль и так видны заданные матрицы

        break;
    }


    mtx_t *C = nullptr;

    C = vinograd(A, B, n);


    cout << "Result matrix: " << endl;
    show(C);
}


/*
 * Установка значениия с простой проверкой ввода, одному
 * господу богу нашему известно на кой черт это написано
 * но что сделано, то сделано
*/
void set(int &n, const std::string info)
{
    string text = "Input " + info;

    cout << text;

    while (!(cin >> n)){
        cout << "Incorrect input!" << endl;
        cout << text;
    }
}


/*
 * Одна из лучших функций этого кода, просто и со вкусом.
 * Используется в user_func_mode()
*/
void show_menu()
{
    cout << "1. Generate unit matrixes." << endl;
    cout << "2. Set matrixes from console." << endl;
}


/*
 * Заполнение матрицы из консоли
*/
mtx_t *set_mtx(int rows, int cols)
{
    mtx_t *mtx = generate_mtx(rows, cols);


    cout << "Input Matrix: " << endl;


    for (int i=0; i < rows; i++)
        for (int j=0; j < cols; j++)
            cin >>mtx->mtx[i][j];


    return mtx;
}


void user_mode()
{
    int choice = 1;

    cout << "1. Check time." << endl;
    cout << "2. Check work." << endl;
    cout << "0. Exit." << endl;

    set(choice, "number: ");

    while (choice != 0){
        switch(choice)
        {
        case 1:
            user_time_mode();
            break;

        case 2:
            user_func_test();
            break;

        case 0:
            return;

        default:
            cout << "Incorrect input! "<< endl;
            break;
        }

        cout << "1. Check time." << endl;
        cout << "2. Check work." << endl;
        cout << "0. Exit." << endl;

        set(choice, "number: ");
    }
}


