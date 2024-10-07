/**
語法第一個作業：讓我輸入一個數字，輸出數字行數的菱形

input限制: odd number, [1,19]

input: 1, output: 
*

input: 3, output:
 *
***
 *
 
**/

#include <stdio.h>
#include <stdlib.h>

// function: print a line with white spaces and marks
int print_marked_line(int white_space_count, int mark_count){
    for (int i = 0; i < white_space_count; i++, printf(" "));
    for (int i = 0; i < mark_count; i++, printf("*"));
    printf("\n");
    return 0;
}

int main(void){
    int number;

    // 1. Wait for user input
    printf("Please enter a positive odd integer between 1 and 19: \n");
    scanf("%d", &number);
    printf("The entered number: %d. \n", number);

    // 2. Check: Invalid number
    if(number < 1 || number > 19 || !(number & 1)){
        printf("[ERROR] Illegal input: %d.\n", number);
        printf("Please enter a positive odd integer between 1 and 19. \n");
        return 0;
    }

    // 3. Print diamond pattern
    printf("Output: \n");
    for (int i = 0; i < number; i++){
        int white_space_count = abs((number / 2) - i);
        int mark_count = number - (2 * white_space_count);
        print_marked_line(white_space_count, mark_count);
    }

    return 0;
}