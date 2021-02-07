#ifndef sdds_ShoppingRec_H // replace with relevant names
#define sdds_ShoppingRec_H

const int MAX_TITLE_LENGTH = 50;
const int MAX_QUANTITY_VALUE = 50;

struct ShoppingRec {
   char m_title[MAX_TITLE_LENGTH + 1];
   int m_quantity;
   bool m_bought;
};

namespace sdds{
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}

#endif