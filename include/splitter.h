#pragma once

#include <fstream>
#include <string>
#include <vector>

class Splitter
{
public:
    Splitter() = delete;
    Splitter(std::string filename, int countMaps);

    /**
     * @brief - Разбивает файл на части
     * @return вектор с позициями частей
     */
    std::vector<std::iostream::pos_type> split();

private:
    std::ifstream _file;
    int _countMaps;
};