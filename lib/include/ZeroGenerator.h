#pragma once
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Генератор нулевых значений
     */
    class ZeroGenerator : public Generator
    {
    public:
        /**
         * @brief Сгенерировать ноль
         * @return 0
         */
        int generate() override;
    };
}
