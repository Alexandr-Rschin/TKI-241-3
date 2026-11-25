#pragma once
#include "PackagedVegetable.h"
#include "BulkVegetable.h"
#include "SupplyRecord.h"
#include "SaleRecord.h"
#include <vector>
#include <string>
#include <utility>

/**
 * @brief Класс Овощной магазин
 */
class VegetableShop
{
private:
    /**
     * @brief Список фасованных овощей
     */
    std::vector<PackagedVegetable> packagedProducts;

    /**
     * @brief Список весовых овощей
     */
    std::vector<BulkVegetable> bulkProducts;

    /**
     * @brief Журнал прихода товара со склада
     */
    std::vector<SupplyRecord> supplies;

    /**
     * @brief Журнал продаж (расхода) товара
     */
    std::vector<SaleRecord> sales;

    /**
     * @brief Поиск товара по ID (возвращает указатель на базовый класс или nullptr)
     * @param productId Идентификатор товара
     * @return Указатель на константный объект Product
     */
    const Product *findProductById(const int productId) const;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    VegetableShop() = default;

    /**
     * @brief Деструктор
     */
    ~VegetableShop() = default;

    /**
     * @brief Добавить фасованный товар в каталог
     * @param product Объект фасованного овоща
     */
    void addPackagedProduct(const PackagedVegetable &product);

    /**
     * @brief Добавить весовой товар в каталог
     * @param product Объект весового овоща
     */
    void addBulkProduct(const BulkVegetable &product);

    /**
     * @brief Зарегистрировать приход товара со склада
     * @param record Запись прихода
     */
    void addSupply(const SupplyRecord &record);

    /**
     * @brief Зарегистрировать продажу товара
     * @param record Запись продажи
     */
    void addSale(const SaleRecord &record);

    /**
     * @brief Получить ассортимент товара в наличии на выбранный день
     * @param date Выбранная дата (YYYY-MM-DD)
     * @return Вектор строк с описанием доступных товаров и их остатком
     */
    std::vector<std::string> getAssortmentByDate(const std::string &date) const;

    /**
     * @brief Получить отчет приход-расход по выбранному товару
     * @param productId Идентификатор товара
     * @return Строка с историей прихода, расхода и текущим остатком
     */
    std::string getIncomeExpenseReport(const int productId) const;

    /**
     * @brief Рассчитать прибыль магазина по товару за отчетный период (без учета налогов)
     * @param productId Идентификатор товара
     * @param startDate Начальная дата периода (YYYY-MM-DD)
     * @param endDate Конечная дата периода (YYYY-MM-DD)
     * @return Прибыль в рублях
     */
    int getProfitByProduct(const int productId, const std::string &startDate, const std::string &endDate) const;

    /**
     * @brief Получить процентное соотношение хорошего и испорченного товара
     * @param productId Идентификатор товара
     * @return Пара чисел: {процент хорошего, процент испорченного}
     */
    std::pair<double, double> getQualityPercentRatio(const int productId) const;

    /**
     * @brief Получить количество проданного товара за отчетный период
     * @param productId Идентификатор товара
     * @param startDate Начальная дата периода (YYYY-MM-DD)
     * @param endDate Конечная дата периода (YYYY-MM-DD)
     * @return Количество проданных единиц
     */
    int getSoldQuantity(const int productId, const std::string &startDate, const std::string &endDate) const;
};
