#include "philosophers.h"

/**
 * @brief prints the number of arguments of the singleton structure
 */
void printArgs()
{
    t_data *data = get_data();
    printf("%d %d %d %d %d\n", data->n_philo, data->time_die, data->time_eat, data->time_eat, data->eat_times);
}

/**
 * @brief main function of the program
 *
 * @param argc number of arguments of the program
 * @param argv arguments of the program
 */
int main(int argc, char **argv)
{
    if (!check_args(argc, argv))
        printf(INVALID_INPUT);
    else
        printf("valid argument format\n");


    start_program();

    // usleep e gettime
    // do the part of initializing only one philo

    // initialize philos
    // initialize forks

    /* PHILOSOPHERS ROUTINE
    while (1) {
        getforks()
        eat()
        putforks()
        sleep()
        think()
    }

    PTHREAD_THREADS_MAX
    */

    // usleep strategy
    // change the order of acquiring forks

    return 0;
}