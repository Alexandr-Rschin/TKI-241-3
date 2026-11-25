#include "VegetableShop.h"
#include <algorithm>
#include <stdexcept>

const Product *VegetableShop::findProductById(const int productId) const
{
    for (const PackagedVegetable &p : packagedProducts)
    {
        if (p.getId() == productId)
        {
            return &p;
        }
    }
    for (const BulkVegetable &p : bulkProducts)
    {
        if (p.getId() == productId)
        {
            return &p;
        }
    }
    return nullptr;
}

void VegetableShop::addPackagedProduct(const PackagedVegetable &product)
{
    if (findProductById(product.getId()) == nullptr)
    {
        packagedProducts.push_back(product);
    }
}

void VegetableShop::addBulkProduct(const BulkVegetable &product)
{
    if (findProductById(product.getId()) == nullptr)
    {
        bulkProducts.push_back(product);
    }
}

void VegetableShop::addSupply(const SupplyRecord &record)
{
    if (findProductById(record.getProductId()) == nullptr)
    {
        throw std::invalid_argument("Товар с указанным ID не найден в каталоге!");
    }
    supplies.push_back(record);
}

void VegetableShop::addSale(const SaleRecord &record)
{
    if (findProductById(record.getProductId()) == nullptr)
    {
        throw std::invalid_argument("Товар с указанным ID не найден в каталоге!");
    }
    sales.push_back(record);
}

std::vector<std::string> VegetableShop::getAssortmentByDate(const std::string &date) const
{
    std::vector<std::string> result;

    auto checkAndAdd = [&](const Product &product)
    {
        int available = 0;
        for (const SupplyRecord &sup : supplies)
        {
            if (sup.getProductId() == product.getId() && sup.getDate() <= date)
            {
                available += sup.getGoodQuantity();
            }
        }
        for (const SaleRecord &sale : sales)
        {
            if (sale.getProductId() == product.getId() && sale.getDate() <= date)
            {
                available -= sale.getQuantity();
            }
        }
        if (available > 0)
        {
            result.push_back(product.getInfo() + " | В наличии на " + date + ": " + std::to_string(available) + " ед.");
        }
    };

    for (const PackagedVegetable &p : packagedProducts)
    {
        checkAndAdd(p);
    }
    for (const BulkVegetable &p : bulkProducts)
    {
        checkAndAdd(p);
    }

    return result;
}

std::string VegetableShop::getIncomeExpenseReport(const int productId) const
{
    const Product *product = findProductById(productId);
    if (product == nullptr)
    {
        return "Товар не найден";
    }

    int totalIncome = 0;
    int totalGoodIncome = 0;
    int totalSpoiled = 0;
    for (const SupplyRecord &sup : supplies)
    {
        if (sup.getProductId() == productId)
        {
            totalIncome += sup.getTotalQuantity();
            totalGoodIncome += sup.getGoodQuantity();
            totalSpoiled += sup.getSpoiledQuantity();
        }
    }

    int totalExpense = 0;
    for (const SaleRecord &sale : sales)
    {
        if (sale.getProductId() == productId)
        {
            totalExpense += sale.getQuantity();
        }
    }

    int remainder = totalGoodIncome - totalExpense;
    return "Товар: " + product->getName() +
           "\n   Приход всего: " + std::to_string(totalIncome) +
           " (годных: " + std::to_string(totalGoodIncome) +
           ", испорчено: " + std::to_string(totalSpoiled) + ")" +
           "\n   Расход (продано): " + std::to_string(totalExpense) +
           "\n   Остаток: " + std::to_string(remainder);
}

int VegetableShop::getProfitByProduct(const int productId, const std::string &startDate, const std::string &endDate) const
{
    const Product *product = findProductById(productId);
    if (product == nullptr)
    {
        throw std::invalid_argument("Товар с указанным ID не найден!");
    }

    int soldQty = getSoldQuantity(productId, startDate, endDate);
    return soldQty * product->getUnitProfit();
}

std::pair<double, double> VegetableShop::getQualityPercentRatio(const int productId) const
{
    int total = 0;
    int good = 0;
    int spoiled = 0;

    for (const SupplyRecord &sup : supplies)
    {
        if (sup.getProductId() == productId)
        {
            total += sup.getTotalQuantity();
            good += sup.getGoodQuantity();
            spoiled += sup.getSpoiledQuantity();
        }
    }

    if (total == 0)
    {
        return {0.0, 0.0};
    }

    double goodPercent = (static_cast<double>(good) / total) * 100.0;
    double spoiledPercent = (static_cast<double>(spoiled) / total) * 100.0;
    return {goodPercent, spoiledPercent};
}

int VegetableShop::getSoldQuantity(const int productId, const std::string &startDate, const std::string &endDate) const
{
    int sold = 0;
    for (const SaleRecord &sale : sales)
    {
        if (sale.getProductId() == productId && sale.getDate() >= startDate && sale.getDate() <= endDate)
        {
            sold += sale.getQuantity();
        }
    }
    return sold;
}
