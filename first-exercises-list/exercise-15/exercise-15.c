//
// Created by Kenyo Faria on 25/09/25.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/inputReader.h"
#include "product_stock.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void add_prompt() {
    clear_input_buffer();
    int product_code = input_int_reader("product code: ");
    clear_input_buffer();
    char *name = input_string_reader("product name: ");
    clear_input_buffer();
    int stock = input_int_reader("product stock: ");
    add_product(product_code, name, stock);
    printf("\nProduct added!");
    free(name);
}


void print_options(void) {
    printf("1 - to add a product\n");
    printf("2 - to list products\n");
    printf("3 - to find a product\n");
}

void start_prompt() {
    print_options();

    int option = input_int_reader("\nChoose an option:");
    while (true) {
        switch (option) {
            case 1:
                add_prompt();
                break;
            case 2:
                list_products();
                break;
            case 3:
                break;
            case 0:
                return;
            default:
                printf("\nInvalid option\n");
                break;
        }
        print_options();
        option = input_int_reader("\nChoose an option:");
    }

}
