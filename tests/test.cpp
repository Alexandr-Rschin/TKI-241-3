#include <gtest/gtest.h>
#include "Matrix.h"
#include "ZeroGenerator.h"
#include "ConstGenerator.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "Task1.h"
#include "Task2.h"
#include <sstream>

using namespace miit::algebra;

TEST(GeneratorTest, ZeroAndConstGenerators)
{
    ZeroGenerator zg;
    EXPECT_EQ(zg.generate(), 0);

    ConstGenerator cg(7);
    EXPECT_EQ(cg.generate(), 7);
}

TEST(GeneratorTest, IStreamGeneratorReadsValues)
{
    std::istringstream iss("10 -5 42");
    IStreamGenerator gen(iss);

    EXPECT_EQ(gen.generate(), 10);
    EXPECT_EQ(gen.generate(), -5);
    EXPECT_EQ(gen.generate(), 42);
}

TEST(MatrixTest, IndexingAndToString)
{
    ConstGenerator cg(3);
    Matrix<int> m(2, 2, cg);

    EXPECT_EQ(m.getRows(), 2u);
    EXPECT_EQ(m.getCols(), 2u);
    EXPECT_EQ(m[0][0], 3);
    EXPECT_EQ(m.toString(), "3\t3\n3\t3");
    EXPECT_THROW(m[5][0], std::out_of_range);
}

TEST(Task1Test, ReplacesOddElementsWithZero)
{
    std::istringstream iss("1 2 -3\n4 5 0");
    IStreamGenerator gen(iss);
    Task1 task1(2, 3, gen);

    task1.solve();

    const Matrix<int> &res = task1.getMatrix();
    EXPECT_EQ(res[0][0], 0);
    EXPECT_EQ(res[0][1], 2);
    EXPECT_EQ(res[0][2], 0);
    EXPECT_EQ(res[1][0], 4);
    EXPECT_EQ(res[1][1], 0);
    EXPECT_EQ(res[1][2], 0);
}

TEST(Task2Test, InsertsFirstColumnAfterColumnsContainingZero)
{
    std::istringstream iss("1 0 3\n2 4 0");
    IStreamGenerator gen(iss);
    Task2 task2(2, 3, gen);

    task2.solve();

    const Matrix<int> &res = task2.getMatrix();
    ASSERT_EQ(res.getRows(), 2u);
    ASSERT_EQ(res.getCols(), 5u);

    // Ожидаемая матрица:
    // 1  0  1  3  1
    // 2  4  2  0  2
    EXPECT_EQ(res[0][0], 1);
    EXPECT_EQ(res[0][1], 0);
    EXPECT_EQ(res[0][2], 1);
    EXPECT_EQ(res[0][3], 3);
    EXPECT_EQ(res[0][4], 1);

    EXPECT_EQ(res[1][0], 2);
    EXPECT_EQ(res[1][1], 4);
    EXPECT_EQ(res[1][2], 2);
    EXPECT_EQ(res[1][3], 0);
    EXPECT_EQ(res[1][4], 2);
}

TEST(Task2Test, HandlesZeroInFirstColumnWithoutInfiniteLoop)
{
    std::istringstream iss("0 5\n1 6");
    IStreamGenerator gen(iss);
    Task2 task2(2, 2, gen);

    task2.solve();

    const Matrix<int> &res = task2.getMatrix();
    ASSERT_EQ(res.getCols(), 3u);
    // Ожидаемая матрица:
    // 0  0  5
    // 1  1  6
    EXPECT_EQ(res[0][0], 0);
    EXPECT_EQ(res[0][1], 0);
    EXPECT_EQ(res[0][2], 5);
    EXPECT_EQ(res[1][0], 1);
    EXPECT_EQ(res[1][1], 1);
    EXPECT_EQ(res[1][2], 6);
}
