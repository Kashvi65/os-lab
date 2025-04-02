#include <stdio.h>

#define BUFFER_SIZE 5

int mutex = 1;
int full = 0;
int empty = BUFFER_SIZE;
int x = 0;

void my_wait() {
    --mutex;
}

void my_signal() {
    ++mutex;
}

void producer() {
    if (empty > 0) {
        my_wait();
        ++full;
        --empty;
        x++;
        printf("Producer has produced: Item %d\n", x);
        my_signal();
    } else {
        printf("Buffer is full!\n");
    }
}

void consumer() {
    if (full > 0) {
        my_wait();
        --full;
        ++empty;
        printf("Consumer has consumed: Item %d\n", x);
        x--;
        my_signal();
    } else {
        printf("Buffer is empty!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("Enter 1.Producer 2.Consumer 3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
