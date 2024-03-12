#include <stdio.h>
#include <pthread.h>

void *function1(void *arg) {
    printf("hello\n");
    pthread_exit(NULL);
}

void *function2(void *arg) {
    printf("World\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2; 

    if (pthread_create(&thread1, NULL, function1, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    if (pthread_join(thread1, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    if (pthread_create(&thread2, NULL, function2, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    if (pthread_join(thread2, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    return 0;
}
