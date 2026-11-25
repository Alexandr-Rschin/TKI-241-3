#include "SupplyRecord.h"
#include <stdexcept>

SupplyRecord::SupplyRecord(const int productId, const std::string &date, const int totalQuantity, const int spoiledQuantity)
    : productId(productId), date(date), totalQuantity(totalQuantity), spoiledQuantity(spoiledQuantity)
{
    if (totalQuantity < 0 || spoiledQuantity < 0 || spoiledQuantity > totalQuantity)
    {
        throw std::invalid_argument("Некорректное количество товара в партии!");
    }
}

int SupplyRecord::getProductId() const noexcept
{
    return productId;
}

const std::string &SupplyRecord::getDate() const noexcept
{
    return date;
}

int SupplyRecord::getTotalQuantity() const noexcept
{
    return totalQuantity;
}

int SupplyRecord::getSpoiledQuantity() const noexcept
{
    return spoiledQuantity;
}

int SupplyRecord::getGoodQuantity() const noexcept
{
    return totalQuantity - spoiledQuantity;
}
