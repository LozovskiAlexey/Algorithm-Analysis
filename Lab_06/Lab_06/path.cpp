#include "path.h"

Path::Path(){
    length = 0;
}

// помещается количество вершин, необходимых
// к посещению
Path::Path(size_t amount){
    vert = amount;
    length = 0;
}

// пометит город как посещенный
void Path::addToVisited(size_t city){
    visited.push_back(city);
}

// удалит город из просмотренных
void Path::removeFromVisited(){
    visited.pop_back();
}

// вернет последний посещенный город
size_t Path::last(){
    return visited.back();
}

// вернет первый посещенный город
size_t Path::first(){
    return visited.front();
}

// считает количество посещенных городов
size_t Path::countVisited(){
    return visited.size();
}

// вернет количество вершин
size_t Path::verticles(){
    return vert;
}

// проверяет путь на полноту
bool Path::isFinished(){
    return (vert == countVisited());
}

// вернет длину пути
size_t& Path::operator()(){
    return length;
}

// проверяет если вершина была посещена
bool Path::isVisited(size_t city){
    bool found = 0;

    for (size_t tmp : visited)
        if (tmp == city)
            found = 1;
    return found;
}


void Path::show(){
    std::cout << "Path: ";

    for (auto city : visited)
        std::cout << city << " ";

    std::cout << std::endl;
}


