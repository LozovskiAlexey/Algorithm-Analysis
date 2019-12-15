#include <thread>
#include <ctime>
#include <string>

#include "test.h"


int menu()
{
    int n;
    cout << " 1. User mode; " << endl;
    cout << " 2. Experinmetal mode; " << endl;
    cout << " 0. Exit; " << endl;
    cout << "Choose number: ";
    cin >> n;

    return n;
}


int main() {

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
            exp_mode();
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


