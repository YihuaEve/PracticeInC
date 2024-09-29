/**
語法第一個作業：讓我輸入一個數字，輸出數字行數的菱形

input: 0, output: 

input: 1, output: 
*

input: 2, output:
 *
***
 *
 
input: 3, output:
  *
 ***
*****
 ***
  *
 
**/

#include <stdio.h>

// function: print a line with white spaces and marks
int print_mark_line(int white_space_count, int mark_count){
    for (int i = 0; i < white_space_count; i++, printf(" "));
    for (int i = 0; i < mark_count; i++, printf("*"));
    printf("\n");
    return 0;
}

int main(void){
    int number;

	// wait for user input
    printf("Please enter a positive integer: \n");
    scanf("%d", &number);
    printf("The entered number: %d\n", number);
	
	// check: Invalid number
    if(number < 0){
        printf("Invalid number: %d, please enter positive integer: \n", number);
        return 0;
    }
	
    printf("Output Diamond: \n");	
	// print upper part of diamond
    for (int i = 0; i < number; i++){
        int white_space_count = number - i - 1;
        int mark_count = 2 * i + 1;
        print_mark_line(white_space_count, mark_count);
    }
	// print upper part of diamond
    for (int i = 0; i < (number - 1); i++){
        int white_space_count = i + 1;
        int mark_count = 2 * (number - 2 - i) + 1;
        print_mark_line(white_space_count, mark_count);
    }

    return 0;
}