#include "executer.h"
#include "log_generator.h"
#include "mytime.h"


static std::chrono::time_point<std::chrono::steady_clock> start;
static std::atomic_int tape_number(0);

// обработка тасков на ленте и передача в следующую очередь
void executer(myqueue& q1, myqueue& q2, Log &log)
{
    int tape_id = ++tape_number;

    std::chrono::time_point<std::chrono::steady_clock> start_awaiting_time; // начало времени ожидания
    bool awaiting = false;                                                  // флаг ожидания очереди
    bool exit = false;

    std::mt19937 gen1(time(nullptr));                             // генератор рандомных чисел
    std::uniform_int_distribution<> urd(1750, 2250);  // устанавливаем распределение


    while(!exit){

        // берем таск из очереди
        auto task = q1.getTask();

        // Если очередь пустая(в случае пустой очереди возвращается таск с номером -1)
        if (task.number != -1)
        {
            // сохраняем время начала работы
            auto time_st = time_point(start);

            // симулируем обработку таска
            auto working_time = urd(gen1);
            std::this_thread::sleep_for(std::chrono::milliseconds(working_time));

            // сохраняем время конца работы
            auto time_end = time_point(start);


            // посылаем данные {номер ленты, номер таска, начало/конец обработки} в лог
            data_t data = init(tape_id, task.number, time_st, time_end);
            log.set(data);


            // передаем task в очередь на обработку дальше
            q2.set(task);

            awaiting = false;  // сброс флага ожидания
        }
        else
        {
            // если очередь пустая, начинаем считать время ожидания
            if (!awaiting){
                awaiting = true;
                start_awaiting_time = std::chrono::steady_clock::now();
            }
            else
            {
                // запоминаем текущее время ожидания
                auto awaiting_time = time_point(start_awaiting_time);

                if (time_is_out(awaiting_time))
                    exit = true;
            }
        }
    }
    return;
}


// та же самая обработка но в очередь ничего после не передает
void executer(myqueue& q1, Log &log)
{
    int tape_id = ++tape_number;

    std::chrono::time_point<std::chrono::steady_clock> start_awaiting_time; // начало времени ожидания
    bool awaiting = false;                                                  // флаг ожидания очереди

    std::mt19937 gen1(time(nullptr));                 // генератор рандомных чисел
    std::uniform_int_distribution<> urd(1750, 2250);  // устанавливаем распределение


    while(1){
        // берем таск из очереди
        auto task = q1.getTask();

        if (task.number != -1)
        {
            // сохраняем время начала работы
            auto time_st = time_point(start);

            // симулируем обработку таска
            auto working_time = urd(gen1);
            std::this_thread::sleep_for(std::chrono::milliseconds(working_time));

            // сохраняем время конца работы
            auto time_end = time_point(start);


            // посылаем данные {номер ленты, номер таска, начало/конец обработки} в лог
            data_t data = init(tape_id, task.number, time_st, time_end);
            log.set(data);

            awaiting = false;  // сброс флага ожидания
        }
        else
        {
            // если очередь пустая, начинаем считать время ожидания
            if (!awaiting){
                awaiting = true;
                start_awaiting_time = std::chrono::steady_clock::now();
            }
            else
            {
                // запоминаем текущее время ожидания
                auto awaiting_time = time_point(start_awaiting_time);

                if (time_is_out(awaiting_time))
                    return;
            }
        }
    }
}


void init_start_time()
{
    start = std::chrono::steady_clock::now();
}

