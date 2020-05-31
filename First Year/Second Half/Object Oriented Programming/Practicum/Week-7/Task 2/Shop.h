#ifndef SHOP_H

#define SHOP_H

#include <vector>
#include <fstream>
#include "Item.cpp"

class Shop
{
protected:
    std::vector<Item> items;
    int max_items;

    void read_from_file(std::fstream&);
public:
    Shop();
    Shop(std::vector<Item>, const int&);
    Shop(std::fstream&, const int&);
    ~Shop();

    bool is_full() const;
    bool add_item(const Item&);
    bool add_item(const std::string&, const double&);
    bool find_item(const Item&) const;
    void save_to_file(const char*) const;
    void print() const;

};

#endif //!SHOP_H