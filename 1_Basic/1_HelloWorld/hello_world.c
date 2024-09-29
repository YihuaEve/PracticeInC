/*
	gcc .\hello_world.c: 不指定 -o, 會產生 a.exe, 執行 a.exe 可看到輸出結果
	gcc -fexec-charset=utf-8  .\hello_world.c -o hello_utf8: -o 可以指定產生的exe檔檔名
	gcc -fexec-charset=BIG5  .\hello_world.c -o hello_big5
	因為輸出文字有中文, 會出現亂碼, 所以要指定執行時使用的編碼, 目前測試 指定BIG5 才能正常輸出繁體中文
*/

#include <stdio.h>

int main(void) {
    printf("Hello! World!\n");
    printf("哈囉! C語言!\n");

    return 0;
}