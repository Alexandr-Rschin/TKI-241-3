#pragma once
#include <string>

/**
 * @brief Базовый класс Товар овощного магазина
 */
class Product
{
protected:
    /**
     * @brief Статический счетчик для генерации уникальных ID
     */
    static int nextId;

    /**
     * @brief Уникальный идентификатор товара
     */
    int id;

    /**
     * @brief Название товара
     */
    std::string name;

    /**
     * @brief Закупочная цена со склада за единицу
     */
    int purchasePrice;

    /**
     * @brief Розничная цена продажи за единицу
     */
    int sellPrice;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Product();

    /**
     * @brief Конструктор с параметрами
     * @param name Название товара
     * @param purchasePrice Закупочная цена
     * @param sellPrice Цена продажи
     * @param id Идентификатор (0 для автогенерации)
     */
    Product(const std::string &name, const int purchasePrice, const int sellPrice, const int id = 0);

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Product() = default;

    /**
     * @brief Получить идентификатор товара
     * @return Уникальный ID
     */
    int getId() const noexcept;

    /**
     * @brief Получить название товара
     * @return Константная ссылка на название
     */
    const std::string &getName() const noexcept;

    /**
     * @brief Получить закупочную цену
     * @return Закупочная цена
     */
    int getPurchasePrice() const noexcept;

    /**
     * @brief Получить цену продажи
     * @return Розничная цена
     */
    int getSellPrice() const noexcept;

    /**
     * @brief Рассчитать прибыль с одной проданной единицы
     * @return Прибыль за единицу товара
     */
    virtual int getUnitProfit() const noexcept;

    /**
     * @brief Получить тип фасовки товара
     * @return Строка с типом товара
     */
    virtual std::string getCategory() const;

    /**
     * @brief Получить подробную информацию о товаре
     * @return Строка с информацией
     */
    virtual std::string getInfo() const;
};
