#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void initHashTable() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE)
        i++;
    if (i < SIZE)
        hashTable[(index + i) % SIZE] = key;
    else
        printf("Hash table is full!\n");
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("[%d] => %d\n", i, hashTable[i]);
}

int main() {
    initHashTable();
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    display();
    return 0;
}
