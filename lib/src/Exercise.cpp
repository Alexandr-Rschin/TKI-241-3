#include "Exercise.h"

miit::algebra::Exercise::Exercise(const std::size_t rows, const std::size_t cols, Generator &generator)
    : matrix(rows, cols, generator), generator(generator)
{
}

const miit::algebra::Matrix<int> &miit::algebra::Exercise::getMatrix() const noexcept
{
    return this->matrix;
}

void miit::algebra::Exercise::setMatrix(const Matrix<int> &newMatrix)
{
    this->matrix = newMatrix;
}
