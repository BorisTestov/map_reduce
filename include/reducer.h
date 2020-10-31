#pragma once

#include <list>
#include <memory>
#include <string>
#include <thread>
#include <vector>

using typeResultContainer = std::vector<std::string>;

//  Структура задачи для редюсера
struct reducerTask
{
    std::shared_ptr<std::thread> threadTask;
    std::shared_ptr<std::ofstream> fileOut;
};

class Reducer
{
public:
    Reducer() = delete;
    Reducer(typeResultContainer sortedResults, int countReducers);

    /**
     * @brief Запуск редюсеров.
     * Выводит минимальную длину префикса, однозначно идентифицирующую строку, в консоль
     */
    void reduce();

private:
    /**
     * @brief Определение ключа для выбор редюсера
     * @param value - значение
     * @param countReducers - количество редюсеров
     * @return ключ
     */
    unsigned char getKey(std::string value, int countReducers);
    std::list<reducerTask> _reducers;
    typeResultContainer _sortedResults;
    int _countReducers;
};