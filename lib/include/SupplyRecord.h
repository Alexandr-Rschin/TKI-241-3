#pragma once
#include <string>

/**
 * @brief Класс Приход товара со склада
 */
class SupplyRecord
{
private:
    /**
     * @brief Идентификатор товара
     */
    int productId;

    /**
     * @brief Дата поступления (формат YYYY-MM-DD)
     */
    std::string date;

    /**
     * @brief Общее поступившее количество
     */
    int totalQuantity;

    /**
     * @brief Количество испорченного товара в партии
     */
    int spoiledQuantity;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    SupplyRecord() = default;

    /**
     * @brief Конструктор с параметрами
     * @param productId ID товара
     * @param date Дата поступления
     * @param totalQuantity Общее количество
     * @param spoiledQuantity Количество испорченного товара
     */
    SupplyRecord(const int productId, const std::string &date, const int totalQuantity, const int spoiledQuantity);

    /**
     * @brief Получить ID товара
     * @return Идентификатор товара
     */
    int getProductId() const noexcept;

    /**
     * @brief Получить дату поступления
     * @return Константная ссылка на дату
     */
    const std::string &getDate() const noexcept;

    /**
     * @brief Получить общее количество партии
     * @return Общее количество
     */
    int getTotalQuantity() const noexcept;

    /**
     * @brief Получить количество испорченного товара
     * @return Количество испорченного товара
     */
    int getSpoiledQuantity() const noexcept;

    /**
     * @brief Получить количество хорошего товара
     * @return Количество годного к продаже товара
     */
    int getGoodQuantity() const noexcept;
};
