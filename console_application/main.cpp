#include <iostream>
#include <memory>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ZeroGenerator.h"
#include "ConstGenerator.h"
#include "Task1.h"
#include "Task2.h"

using namespace miit::algebra;

/**
 * @brief Точка входа в демонстрационную программу (Вариант 14)
 * @return 0 при успешном завершении
 */
int main()
{
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    std::size_t rows = 0;
    std::size_t cols = 0;
    std::cout << "Введите количество строк и столбцов матрицы: ";
    std::cin >> rows >> cols;

    int choice = 0;
    std::cout << "Выберите способ заполнения:\n"
              << "1 - Случайные числа (-10..10)\n"
              << "2 - Ввод с клавиатуры\n"
              << "3 - Заполнение нулями\n"
              << "4 - Заполнение константой\n"
              << "Ваш выбор: ";
    std::cin >> choice;

    std::unique_ptr<Generator> generator;
    if (choice == 1)
    {
        generator = std::make_unique<RandomGenerator>(-10, 10);
    }
    else if (choice == 2)
    {
        std::cout << "Введите " << (rows * cols) << " целых чисел:\n";
        generator = std::make_unique<IStreamGenerator>(std::cin);
    }
    else if (choice == 3)
    {
        generator = std::make_unique<ZeroGenerator>();
    }
    else
    {
        int c = 0;
        std::cout << "Введите константное значение: ";
        std::cin >> c;
        generator = std::make_unique<ConstGenerator>(c);
    }

    Task1 task1(rows, cols, *generator);
    Matrix<int> initialMatrix = task1.getMatrix();

    std::cout << "\n=== Исходная матрица ===\n"
              << initialMatrix << "\n";

    task1.solve();
    std::cout << "\n=== Задача 1 (нечетные элементы заменены на 0) ===\n"
              << task1.getMatrix() << "\n";

    ZeroGenerator dummyGen;
    Task2 task2(rows, cols, dummyGen);
    task2.setMatrix(task1.getMatrix());
    task2.solve();
    std::cout << "\n=== Задача 2 (вставка первого столбца после столбцов с 0) ===\n"
              << task2.getMatrix() << "\n";

    return 0;
}
