//
// Created by Kenyo Faria on 25/09/25.
//

#include <stdio.h>
#include <stdlib.h>

#include "product.h"

Product* stocks;
int count = 0;

void init_stocks() {
    if (stocks == NULL)
        stocks = malloc(sizeof(Product)*255);
}

void add_product(int code, char* name, int stock) {
    init_stocks();
    Product* product = create_product(code, name, stock);
    stocks[count] = *product;
    count++;
    free(product);
}

Product* find_product(int code) {
    init_stocks();
    for (int i = 0; i < count; i++) {
        if (code == stocks[i].code) {
            return stocks+i;
        }
    }
}

void update_stock(int code, int stock) {
    init_stocks();
    Product* product = find_product(code);
    product->stock = stock;
}

void list_products() {
    init_stocks();
    for (int i = 0; i < count; i++) {
        printf("\nProduct code: %s\n", to_string(stocks+i));
    }
}
