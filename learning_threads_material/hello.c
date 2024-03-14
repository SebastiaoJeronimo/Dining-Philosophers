/*
* hello.c - Pthreads "hello, world" program
*/
#include "pthread.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

volatile int counter = 0; // shared global variable

void *mythread(void *arg) {
    char *letter = arg; int i;
    printf("%s: begin [addr of i: %p]\n", letter, &i);
    for (i = 0; i < 100; i++) counter = counter + 1;
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p1, p2;
    printf("main: begin [counter = %d] [%x]\n", counter, (unsigned int) &counter);
    pthread_create(&p1, NULL, mythread, "A"); pthread_join(p1, NULL);
    pthread_create(&p2, NULL, mythread, "B"); pthread_join(p2, NULL);
    printf("main: done\n [counter: %d]\n [should: %d]\n", counter, 100*2);
    return 0;
}

//---------------------------------------------------------------------------------------------------

/*
void *minhaThread(void *vargp);

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, minhaThread, NULL);
    pthread_join(tid, NULL);
    exit(0);
}

void *minhaThread(void *vargp) {
    printf("Hello, world!\n");
    return NULL;
}
*/