#include "Product.h"

int Product::nextId = 1;

Product::Product() : id(nextId++), name(""), purchasePrice(0), sellPrice(0) {}

Product::Product(const std::string &name, const int purchasePrice, const int sellPrice, const int id)
    : id(id > 0 ? id : nextId++), name(name), purchasePrice(purchasePrice), sellPrice(sellPrice)
{
    if (this->id >= nextId)
    {
        nextId = this->id + 1;
    }
}

int Product::getId() const noexcept
{
    return id;
}

const std::string &Product::getName() const noexcept
{
    return name;
}

int Product::getPurchasePrice() const noexcept
{
    return purchasePrice;
}

int Product::getSellPrice() const noexcept
{
    return sellPrice;
}

int Product::getUnitProfit() const noexcept
{
    return sellPrice - purchasePrice;
}

std::string Product::getCategory() const
{
    return "Овощ";
}

std::string Product::getInfo() const
{
    return "ID: " + std::to_string(id) +
           " | Товар: " + name +
           " | Тип: " + getCategory() +
           " | Закупка: " + std::to_string(purchasePrice) + " руб." +
           " | Продажа: " + std::to_string(sellPrice) + " руб.";
}
