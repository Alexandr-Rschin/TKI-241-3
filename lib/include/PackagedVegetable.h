#pragma once
#include "Product.h"

/**
 * @brief Класс Расфасованный овощ, наследуемый от Product
 */
class PackagedVegetable : public Product
{
private:
    /**
     * @brief Вес одной фасовки в граммах
     */
    int packageWeightGrams;

    /**
     * @brief Стоимость упаковки за одну единицу
     */
    int packagingCost;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    PackagedVegetable();

    /**
     * @brief Конструктор с параметрами
     * @param name Название овоща
     * @param purchasePrice Закупочная цена
     * @param sellPrice Цена продажи
     * @param packageWeightGrams Вес упаковки в граммах
     * @param packagingCost Затраты на упаковку
     * @param id Идентификатор
     */
    PackagedVegetable(const std::string &name, const int purchasePrice, const int sellPrice,
                      const int packageWeightGrams, const int packagingCost, const int id = 0);

    /**
     * @brief Получить вес фасовки
     * @return Вес в граммах
     */
    int getPackageWeightGrams() const noexcept;

    /**
     * @brief Получить стоимость упаковки
     * @return Стоимость упаковки
     */
    int getPackagingCost() const noexcept;

    /**
     * @brief Рассчитать прибыль с учетом затрат на фасовку
     * @return Прибыль за единицу товара
     */
    int getUnitProfit() const noexcept override;

    /**
     * @brief Получить тип фасовки
     * @return Строка "Фасованный"
     */
    std::string getCategory() const override;

    /**
     * @brief Получить подробную информацию о фасованном овоще
     * @return Строка с информацией
     */
    std::string getInfo() const override;
};
