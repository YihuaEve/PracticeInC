#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_A 4
#define LEN_S 10

int main(void){
    int a[LEN_A], *b, *c;
    char s[LEN_S];
    printf("LEN_A: '%d'\n", LEN_A);
    printf("LEN_S: '%d'\n", LEN_S);
    printf("==============\n");

    for (int i = 0; i < LEN_A; a[i] = i, i++);
    b = a;
    c = &a[2];
    strcpy(s, "123");

    printf("a: '%d'\n", a); // print start address of a array
    printf("a[0]: '%d'\n", a[0]); // print a[0] value
    printf("&a[0]: '%d'\n", &a[0]); // print address of a[0], same as a
    printf("==============\n");

    printf("a[LEN_A]: '%d' with LEN_A = %d\n", a[LEN_A], LEN_A); // a[LEN_A] = '\0', number: ?
    printf("a[LEN_A]: '%c' with LEN_A = %d\n", a[LEN_A], LEN_A); // a[LEN_A] = '\0', output:empty space
    printf("==============\n");

    printf("s: '%d'\n", s); // s: address of s[0]
    printf("s: '%s'\n", s); // %s only accept pointer s, print s string
    printf("&s[0]: '%s'\n", &s[0]); // s = &s[0], print s string until \0
    printf("s: '%c'\n", s); // ? , s address in char
    printf("==============\n");

    printf("s[0]: '%d'\n", s[0]); // 1
    printf("s[0]: '%c'\n", s[0]); // 1
    printf("s[0]: '%s'\n", s[0]); // %s only accept pointer, compile error
    printf("==============\n");

    return 0;
}