#include "Task2.h"
#include <vector>

miit::algebra::Task2::Task2(const std::size_t rows, const std::size_t cols, Generator &generator)
    : Exercise(rows, cols, generator)
{
}

void miit::algebra::Task2::solve()
{
    const std::size_t rows = this->matrix.getRows();
    if (rows == 0 || this->matrix.getCols() == 0)
    {
        return;
    }

    std::vector<int> firstColumn(rows);
    for (std::size_t i = 0; i < rows; ++i)
    {
        firstColumn[i] = this->matrix[i][0];
    }

    for (std::size_t j = 0; j < this->matrix.getCols(); ++j)
    {
        bool hasZero = false;
        for (std::size_t i = 0; i < rows; ++i)
        {
            if (this->matrix[i][j] == 0)
            {
                hasZero = true;
                break;
            }
        }

        if (hasZero)
        {
            this->matrix.insertColumn(j + 1, firstColumn);
            ++j;
        }
    }
}
