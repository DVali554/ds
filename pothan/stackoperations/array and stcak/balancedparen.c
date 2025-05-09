#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1 || !isMatchingPair(pop(), ch))
                return 0;
        }
    }
    return (top == -1);
}

int main() {
    char exp[] = "{[()]}";
    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
