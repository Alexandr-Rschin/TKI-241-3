#include <gtest/gtest.h>
#include "VegetableShop.h"
#include <typeinfo>

TEST(ProductTest, UnitProfitAndPolymorphism)
{
    PackagedVegetable pv("Томаты", 100, 200, 500, 20, 10);
    BulkVegetable bv("Картофель", 30, 70, "Тула", 11);

    const Product &p1 = pv;
    const Product &p2 = bv;

    EXPECT_EQ(p1.getUnitProfit(), 80);
    EXPECT_EQ(p2.getUnitProfit(), 40);
    EXPECT_EQ(p1.getCategory(), "Фасованный");
    EXPECT_EQ(p2.getCategory(), "Весовой");

    EXPECT_NO_THROW((void)dynamic_cast<const PackagedVegetable &>(p1));
    EXPECT_THROW((void)dynamic_cast<const PackagedVegetable &>(p2), std::bad_cast);
}

TEST(SupplyRecordTest, InvalidQuantitiesThrow)
{
    EXPECT_THROW(SupplyRecord(1, "2026-11-01", 10, 15), std::invalid_argument);
    EXPECT_THROW(SupplyRecord(1, "2026-11-01", -5, 0), std::invalid_argument);

    SupplyRecord sr(1, "2026-11-01", 100, 20);
    EXPECT_EQ(sr.getGoodQuantity(), 80);
}

TEST(VegetableShopTest, AllFiveAssignmentsWorkCorrectly)
{
    VegetableShop shop;
    PackagedVegetable pv("Огурцы", 80, 150, 500, 10, 100);
    shop.addPackagedProduct(pv);

    shop.addSupply(SupplyRecord(100, "2026-11-01", 100, 20));
    shop.addSale(SaleRecord(100, "2026-11-02", 30));
    shop.addSale(SaleRecord(100, "2026-11-10", 20));

    auto assortment = shop.getAssortmentByDate("2026-11-05");
    ASSERT_EQ(assortment.size(), 1u);
    EXPECT_NE(assortment[0].find("50 ед."), std::string::npos);

    std::string report = shop.getIncomeExpenseReport(100);
    EXPECT_NE(report.find("Приход всего: 100"), std::string::npos);
    EXPECT_NE(report.find("Расход (продано): 50"), std::string::npos);
    EXPECT_NE(report.find("Остаток: 30"), std::string::npos);

    EXPECT_EQ(shop.getProfitByProduct(100, "2026-11-01", "2026-11-05"), 1800);

    auto ratio = shop.getQualityPercentRatio(100);
    EXPECT_DOUBLE_EQ(ratio.first, 80.0);
    EXPECT_DOUBLE_EQ(ratio.second, 20.0);

    EXPECT_EQ(shop.getSoldQuantity(100, "2026-11-01", "2026-11-05"), 30);
    EXPECT_EQ(shop.getSoldQuantity(100, "2026-11-01", "2026-11-15"), 50);
}
