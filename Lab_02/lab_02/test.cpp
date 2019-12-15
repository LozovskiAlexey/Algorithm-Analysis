#include "test.h"


using namespace std;

static string PATH = "C:\\Users\\mrado\\OneDrive\\Desktop\\Labs\\semester5\\AA\\lab_02\\lab_02\\";
static string OUT_PATH = "C:\\Users\\mrado\\OneDrive\\Desktop\\Labs\\semester5\\AA\\lab_02\\test_data\\";

// =============================== СЧИТАЕМ ВРЕМЯ =======================================

/*
 * Считает время для сортировки массива arr размера size
 * заданной сортировкой
*/
double timer(int *arr, int size, void (* sort)(int*, int))
{
    auto start = clock();
    sort(arr, size);
    auto end = clock();

    auto time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    return time;
}

/*
 * Тестирование времени, получает размер массива, генерирует его, считает
 * усредненное время и освобождает память, возвращает время.
*/
double test(int size, int* (* generator)(int), void (* sort)(int*, int))
{
    int *data;
    int iterations = 5;
    double time = 0;

    // Считаем время работы
    for (int i=0; i < iterations; i++)
    {
        data = generator(size);
        time += timer(data, size, sort);
        release_data(data);
    }

    time /= static_cast<double>(iterations);

    //cout.setf(ios::fixed);
    //std::cout <<"Processing time = " << time << ", size = " << size << std::endl;

    return time;
}


/*
 * Запускает тестирование времени программы для массивов заданной внутри функции
 * размерности (100...1000). Запись происходит в файл в формате (Размер, время).
*/
void test_wrapee(string file,  int* (* generator)(int), void (* sort)(int*, int))
{
    int size = 100;
    int limit = 1000;
    double time = 0;

    ofstream fout;
    fout.open(file, ios::out);

    while (size <= limit)
    {
        time = test(size, generator, sort);
        fout << "(" << size << ", " << time << ") " << endl;
        size += 100;
    }

    fout.close();
}


/*
 * Отображает массив, который в нее подали
*/
void show(int *arr, int n)
{
    for (int i=0; i<n; i++)

        cout<<arr[i] << " ";

    cout<<endl;
}


/*
 *  Получает на вход файл(с путен, потому что у меня иначе файл не находит),
 *  генератор данных и тип сортировки.
*/
void time_test_mode()
{
    test_wrapee(PATH + "sorted_buble_sort.txt", create_sorted, buble_sort);
    test_wrapee(PATH + "randomed_buble_sorted.txt", create_random, buble_sort);
    test_wrapee(PATH + "reversed_sorted.txt", create_reversed, buble_sort);

    test_wrapee(PATH + "sorted_insertion_sort.txt", create_sorted, insertion_sort);
    test_wrapee(PATH + "randomed_insertion_sort.txt", create_random, insertion_sort);
    test_wrapee(PATH + "reversed_insertion_sort.txt", create_reversed, insertion_sort);

    test_wrapee(PATH + "sorted_selection_sort.txt", create_sorted, selection_sort);
    test_wrapee(PATH + "randomed_selection_sort.txt", create_random, selection_sort);
    test_wrapee(PATH + "reversed_selection_sort.txt", create_reversed, selection_sort);
}


// ========================= ФУНКЦИОНАЛЬНОЕ ТЕСТИРОВАНИЕ ==============================

int* get_array_from_file(string file_name){

    int *array =  new int[10];

    ifstream in(file_name);


    if (in.is_open()){

        for (int i=0; i<10; i++)
            in >> array[i];

        in.close();
    }
    else
        cout << "Failed to open file." << endl;

    return array;
}


void run_test(int *arr, int* exp_arr,  void (* sort)(int*, int)){


    int n = 10;


    sort(arr, n);


    cout << "Expected array: "<<endl;
    show(exp_arr, n);
    cout <<endl << "Result array: "<<endl;
    show(arr, n);


    string res = compare(arr, exp_arr) ? "COMPLETED!" : "FAILED!";
    cout << "Test: " << res << endl << endl;

}


bool compare(int *arr, int* exp_arr)
{
    int n = 10;
    bool res = 1;

    for (int i=0; i<n; i++)
        if (arr[i] != exp_arr[i]){

            res = 0;
            break;
        }
    return res;
}


void process_data(string f1, string f2, void (* sort)(int*, int)){

    int * arr = get_array_from_file(f1);
    int * exp_arr = get_array_from_file(f2);

    if (arr and exp_arr)
        run_test(arr, exp_arr, sort);
    else
        cout << "something went wrong"<<endl;
}

void func_test_mode()
{
    int n = 3; // количество тестов

    string A_file, B_file, C_file;
    string num;

    cout << " =============== BUBLE SORT ================" << endl;
    for (int i=1; i<=n; i++){

        num = to_string(i);

        A_file = OUT_PATH + "A" + num + ".txt";
        C_file = OUT_PATH + "RES" + num + ".txt";

        process_data(A_file, C_file, buble_sort);

    }

    cout << " =============== ISERTION SORT ================" << endl;
    for (int i=1; i<=n; i++){

        num = to_string(i);

        A_file = OUT_PATH + "A" + num + ".txt";
        C_file = OUT_PATH + "RES" + num + ".txt";

        process_data(A_file, C_file, insertion_sort);

    }

    cout << " ============= SELECTION SORT =============" << endl;
    for (int i=1; i<=n; i++){

        num = to_string(i);

        A_file = OUT_PATH + "A" + num + ".txt";
        C_file = OUT_PATH + "RES" + num + ".txt";

        process_data(A_file, C_file, selection_sort);

    }

    cout << endl << endl;
}



// =========================== ПОЛЬЗОВАТЕЛЬСКИЙ РЕЖИМ =================================


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

    cout << "1. Buble sort." << endl;
    cout << "2. Insertion sort." << endl;
    cout << "3. Selection sort." << endl;
    cout << "0. Exit." << endl;

}


int *set_array(int &n)
{
    n = 10;

    cout << "Input array size (N): ";

    int *array = nullptr;

    if (cin >> n){
        array = new int[n];

        cout << "Input array: ";
        for (int i=0; i < n; i++)
            cin >>array[i];
    }
    else {
        cout << "Incorrect input!" << endl;
    }

    return array;
}


void user_mode()
{
    int n = 0;

    // Ввод массива
    int *arr = set_array(n);

    // Вывод меню с выбором алгоритма
    show_menu();

    // Ввод числа с выбором алгоритмом + простая проверка ввода
    int choice = get_choice();


    // Запуск алгоритма
    switch(choice)
    {
    case(1):
        buble_sort(arr, n);
        break;
    case(2):
        insertion_sort(arr, n);
        break;
    case(3):
        selection_sort(arr, n);
        break;
    case(0):
        break;

        // Если со вводом все же лажа, то ловите ругань
        // К слову, после лажи ничего вас не ждет, так что живите с этим.
    default:
        cout << "Incorrect input!" << endl;
        break;
    }

    cout << "result: ";
    show(arr, n);
}
