//
// Created by Kenyo Faria on 25/09/25.
//

#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct {
    int code;
    char* name;
    int stock;
} Product;

Product * create_product(int code, char* name, int stock);
char* to_string(Product * product);

#endif //PRODUCT_H
