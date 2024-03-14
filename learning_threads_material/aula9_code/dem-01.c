#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "common.h"
#include "common_threads.h"

int inSync= 0;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cnd = PTHREAD_COND_INITIALIZER;


void myThrWait() {
 pthread_mutex_lock(&mtx);
    while (!inSync) pthread_cond_wait(&cnd, &mtx);
  pthread_mutex_unlock(&mtx);
}


void myThrSign() {
  pthread_mutex_lock(&mtx);
    inSync= 1;
    pthread_cond_signal(&cnd);
  pthread_mutex_unlock(&mtx);
}



void *child(void *arg) {

    printf("child begins and sleeps 5s\n"); sleep(5);

    myThrSign();

    printf("child ends\n");
    return NULL;
}

int main(int argc, char *argv[]) {

    pthread_t p;

    printf("parent begins\n");

    Pthread_create(&p, NULL, child, NULL);

    myThrWait();

    printf("parent ends\n");

    return 0;
}
