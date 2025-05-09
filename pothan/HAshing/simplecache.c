#include <stdio.h>
#include <string.h>
#define SIZE 10

struct Cache {
    int key;
    char value[100];
};

struct Cache cache[SIZE];

int hash(int key) {
    return key % SIZE;
}

void insert(int key, const char* value) {
    int index = hash(key);
    while (cache[index].key != -1 && cache[index].key != key)
        index = (index + 1) % SIZE;
    cache[index].key = key;
    strcpy(cache[index].value, value);
}

void get(int key) {
    int index = hash(key);
    while (cache[index].key != -1) {
        if (cache[index].key == key) {
            printf("Cache Hit! Value = %s\n", cache[index].value);
            return;
        }
        index = (index + 1) % SIZE;
    }
    printf("Cache Miss!\n");
}

void initCache() {
    for (int i = 0; i < SIZE; i++)
        cache[i].key = -1;
}

int main() {
    initCache();
    insert(1, "Page_A");
    insert(11, "Page_B");
    get(1);   // Hit
    get(2);   // Miss
    return 0;
}
