//
// Created by Kenyo Faria on 25/09/25.
//
#include "product.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Product* basic_creation(int code, char* name) {
    Product *product = malloc(sizeof(Product));
    product->code = code;
    product->name = malloc(strlen(name) + 1);
    strcpy(product->name, name);
    return product;
}


Product* create_product(int code, char* name, int stock) {
    Product *product = basic_creation(code, name);
    product->stock = stock;
    return product;
}

char* to_string(Product* product) {
    size_t name_len = (product->name != NULL) ? strlen(product->name) : 0;
    size_t buffer_size = 50 + name_len;
    char* buffer = (char*)malloc(buffer_size);
    if (buffer == NULL) {
        perror("Failed to allocate memory for string");
        return NULL;
    }
    snprintf(
        buffer,
        buffer_size,
        "{Code: %d, Name: \"%s\", Stock: %d}",
        product->code,
        (product->name != NULL ? product->name : "N/A"),
        product->stock
    );
    return buffer;
}