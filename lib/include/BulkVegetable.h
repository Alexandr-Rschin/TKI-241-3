#pragma once
#include "Product.h"

/**
 * @brief Класс Весовой (насыпной) овощ, наследуемый от Product
 */
class BulkVegetable : public Product
{
private:
    /**
     * @brief Страна или регион происхождения
     */
    std::string origin;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    BulkVegetable();

    /**
     * @brief Конструктор с параметрами
     * @param name Название овоща
     * @param purchasePrice Закупочная цена за кг
     * @param sellPrice Цена продажи за кг
     * @param origin Происхождение товара
     * @param id Идентификатор
     */
    BulkVegetable(const std::string &name, const int purchasePrice, const int sellPrice,
                  const std::string &origin, const int id = 0);

    /**
     * @brief Получить регион происхождения
     * @return Константная ссылка на строку происхождения
     */
    const std::string &getOrigin() const noexcept;

    /**
     * @brief Получить тип товара
     * @return Строка "Весовой"
     */
    std::string getCategory() const override;

    /**
     * @brief Получить подробную информацию о весовом овоще
     * @return Строка с информацией
     */
    std::string getInfo() const override;
};
