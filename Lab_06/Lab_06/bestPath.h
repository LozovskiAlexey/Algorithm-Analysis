#ifndef BESTPATH_H
#define BESTPATH_H

#include "path.h"

template <typename T>
using map_t = std::vector<std::vector<T>>;

template <typename T>
void find_best(const map_t<T> map, Path &path, Path &best){

    if (path.isFinished()){

        // добавить первый элемент
        size_t first = path.first();
        size_t last = path.last();

        // добавить к длине пути длину расстояния до старта
        path.addToVisited(first);
        path() += map[last][first];

        if (best() == 0 or path() < best())
            best = path;

        return;
    }


    size_t start = path.last();
    size_t distance;
    Path tmp_path;


    for (size_t target = 0; target < path.verticles(); target++){

        // Вычисляем расстояние между стартовым и целевым городом
        distance = map[start][target];
        tmp_path = path;

        if (!tmp_path.isVisited(target) and distance != 0){

            tmp_path.addToVisited(target); // добавляем город в посещенные
            tmp_path() += distance; // увеличиваем длину пути

            find_best(map, tmp_path, best); // уходим на рекурсивное дно
        }
    }
}

template <typename T>
Path get_best_path(const map_t<T> map, size_t start){
    Path best;

    Path path = Path(map.size());
    path.addToVisited(start);

    find_best(map, path, best);

    return best;
}

template <typename T>
void show(map_t<T> map){
    std::cout << std::endl;

    auto size = map.size();

    for (size_t i=0; i<size; i++){

        for(size_t j=0; j<size; j++){
            //if (j == 0){
            //    std::cout << map[i][j] << ", \t";
            //}else
            //    std::cout << "&" << map[i][j] << " \t";
            std::cout << map[i][j] << " \t";
        }
        //std::cout << "\\" << "\\" << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
}



#endif // BESTPATH_H
