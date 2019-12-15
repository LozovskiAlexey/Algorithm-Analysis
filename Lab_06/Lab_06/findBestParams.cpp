#include "findBestParams.h"


params_t find_best(map_t<size_t> mtx, double a, double p){

    // границы диапазонов параметров, которые ищем
    auto limit_a = a + 1.0;
    auto limit_p = p + 1.0;
    auto start_p = p;

    //double eps = 2; // возможная реализация работы с eps
    //double repeats = 0;
    //double prev;

    // поиск пути методом полного перебора
    auto best = get_best_path(mtx, 0)();


    Ant ant;
    params_t prm;
    int iterations;


    double step = 0.1;
    double q = best / mtx.size();
    auto t = TMAX;
    prm.init(best, t, a, p); // инициализируем стартовые параметры

    std::cout << "a \t b \t p \t iters \t distance" << std::endl;

    // проходим по всем параметрам a, p
    while (a <= limit_a){
        p = start_p;
        while (p <= limit_p){

            // считаем количество итераций для каждого набора
            iterations = 0;

            // инициализируем - обновляем значения
            Map map = Map(mtx, a, p, q);
            colony_t colony = init(&map);

            //repeats = 0;
            //prev = cycle(map, colony).getPathDistance();

            do {
                // выполняем пока не найдем идеальный путь
                // либо пока не превысим количество итераций
                ant = cycle(map, colony);

                //if (std::abs(ant.getPathDistance() - prev) < eps)
                //   repeats += 1;

                iterations++;

                if (iterations > TMAX)
                    break;

            } while (ant.getPathDistance() != prm.len);
            //} while (repeats < 3);

            // выводим полученные данные
            std::cout << a << " \t "
                      << CONST - a <<  " \t "
                      << p << " \t "
                      << iterations << " \t"
                      << ant.getPathDistance()
                      << std::endl;

            // обновление данных
            if (iterations < prm.iter){
                prm.update(iterations, a, p);
            }

            p += step;
        }
        std::cout << " ============================= " << std::endl;
        a += step;
    }

    return prm;
}
