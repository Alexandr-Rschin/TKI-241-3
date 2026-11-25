#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Задача 2 (Вариант 14): Вставить после всех столбцов, содержащих нулевой элемент, первый столбец
     */
    class Task2 : public Exercise
    {
    public:
        /**
         * @brief Конструктор Task2
         * @param rows Количество строк
         * @param cols Количество столбцов
         * @param generator Генератор значений
         */
        Task2(const std::size_t rows, const std::size_t cols, Generator &generator);

        /**
         * @brief Выполнить вставку первого столбца после каждого столбца, содержащего 0
         */
        void solve() override;
    };
}
