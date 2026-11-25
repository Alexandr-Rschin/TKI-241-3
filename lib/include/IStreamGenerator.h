#pragma once
#include "Generator.h"
#include <istream>
#include <iostream>

namespace miit::algebra
{
    /**
     * @brief Генератор значений из входного потока (например, с клавиатуры)
     */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream &in;

    public:
        /**
         * @brief Конструктор генератора из потока
         * @param in Входной поток (по умолчанию std::cin)
         */
        explicit IStreamGenerator(std::istream &in = std::cin);

        /**
         * @brief Считать следующее целое число из потока
         * @return Считанное значение
         */
        int generate() override;
    };
}
