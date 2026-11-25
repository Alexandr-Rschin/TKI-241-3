#pragma once
#include <string>

/**
 * @brief Класс Расход (продажа) товара
 */
class SaleRecord
{
private:
    /**
     * @brief Идентификатор товара
     */
    int productId;

    /**
     * @brief Дата продажи (формат YYYY-MM-DD)
     */
    std::string date;

    /**
     * @brief Проданное количество
     */
    int quantity;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    SaleRecord() = default;

    /**
     * @brief Конструктор с параметрами
     * @param productId ID товара
     * @param date Дата продажи
     * @param quantity Проданное количество
     */
    SaleRecord(const int productId, const std::string &date, const int quantity);

    /**
     * @brief Получить ID товара
     * @return Идентификатор товара
     */
    int getProductId() const noexcept;

    /**
     * @brief Получить дату продажи
     * @return Константная ссылка на дату
     */
    const std::string &getDate() const noexcept;

    /**
     * @brief Получить проданное количество
     * @return Количество проданного товара
     */
    int getQuantity() const noexcept;
};
