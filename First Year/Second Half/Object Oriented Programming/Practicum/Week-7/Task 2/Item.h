#ifndef ITEM_H

#define ITEM_H

#include <string>

class Item
{
private:
    std::string name;
    double price;
public:
    Item();
    Item(const std::string&,const double&);
    Item(const Item&);
    ~Item();


    void set_name(const std::string&);
    void set_price(const double&);

    bool operator==(const Item&) const;
    friend std::ostream& operator<<(std::ostream&, const Item&);
};



#endif //!ITEM_H