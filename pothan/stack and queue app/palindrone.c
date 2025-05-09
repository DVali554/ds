#include <stdio.h>
#include <string.h>

int isPalindrome(char* str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

int main() {
    char str[] = "madam";

    if (isPalindrome(str))
        printf("%s is a Palindrome\n", str);
    else
        printf("%s is NOT a Palindrome\n", str);

    return 0;
}
