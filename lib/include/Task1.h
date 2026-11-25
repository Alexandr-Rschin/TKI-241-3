#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Задача 1 (Вариант 14): Заменить нечетный элемент каждой строки нулем
     */
    class Task1 : public Exercise
    {
    public:
        /**
         * @brief Конструктор Task1
         * @param rows Количество строк
         * @param cols Количество столбцов
         * @param generator Генератор значений
         */
        Task1(const std::size_t rows, const std::size_t cols, Generator &generator);

        /**
         * @brief Выполнить замену всех нечетных элементов каждой строки на 0
         */
        void solve() override;
    };
}
