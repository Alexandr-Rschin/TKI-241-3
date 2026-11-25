#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Абстрактный базовый класс задания, агрегирующий Matrix и Generator
     */
    class Exercise
    {
    protected:
        Matrix<int> matrix;
        Generator &generator;

    public:
        /**
         * @brief Конструктор задания
         * @param rows Количество строк матрицы
         * @param cols Количество столбцов матрицы
         * @param generator Ссылка на генератор заполнения
         */
        Exercise(const std::size_t rows, const std::size_t cols, Generator &generator);

        /**
         * @brief Виртуальный деструктор
         */
        virtual ~Exercise() = default;

        /**
         * @brief Чисто виртуальный метод решения задания
         */
        virtual void solve() = 0;

        /**
         * @brief Получить константную ссылку на матрицу
         * @return Матрица
         */
        const Matrix<int> &getMatrix() const noexcept;

        /**
         * @brief Установить матрицу вручную (удобно для модульных тестов)
         * @param newMatrix Новая матрица
         */
        void setMatrix(const Matrix<int> &newMatrix);
    };
}
