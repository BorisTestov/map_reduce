#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

using typeResultContainer = std::vector<std::string>;
using typeResultContainerPtr = std::shared_ptr<typeResultContainer>;

class Sorter
{
public:
    Sorter() = default;

    /**
     * @brief сортирует вектора строк, объединяет результат в один вектор
     * @param inputs - вектор указателей на неотсортированные векторы строк
     * @return отсортированный вектор
     */
    typeResultContainer mergeSort(std::vector<typeResultContainerPtr> inputs);
};