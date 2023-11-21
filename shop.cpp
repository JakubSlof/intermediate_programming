#include <cassert>
#include <vector>
#include<iostream>

enum ProductType
{
    ELECTRONICS,
    CLOTHING,
    FOOD,
    BOOKS,
    FURNITURE
};

struct InventoryItem
{
    int itemID;
    int quantity;
    int yearManufactured;
    int price;
    ProductType type;
};

struct Shop
{
    std::vector<InventoryItem> inventory;
};

std::vector<InventoryItem> getItemsByType(const Shop &shop, ProductType type){
    std::vector<InventoryItem> itemsToReturn;
    for (std::size_t i = 0; i < shop.inventory.size(); i++){
        if (type == shop.inventory[i].type){
            
            itemsToReturn.push_back(shop.inventory[i]);
            
    }
}
return itemsToReturn;
}
std::vector<InventoryItem> getItemsByYear(const Shop &shop, int year){
    std::vector<InventoryItem> itemsToReturn;
    for (std::size_t  i = 0; i < shop.inventory.size(); i++)
    {
        if (year == shop.inventory[i].yearManufactured)
        {
            itemsToReturn.push_back(shop.inventory[i]);
            }

    }
    return itemsToReturn;
}
std::vector<InventoryItem> getItemsByPrice(const Shop &shop, int price){
 std::vector<InventoryItem> itemsToReturn;
    for (std::size_t  i = 0; i < shop.inventory.size(); i++)
    {
        if (price == shop.inventory[i].price)
        {
            itemsToReturn.push_back(shop.inventory[i]);
            }

    }
    return itemsToReturn;

}

std::vector<InventoryItem> getItemsCheaperThan(Shop &shop, int price){
    std::vector<InventoryItem> itemsToReturn;
    for (std::size_t  i = 0; i < shop.inventory.size(); i++)
    {
        if (price > shop.inventory[i].price){
            itemsToReturn.push_back(shop.inventory[i]);
            }
            }
            return itemsToReturn;
}
std::vector<InventoryItem> getItemsMoreExpensiveThan(Shop &shop, int price){
    std::vector<InventoryItem> itemsToReturn;
    for (std::size_t  i = 0; i < shop.inventory.size(); i++)
    {
        if (price < shop.inventory[i].price){
            itemsToReturn.push_back(shop.inventory[i]);
            }
            }
            return itemsToReturn;
}

int main()
{
    InventoryItem meloun = {69, 4, 1896, 6000, FOOD};
    InventoryItem pizza = {72, 3, 2005, 1000, FOOD};
    InventoryItem shirt = {73, 25, 2015, 20, CLOTHING};
    InventoryItem jeans = {74, 25, 2015, 25, CLOTHING};
    InventoryItem laptop = {74, 10, 2016, 1500, ELECTRONICS};
    InventoryItem book = {75, 10, 2017, 100, BOOKS};
    InventoryItem phone = {76, 10, 2018, 500, ELECTRONICS};
    InventoryItem camera = {77, 10, 2019, 1000, ELECTRONICS};
    InventoryItem tablet = {78, 10, 2020, 1500, ELECTRONICS};


    Shop pekarna = {
        .inventory = {
            meloun,
            laptop,
            shirt,
            book
            }};
std::vector<InventoryItem> id = getItemsByType(pekarna,FOOD);
  for (std::size_t i = 0; i < getItemsByType(pekarna,FOOD).size(); i++) {
        std::cout << id[i].itemID<< std::endl;
        
}
}