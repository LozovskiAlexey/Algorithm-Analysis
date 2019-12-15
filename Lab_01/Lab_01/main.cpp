#include <iostream>
#include <string>

#include "user_mode.h"
#include "func_testing.h"
#include "time_testing.h"

int menu()
{
    int n;
    cout << " 1. User-mode; " << endl;
    cout << " 2. Func testing-mode; " << endl;
    cout << " 3. Time testing-mode; " << endl;
    cout << " 0. Exit; " << endl;
    cout << "Choose number: ";
    cin >> n;

    return n;
}


// Пользовательский режим
int main()
{  
    setlocale(LC_ALL, "rus");

    int n = menu();

    while (1)
    {
        switch(n)
        {
        case 1:
            user_mode();
            break;
        case 2:
            func_testing_mode();
            break;
        case 3:
            time_testing_mode();
            break;
        case 0:
            return 0;
        default:
            cout << "incorrect input! " << endl;
            break;
        }

        n = menu();
    }
}
