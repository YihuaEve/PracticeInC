#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char s1[] = "abcde";
    char *s2 = "abcde";
    char *s3; s3 = malloc(6); strcpy(s3, "abcde");
    char a[100]; strcpy(a, "123");

    s1 = a; // compile error
    s2 = a; // ok
    s3 = a; // ok but memory leak
    strcpy(s1,a); // ok
    strcpy(s2,a); // run time error
    strcpy(s3,a); // ok

	// To avoid buffer overflow, it's better to use strncpy than strcpy
	#define LEN	5
	char s1[LEN], s2[LEN];

	strncpy(s1, "abcdefgh", LEN-1); // s1: 'abcde' without end of \0. It will encounter error if print s1.
	s1[LEN - 1] = '\0'; // s1: 'abcd\0'

	strncpy(s2, "ab", LEN-1); // s2[0]=a, s2[1]=b, s2[2]='\0'
	s2[LEN - 1] = '\0'; // unnecessary but safer coding style

    return 0;
}