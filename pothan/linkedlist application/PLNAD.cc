#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coeff, power;
    struct PolyNode* next;
};

void append(struct PolyNode** poly, int coeff, int power) {
    struct PolyNode* newNode = (struct PolyNode*) malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;

    if (*poly == NULL)
        *poly = newNode;
    else {
        struct PolyNode* temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

struct PolyNode* addPolynomials(struct PolyNode* poly1, struct PolyNode* poly2) {
    struct PolyNode* result = NULL;
    while (poly1 && poly2) {
        if (poly1->power > poly2->power) {
            append(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else if (poly1->power < poly2->power) {
            append(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else {
            append(&result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        append(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2) {
        append(&result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

void printPolynomial(struct PolyNode* poly) {
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->power);
        if (poly->next) printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    struct PolyNode *poly1 = NULL, *poly2 = NULL;

    append(&poly1, 3, 3);
    append(&poly1, 4, 2);
    append(&poly1, 2, 0);

    append(&poly2, 5, 1);
    append(&poly2, 5, 0);

    printf("First polynomial: ");
    printPolynomial(poly1);

    printf("Second polynomial: ");
    printPolynomial(poly2);

    struct PolyNode* sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    printPolynomial(sum);

    return 0;
}
