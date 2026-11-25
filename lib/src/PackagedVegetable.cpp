#include "PackagedVegetable.h"

PackagedVegetable::PackagedVegetable() : Product(), packageWeightGrams(0), packagingCost(0) {}

PackagedVegetable::PackagedVegetable(const std::string &name, const int purchasePrice, const int sellPrice,
                                     const int packageWeightGrams, const int packagingCost, const int id)
    : Product(name, purchasePrice, sellPrice, id),
      packageWeightGrams(packageWeightGrams),
      packagingCost(packagingCost) {}

int PackagedVegetable::getPackageWeightGrams() const noexcept
{
    return packageWeightGrams;
}

int PackagedVegetable::getPackagingCost() const noexcept
{
    return packagingCost;
}

int PackagedVegetable::getUnitProfit() const noexcept
{
    return sellPrice - purchasePrice - packagingCost;
}

std::string PackagedVegetable::getCategory() const
{
    return "Фасованный";
}

std::string PackagedVegetable::getInfo() const
{
    return Product::getInfo() +
           " | Фасовка: " + std::to_string(packageWeightGrams) + " г" +
           " | Упаковка: " + std::to_string(packagingCost) + " руб.";
}
