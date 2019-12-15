#include <iostream>
#include <vector>

#include "test.h"

using namespace std;

int main()
{  
    int cmd;

    cout << "0 Exit." << endl
         << "1 Find substring." << endl
         << "Input digit: ";

    cin >> cmd;

    while (cmd == 1){

        string  str;
        string substr;

        cout << "Input string: ";
        cin >> str;

        cout << "input substring: ";
        cin >> substr;

        int res;

        res = standart(str, substr);
        cout << "Standart algorithm execution result: " << res << endl;

        res = kmp(str, substr);
        cout << "KMP algorithm execution result: " << res << endl;

        res = bm(str, substr);
        cout << "BM algorithm execution result: " << res << endl;

        cout << "0 Exit." << endl
             << "1 Find substring." << endl
             << "Input digit: ";

        cin >> cmd;
    }
    return 0;
}
