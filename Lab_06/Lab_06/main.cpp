#include "bestPath.h"
#include "generator.h"
#include "findBestParams.h"

using namespace std;

int main(){

    int start, end;
    size_t size;

    cout << "set matrix data range (start end): ";
    cin >> start >> end;

    cout << "set matrix size: ";
    cin >> size;

    Generator gen1(start, end);
    auto map = gen1(size);


    show(map);


    auto prms = find_best(map, 0.0, 0.0);
    prms.show();

    return 0;
}
