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

/**
 * @brief checks if the philosopher starved 
 * using its last meal timestamp
 * 
 * @param last_meal_time the last time that the philosopher ate
 * @returns 1 if the philosopher starved and 0 if it didnt starve
 */
int did_philo_starve(long long last_meal_time)
{
    t_data  *data;

    data = get_data();
    if ((getTime() - last_meal_time) > data->time_eat)
        return (1);
    return (0);
}

/*
int main (){
    long long start_value = getTime();
    printf("starting time : %lld \n",getTime()- start_value);
    usleep(2000);
    printf("time after 3 miliseconds: %lld \n",getTime() - start_value);
}
*/