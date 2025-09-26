//
// Created by Kenyo Faria on 25/09/25.
//

#ifndef PRODUCT_STOCK_H
#define PRODUCT_STOCK_H
#include "product.h"

void add_product(int code, char* name, int stock);
Product* find_product(int code);
void update_stock(int code, int stock);
void list_products();

#endif //PRODUCT_STOCK_H
