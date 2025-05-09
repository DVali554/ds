#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

void infixToPostfix(char* infix) {
    char ch;
    int i = 0;
    printf("Postfix: ");
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            printf("%c", ch);
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                printf("%c", pop());
            pop(); // Remove '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                printf("%c", pop());
            push(ch);
        }
    }
    while (top != -1)
        printf("%c", pop());
    printf("\n");
}

int main() {
    char infix[] = "a+b*(c-d)";
    printf("Infix: %s\n", infix);
    infixToPostfix(infix);
    return 0;
}
