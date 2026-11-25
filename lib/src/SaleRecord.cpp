#include "SaleRecord.h"
#include <stdexcept>

SaleRecord::SaleRecord(const int productId, const std::string &date, const int quantity)
    : productId(productId), date(date), quantity(quantity)
{
    if (quantity <= 0)
    {
        throw std::invalid_argument("Количество проданного товара должно быть больше нуля!");
    }
}

int SaleRecord::getProductId() const noexcept
{
    return productId;
}

const std::string &SaleRecord::getDate() const noexcept
{
    return date;
}

int SaleRecord::getQuantity() const noexcept
{
    return quantity;
}
