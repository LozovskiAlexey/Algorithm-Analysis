#include "test.h"

using namespace std;

static string OUT_PATH = "C:\\Users\\mrado\\OneDrive\\Desktop\\Labs\\semester5\\AA\\lab_03\\lab_03\\";
static string IN_PATH = "C:\\Users\\mrado\\OneDrive\\Desktop\\Labs\\semester5\\AA\\lab_03\\test_data\\";


// ======================== ТЕСТИРУЕМ ВРЕМЯ ============================

// Вывод матрицы в консоль

void show(mtx_t *mtx)
{
    for (int i=0; i<mtx->r; i++)
    {
        for(int j=0; j<mtx->c; j++)
            cout << mtx->mtx[i][j] << " ";
        cout << endl;
    }
}


// Счетчик времени для умножения двух матриц

double timer(mtx_t *A, mtx_t *B, mtx_t* (* mult)(mtx_t*, mtx_t*))
{
    mtx_t *res = nullptr;

    auto start = clock();
    res = mult(A, B);
    auto end = clock();

    auto time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    release_mtx(res);

    return time;
}


/*
 * Деляем таймер круче, теперь это чудо генерит матрицу
 * и считает время умножения сколько душе угодно
 * Возвращает усредненное время
*/
double test(int size, mtx_t* (* mult)(mtx_t*, mtx_t*))
{
    int iterations = 5;
    double time = 0;

    mtx_t *A = generate_mtx(size, size);
    mtx_t *B = generate_mtx(size, size);

    fill_mtx(A);
    fill_mtx(B);

    for (int i=0; i<iterations; i++)
        time += timer(A, B, mult);

     time /= static_cast<double>(iterations);

    release_mtx(A);
    release_mtx(B);

    return time;
}


/*
 * Выше test'ом мы считали усредненное время для N умножений матрицы
 * А теперь мы будем считать усредненное время для для матриц размером в
 * даипазоне, заданным пользователем (size, limit) и записывать данные в
 * файл в формате (size, time)
*/
void test_wrapee(string file, int size, int limit, mtx_t* (* mult)(mtx_t*, mtx_t*))
{
    double time = 0;

    ofstream fout;

    fout.open(OUT_PATH + file, ios::out);

    while (size <= limit)
    {
        time = test(size, mult);
        fout << "(" << size << ", " << time << ") " << endl;
        size += 100;
    }

    fout.close();
    cout << "file " << file << " operation completed" << endl;
}


/*
 * Тесты для алгоритмов
 * На вход - имя файла, начальный, конечный размер, алгоритм умножения
 * Записывают в файл пары (размер матрицы, время выполнения)
*/
void time_test_mode()
{
    int st = 100;
    int fin = 1000;

    // Для квадратных матриц четной размерности
    test_wrapee("standart.txt", st, fin, standart);
    test_wrapee("vinograd.txt", st, fin, vinograd);
    test_wrapee("super_vinograd.txt", st, fin, super_vinograd);


    st++;
    fin++;

    // Для нечетной размерности
    test_wrapee("uneven_standart.txt", st, fin, standart);
    test_wrapee("uneven_vinograd.txt", st, fin, vinograd);
    test_wrapee("uneven_super_vinograd.txt", st, fin, super_vinograd);

}



// ===================== ПОЛЬЗОВАТЕЛЬСКИЙ РЕЖИМ ========================

// Ввод матрицы в консоли

mtx_t *set_mtx()
{
    int rows, cols;

    cout << "Input matrix size (N, M): ";
    cin >> rows >> cols;


    mtx_t *mtx = generate_mtx(rows, cols);


    cout << "Input Matrix: " << endl;


    for (int i=0; i < rows; i++)
        for (int j=0; j < cols; j++)
            cin >>mtx->mtx[i][j];

    return mtx;
}


// Получаение значения числа, введенного в консоли с небольшой проверкой
// вводе, кстати, возможно, она не работает, но кого это волнует

int get_choice()
{

    int choice;

    cout << "Input number: ";

    while (!(cin >> choice) || choice > 3 || choice < 0){

        cout << "Incorrect input! " << endl;
        cin.clear();
        fflush(stdin);

        cout << "Input number: ";
    }

    return choice;
}


// Показываем офигенную менюшку с названием алгоритмов

void show_menu()
{

    cout << "1. Standart algorithm" << endl;
    cout << "2. Winograd algorithm" << endl;
    cout << "3. Winograd optimization" << endl;
    cout << "0. Exit" << endl;

}


/*
 * Собственно, то, ради чего все это было сделано
 * Тот самый гениальный пользовательский режим, который мы все ждали
 * На вход записываются в консоль размеры матрицы
 * Каждая матрица заполняется с консоли
 * Выбирается как будем умножать введенные матрицы
 * Умножаем матрицы
 * Получаем результат или плевок в лицо
*/
void user_mode()
{
    // Ввод матриц
    mtx_t *A = set_mtx();

    mtx_t *B = set_mtx();

    mtx_t *C = nullptr;


    // Вывод меню с выбором алгоритма
    show_menu();
    // Ввод числа с выбором алгоритмом + простая проверка ввода
    int choice = get_choice();


    // Запуск алгоритма
    switch(choice)
    {
    case(1):
        C = standart(A, B);
        break;
    case(2):
        C = vinograd(A, B);
        break;
    case(3):
        C = super_vinograd(A, B);
        break;
    case(0):
        break;

    // Если со вводом все же лажа, то ловите ругань
    // К слову, после лажи ничего вас не ждет, так что живите с этим.
    default:
        cout << "Incorrect input!" << endl;
        break;
    }


    // Если матрица каким-то чудом была посчитана, от нее нужно избавиться
    if (C){
        cout << "Result: " << endl;

        show(C);
        release_mtx(C);
    }
    else
        cout << "Something went wrong..." << endl;


    // Тотально заметаем следы преступления
    release_mtx(A);
    release_mtx(B);
}



