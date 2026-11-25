#pragma once
#include "Generator.h"
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <ostream>
#include <istream>

namespace miit::algebra
{
    /**
     * @brief Шаблонный класс двумерного массива (матрицы)
     * @tparam T Тип элементов матрицы
     */
    template <typename T>
    class Matrix
    {
    private:
        std::size_t rows;
        std::size_t cols;
        std::vector<std::vector<T>> data;

    public:
        /**
         * @brief Конструктор по умолчанию
         */
        Matrix() : rows(0), cols(0), data() {}

        /**
         * @brief Конструктор с заданием размеров
         * @param rows Количество строк
         * @param cols Количество столбцов
         */
        Matrix(const std::size_t rows, const std::size_t cols)
            : rows(rows), cols(cols), data(rows, std::vector<T>(cols, T{})) {}

        /**
         * @brief Конструктор с заполнением через генератор
         * @param rows Количество строк
         * @param cols Количество столбцов
         * @param generator Генератор значений
         */
        Matrix(const std::size_t rows, const std::size_t cols, Generator &generator)
            : rows(rows), cols(cols), data(rows, std::vector<T>(cols))
        {
            fill(generator);
        }

        /**
         * @brief Конструктор копирования
         */
        Matrix(const Matrix &other) = default;

        /**
         * @brief Конструктор перемещения
         */
        Matrix(Matrix &&other) noexcept = default;

        /**
         * @brief Деструктор
         */
        ~Matrix() = default;

        /**
         * @brief Оператор присваивания копированием
         */
        Matrix &operator=(const Matrix &other) = default;

        /**
         * @brief Оператор присваивания перемещением
         */
        Matrix &operator=(Matrix &&other) noexcept = default;

        /**
         * @brief Заполнить матрицу с помощью генератора
         * @param generator Генератор значений
         */
        void fill(Generator &generator)
        {
            for (std::size_t i = 0; i < rows; ++i)
            {
                for (std::size_t j = 0; j < cols; ++j)
                {
                    data[i][j] = static_cast<T>(generator.generate());
                }
            }
        }

        /**
         * @brief Получить количество строк
         * @return Количество строк
         */
        std::size_t getRows() const noexcept { return rows; }

        /**
         * @brief Получить количество столбцов
         * @return Количество столбцов
         */
        std::size_t getCols() const noexcept { return cols; }

        /**
         * @brief Оператор индексации (доступ к строке)
         * @param index Индекс строки
         * @return Ссылка на вектор строки
         */
        std::vector<T> &operator[](const std::size_t index)
        {
            if (index >= rows)
            {
                throw std::out_of_range("Индекс строки выходит за границы матрицы");
            }
            return data[index];
        }

        /**
         * @brief Константный оператор индексации
         * @param index Индекс строки
         * @return Константная ссылка на вектор строки
         */
        const std::vector<T> &operator[](const std::size_t index) const
        {
            if (index >= rows)
            {
                throw std::out_of_range("Индекс строки выходит за границы матрицы");
            }
            return data[index];
        }

        /**
         * @brief Вставить столбец в указанную позицию
         * @param colIndex Индекс вставки (от 0 до cols включительно)
         * @param column Вектор элементов столбца (размер должен совпадать с rows)
         */
        void insertColumn(const std::size_t colIndex, const std::vector<T> &column)
        {
            if (colIndex > cols)
            {
                throw std::out_of_range("Индекс столбца выходит за границы матрицы");
            }
            if (column.size() != rows)
            {
                throw std::invalid_argument("Размер вставляемого столбца не совпадает с числом строк");
            }
            for (std::size_t i = 0; i < rows; ++i)
            {
                data[i].insert(data[i].begin() + static_cast<std::ptrdiff_t>(colIndex), column[i]);
            }
            ++cols;
        }

        /**
         * @brief Преобразовать содержимое матрицы в строку
         * @return Строковое представление матрицы
         */
        std::string toString() const
        {
            std::ostringstream oss;
            for (std::size_t i = 0; i < rows; ++i)
            {
                for (std::size_t j = 0; j < cols; ++j)
                {
                    oss << data[i][j];
                    if (j + 1 < cols)
                    {
                        oss << "\t";
                    }
                }
                if (i + 1 < rows)
                {
                    oss << "\n";
                }
            }
            return oss.str();
        }

        /**
         * @brief Оператор сравнения матриц
         */
        bool operator==(const Matrix &other) const
        {
            return rows == other.rows && cols == other.cols && data == other.data;
        }

        /**
         * @brief Оператор вывода матрицы в поток (сдвиг влево)
         */
        friend std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix)
        {
            os << matrix.toString();
            return os;
        }

        /**
         * @brief Оператор ввода матрицы из потока (сдвиг вправо)
         */
        friend std::istream &operator>>(std::istream &is, Matrix<T> &matrix)
        {
            for (std::size_t i = 0; i < matrix.rows; ++i)
            {
                for (std::size_t j = 0; j < matrix.cols; ++j)
                {
                    is >> matrix.data[i][j];
                }
            }
            return is;
        }
    };
}
