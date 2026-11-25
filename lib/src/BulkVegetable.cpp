#include "BulkVegetable.h"

BulkVegetable::BulkVegetable() : Product(), origin("") {}

BulkVegetable::BulkVegetable(const std::string &name, const int purchasePrice, const int sellPrice,
                             const std::string &origin, const int id)
    : Product(name, purchasePrice, sellPrice, id), origin(origin) {}

const std::string &BulkVegetable::getOrigin() const noexcept
{
    return origin;
}

std::string BulkVegetable::getCategory() const
{
    return "Весовой";
}

std::string BulkVegetable::getInfo() const
{
    return Product::getInfo() + " | Происхождение: " + origin;
}