// ===================== ФУНКЦИОНАЛЬНОЕ ТЕСТИРОВАНИЕ ========================


// Сравнивает матрицы

bool compare(mtx_t *C, mtx_t *EXP_C)
{
    bool res;

    res = C->c == EXP_C->c and C->r == EXP_C->r ? 1 : 0;

    if (res == 1)
    {
        for (int i=0; i< C->r; i++)
            for (int j=0; j<C->c; j++){
                if (C->mtx[i][j] != EXP_C->mtx[i][j]){
                    res = 0;
                    break;
                }
            }
    }

    return res;
}

// Чтение файла из матрицы

mtx_t *get_mtx_from_file(string file_name)
{
    mtx_t *mtx = nullptr;

    ifstream in(file_name);

    if (in.is_open()){

        int count = 0;
        int tmp;

        // проходим по файлу, считаем сколько всякого добра тут есть

        while (!in.eof()){

            in >> tmp;
            count++;
        }

        // В конце нам не нравится, вернулись в начало
        in.seekg(0, ios::beg);
        in.clear();

        int count_space = 0; // пробелы в строке
        char symbol;

        while (!in.eof()){

            in.get(symbol);

            // считаем пробелы
            if (symbol == ' ')
                count_space++;

            // конец строки? не проблема - мы уходим
            if (symbol == '\n')
                break;
        }
        count_space++;

        in.seekg(0, ios::beg);
        in.clear();

        int r = count / count_space;
        int c = count_space;

        mtx = generate_mtx(r, c);

        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++)
                in >> mtx->mtx[i][j];

        in.close();
    }
    else
        cout << "Failed to open file." << endl;

    return mtx;
}


/*
 * Функция тестирования, получает на вход три матрицы, две, что надо умножить
 * и ожидаемый результат. Умножает матрицы заданным алгоритмом, сравнивает с ожидаемым результатом
 * Выводит результат + ожидаемый результат + результат тестирования.
*/
void func_test(mtx_t *A, mtx_t *B, mtx_t *EXP_C, mtx_t* (* mult)(mtx_t*, mtx_t*))
{
    cout << "=============== TEST ==================" << endl;

    mtx_t* C = mult(A, B);

    string result = compare(C, EXP_C) == 1 ? "COMPLETE!" : "FAILED!";

    cout << "Expected result: " << endl;
    show(EXP_C);

    cout << endl << "Function result: " << endl;
    show(C);

    cout << "Test: " << result << endl;
}


 /*
  * Обертка для функциональных тестов, подается файл и функция умножения - это чудо
  * все запускает.
*/
void process_data(string f1, string f2, string f3, mtx_t* (* mult)(mtx_t*, mtx_t*))
{

    mtx_t *A = get_mtx_from_file(f1);
    mtx_t *B = get_mtx_from_file(f2);
    mtx_t *C = get_mtx_from_file(f3);

    if (A and B and C)
        func_test(A, B, C, mult);

}


/*
 * УМОПОМРАЧИТЕЛЬНЫЕ ТЕСТЫ, ЛУЧШИЕ ИЗ ТЕХ, ЧТО Я ПИСАЛ
 * НИЧЕГО ГЕНИАЛЬНЕЕ ЭТОТ СВЕТ НЕ ВИДЕЛ, ПРОСТО ТИСД ОТДЫХАЕТ
 * ЛЮБЛЮ УМИРАЮ!
 * ПРОГРАММИРОВАНИЕ ТОП
*/
void func_test_mode()
{
    int n = 3; // количество тестов

    string A_file, B_file, C_file;
    string num;

    cout << "===============STANDART================" << endl;
    for (int i=1; i<=n; i++){

        num = to_string(i);

        A_file = IN_PATH + "A" + num + ".txt";
        B_file = IN_PATH + "B" + num + ".txt";
        C_file = IN_PATH + "C" + num + ".txt";

        process_data(A_file, B_file, C_file, standart);

    }

    cout << "===============WINOGRAD================" << endl;
    for (int i=1; i<=n; i++){

        num = to_string(i);

        A_file = IN_PATH + "A" + num + ".txt";
        B_file = IN_PATH + "B" + num + ".txt";
        C_file = IN_PATH + "C" + num + ".txt";

        process_data(A_file, B_file, C_file, vinograd);

    }

    cout << "=============SUPER WINOGRAD=============" << endl;
    for (int i=1; i<=n; i++){

        num = to_string(i);

        A_file = IN_PATH + "A" + num + ".txt";
        B_file = IN_PATH + "B" + num + ".txt";
        C_file = IN_PATH + "C" + num + ".txt";

        process_data(A_file, B_file, C_file, super_vinograd);

    }

    cout << endl << endl;
}
