#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include "VegetableShop.h"

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    VegetableShop shop;

    PackagedVegetable tomatoes("Томаты Черри", 120, 210, 500, 15);
    PackagedVegetable carrots("Морковь мытая", 40, 85, 1000, 10);
    BulkVegetable potatoes("Картофель", 30, 65, "Краснодарский край");

    shop.addPackagedProduct(tomatoes);
    shop.addPackagedProduct(carrots);
    shop.addBulkProduct(potatoes);

    shop.addSupply(SupplyRecord(tomatoes.getId(), "2026-11-01", 100, 10));
    shop.addSupply(SupplyRecord(tomatoes.getId(), "2026-11-05", 50, 5));
    shop.addSupply(SupplyRecord(carrots.getId(), "2026-11-02", 80, 4));
    shop.addSupply(SupplyRecord(potatoes.getId(), "2026-11-01", 200, 20));

    shop.addSale(SaleRecord(tomatoes.getId(), "2026-11-02", 40));
    shop.addSale(SaleRecord(tomatoes.getId(), "2026-11-06", 35));
    shop.addSale(SaleRecord(carrots.getId(), "2026-11-03", 30));
    shop.addSale(SaleRecord(potatoes.getId(), "2026-11-04", 90));

    std::cout << "=== 1. АССОРТИМЕНТ НА 2026-11-03 ===" << std::endl;
    for (const std::string &item : shop.getAssortmentByDate("2026-11-03"))
    {
        std::cout << item << std::endl;
    }

    std::cout << "\n=== 2. ПРИХОД-РАСХОД (Томаты Черри) ===" << std::endl;
    std::cout << shop.getIncomeExpenseReport(tomatoes.getId()) << std::endl;

    std::cout << "\n=== 3. ПРИБЫЛЬ ЗА ПЕРИОД 2026-11-01 .. 2026-11-10 ===" << std::endl;
    std::cout << "Томаты Черри: " << shop.getProfitByProduct(tomatoes.getId(), "2026-11-01", "2026-11-10") << " руб." << std::endl;
    std::cout << "Картофель:    " << shop.getProfitByProduct(potatoes.getId(), "2026-11-01", "2026-11-10") << " руб." << std::endl;

    std::cout << "\n=== 4. % ХОРОШЕГО И ИСПОРЧЕННОГО ТОВАРА (Томаты Черри) ===" << std::endl;
    auto ratio = shop.getQualityPercentRatio(tomatoes.getId());
    std::cout << std::fixed << std::setprecision(1)
              << "Хорошего: " << ratio.first << "% | Испорченного: " << ratio.second << "%" << std::endl;

    std::cout << "\n=== 5. КОЛИЧЕСТВО ПРОДАННОГО ЗА ПЕРИОД 2026-11-01 .. 2026-11-05 ===" << std::endl;
    std::cout << "Томаты Черри продано: "
              << shop.getSoldQuantity(tomatoes.getId(), "2026-11-01", "2026-11-05") << " ед." << std::endl;

    std::cout << "\n=== ПОЛИМОРФНЫЙ ОБХОД КОЛЛЕКЦИИ БАЗОВОГО КЛАССА Product ===" << std::endl;
    std::vector<std::reference_wrapper<const Product>> catalog;
    catalog.push_back(std::cref(tomatoes));
    catalog.push_back(std::cref(carrots));
    catalog.push_back(std::cref(potatoes));

    for (const Product &prod : catalog)
    {
        std::cout << prod.getInfo() << " | Прибыль/ед.: " << prod.getUnitProfit() << " руб." << std::endl;
    }

    return 0;
}
