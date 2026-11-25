#pragma once
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Генератор константного значения
     */
    class ConstGenerator : public Generator
    {
    private:
        int value;

    public:
        /**
         * @brief Конструктор генератора константы
         * @param value Константное значение
         */
        explicit ConstGenerator(const int value);

        /**
         * @brief Вернуть заданную константу
         * @return Константное целое число
         */
        int generate() override;
    };
}
