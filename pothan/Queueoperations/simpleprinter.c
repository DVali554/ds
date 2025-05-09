#include <stdio.h>
#define SIZE 5

char* printerQueue[SIZE];
int front = -1, rear = -1;

void addJob(char* job) {
    if (rear == SIZE - 1)
        printf("Printer Queue Full\n");
    else {
        if (front == -1) front = 0;
        printerQueue[++rear] = job;
        printf("Added Job: %s\n", job);
    }
}

void printJob() {
    if (front == -1 || front > rear)
        printf("No jobs to print\n");
    else
        printf("Printing Job: %s\n", printerQueue[front++]);
}

int main() {
    addJob("Document1.pdf");
    addJob("Report.docx");
    printJob();
    printJob();
    printJob();
    return 0;
}
