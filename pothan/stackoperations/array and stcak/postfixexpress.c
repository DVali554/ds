#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100
int stack[SIZE], top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[] = "231*+9-";
    printf("Postfix Expression: %s\n", exp);
    printf("Result = %d\n", evaluatePostfix(exp));
    return 0;
}
