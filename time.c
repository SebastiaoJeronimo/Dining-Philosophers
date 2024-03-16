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
 * @brief Get the real time difference since starting the program
 * 
 * @param num is the number that is going to be subtracted to the initial value
 * @return long long the real time value
 */
long long get_real_time(long long num)
{
    return (num - get_data()->start_time);
}

/**
 * @brief computes the time diff
 * 
 * @param num1 the latest timestamp
 * @param num2 teh older  timestamp
 * @returns the difference bettween the two numebrs of miliseconds
 */
long long time_diff(long long num1, long long num2)
{
    return (num1 - num2);
}

/**
 * @brief checks if the philosopher starved 
 * using its last meal timestamp
 * 
 * @param last_meal_time the last time that the philosopher ate
 * @returns 1 if the philosopher starved and 0 if it didnt starve
 */
long long did_philo_starve(long long last_meal_time)
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