#include <stdio.h>
#include <string.h>

#define SIZE 100

int isSymmetric(char* str) {
    int len = strlen(str);
    int mid = len / 2;
    int symmetric = 1;

    for (int i = 0; i < mid; i++) {
        if (str[i] != str[len - 1 - i]) {
            symmetric = 0;
            break;
        }
    }

    return symmetric;
}

int main() {
    char str[] = "abccba";

    if (isSymmetric(str))
        printf("%s is Symmetric\n", str);
    else
        printf("%s is NOT Symmetric\n", str);

    return 0;
}
