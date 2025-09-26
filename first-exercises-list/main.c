#include <stdio.h>
#include <stdlib.h>
#include "utils/inputReader.h"
#include "exercise-1/exercise-1.h"
#include "exercise-2/exercise-2.h"
#include "exercise-3/exercise-3.h"
#include "exercise-4/exercise-4.h"
#include "exercise-5/exercise-5.h"
#include "exercise-6/exercise-6.h"
#include "exercise-7/exercise-7.h"
#include "exercise-7/student.h"
#include "exercise-8/exercise-8.h"
#include "exercise-9/exercise-9.h"
#include "exercise-10/exercise-10.h"
#include "exercise-11/exercise-11.h"
#include "exercise-12/exercise-12.h"
#include "exercise-13/exercise-13.h"
#include "exercise-14/exercise-14.h"
#include "exercise-15/exercise-15.h"


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Wrong number of arguments\n");
        printf("Please choose between 1 and 14\n");
        return 1;
    }
    int choice = atoi(argv[1]);

    switch (choice) {
        case 1:
            printf("\nExercise 1!\n");
            const int time = input_int_reader("Enter with time in seconds: ");
            const int hours = seconds_to_hour(time);
            const int minutes = seconds_to_minute(time);
            printf("\n seconds: %d", time);
            printf("\n minutes: %d", minutes);
            printf("\n hours: %d", hours);
            break;
        case 2:
            printf("Exercise 2!\n");
            int numbers[3];
            numbers[0] = input_int_reader("Enter with the first number: ");
            numbers[1] = input_int_reader("Enter with the second number: ");
            numbers[2] = input_int_reader("Enter with the third number: ");
            printf("\n The average is: %.2f", average(numbers, 3));
            break;
        case 3:
            printf("Exercise 3!\n");
            const int number = input_int_reader("Enter a integer: ");
            char* result = odd_even(number);
            printf("\n The number is: %s", result);
            break;
        case 4:
            printf("Exercise 4!\n");
            int a = input_int_reader("Enter with value a: ");
            int b = input_int_reader("Enter with value b: ");
            int c = input_int_reader("Enter with value c: ");
            printf("\n Does these values build a triangle: %d\n", is_triangle(a, b, c));
        case 5:
            printf("Exercise 5!\n");
            float values[3];
            values[0] = input_float_reader("Enter with the first number: ");
            values[1] = input_float_reader("Enter with the second number: ");
            values[2] = input_float_reader("Enter with the third number: ");
            printf("\n Min: %.2f", min(values, 3));
            printf("\n Mid: %.2f", mid(values, 3));
            printf("\n Max: %.2f", max(values, 3));
            break;
        case 6:
            printf("Exercise 6!\n");
            char operator = input_char_reader("Enter with the operator: ");
            printf("\n Result: %.2f", do_operation(operator));
            break;
        case 7:
            printf("Exercise 7!\n");
            Student* student = classifyStudent();
            printf("\n Name: %s", student->name);
            printf("\n Grade 1: %.2f", student->grade1);
            printf("\n Grade 2: %.2f", student->grade2);
            printf("\n Status: %s", student->status);
            free(student);
            break;
        case 8:
            printf("Exercise 8!\n");
            printf("\n Tax to pay: %.2f", calculate_tax());
            break;
        case 9:
            printf("Exercise 9!\n");
            printf("\n Number of days: %d", get_num_days());
            break;
        case 10:
            printf("Exercise 10!\n");
            print_values();
            break;
        case 11:
            printf("Exercise 11!\n");
            int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
            invert(array, 15);
            break;
        case 12:
            printf("Exercise 12!\n");
            int other_array[] = {1,2,3,3,4,2};
            remove_duplicates(other_array, 6);
            break;
        case 13:
            printf("Exercise 13!\n");
            printf("the result is: %d ", compare("henyo", "kenyo"));
            break;
        case 14:
            printf("Exercise 14!\n");
            printf("words: %d", count_words("kenyo   h     abadio    f     crosara faria"));
            break;
        case 15:
            printf("Exercise 15!\n");
            start_prompt();
            break;
        default:
            printf("Invalid number\n");
            return 1;
    }

    return 0;
}
