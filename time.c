#include "philosophers.h"

/**
 * @brief get the time using the archaic function gettimeofday
 * @return long long that corresponds to the time in miliseconds
 */
long long getTime(){

    struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec/1000));
}

int main (){
    long long start_value = getTime();
    printf("starting time : %lld \n",getTime()- start_value);
    usleep(1000);
    printf("time after 1 second: %lld \n",getTime() -start_value);
}