#pragma once

namespace miit::algebra
{
    /**
     * @brief Абстрактный базовый класс генератора значений
     */
    class Generator
    {
    public:
        /**
         * @brief Виртуальный деструктор
         */
        virtual ~Generator() = default;

        /**
         * @brief Сгенерировать очередное целое значение
         * @return Сгенерированное число
         */
        virtual int generate() = 0;
    };
}
