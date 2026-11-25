#include "Task1.h"

miit::algebra::Task1::Task1(const std::size_t rows, const std::size_t cols, Generator &generator)
    : Exercise(rows, cols, generator)
{
}

void miit::algebra::Task1::solve()
{
    for (std::size_t i = 0; i < this->matrix.getRows(); ++i)
    {
        for (std::size_t j = 0; j < this->matrix.getCols(); ++j)
        {
            if (this->matrix[i][j] % 2 != 0)
            {
                this->matrix[i][j] = 0;
            }
        }
    }
}
