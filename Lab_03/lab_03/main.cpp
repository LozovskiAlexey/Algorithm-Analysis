#include <iostream>

#include "test.h"

using namespace std;


int main()
{
    bool res = 1;
    while (res){

        cout << "1. User mode." << endl;
        cout << "2. Test time." << endl;
        cout << "3. Test func." << endl;
        cout << "0. Exit." << endl;
        int choice = get_choice();

        switch(choice){
        case 1:
            user_mode();
            break;
        case 2:
            time_test_mode();
            break;
        case 3:
            func_test_mode();
            break;
        case 0:
            res = 0;
            break;
        default:
            cout << "Incorrect input! " << endl;
            break;
        }
    }

    return 0;
}
