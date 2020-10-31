#pragma once

#include <fstream>
#include <functional>
#include <list>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using typeResultContainer = std::vector<std::string>;
using typeResultContainerPtr = std::shared_ptr<typeResultContainer>;

//  Структура задачи для маппера
struct mapTask
{
    std::shared_ptr<std::thread> threadTask;
    typeResultContainerPtr ptrResult;
};

class Mapper
{
public:
    Mapper() = delete;
    Mapper(std::string filename, int countMaps);

    /**
     * @brief Запуск маппера
     * @param borders - вектор с позициями частей в файле (см. @splitter)
     * @return вектор указателей на вектора строк
     */
    std::vector<typeResultContainerPtr> map(std::vector<std::iostream::pos_type> borders);

private:
    std::ifstream _file;
    int _countMaps;
};
