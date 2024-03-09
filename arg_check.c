#include "philosophers.h"

/**
 * @brief stores the valid input number in the static/singleton struct
 * 
 * @param num_arg the number of the argv position of the argument
 * @param num the int of the argv number
 */
void store_valid_input(int num_arg, int num)
{
    t_data *data;

    data = get_data();
    if(num_arg == N_PHILO)
        data->n_philo = num_arg;
    else if (num_arg == T_DIE)
        data->time_die = num_arg;
    else if (num_arg == T_EAT)
        data->time_eat = num_arg;
    else if (num_arg == T_SLEEP)
        data->time_sleep = num_arg;
    else
        data->eat_times = num_arg;
}

/**
 * @brief checks if the number is valid it has to be positive and lower than < 1
 * 
 * @param num_str each arg which is a number in string format
 * @returns 0 if the number is valid and returns the number if its valid //
 */
int check_valid_number(char *num_str)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while(num_str[i])
    {
        if ((num > INT_MAX) | !ft_isdigit(num_str[i]))
            return 0;
        num += num*10 + (num_str[i] - '0');
        i++;
    }
    return num;
}

/**
 * @brief checks if the arguments are in the correct format
 * 
 * @param argc number of arguments
 * @param argv the array with with arguments
 * @returns 1 if the arguments are in a correct form  0 if not
 */
int check_args(int argc, char **argv)
{
    int i = 1;
    int num = 0;
    
    if (!(argc == 5 || argc == 6))
        return 0;
    while (i < argc)
    {
        num = check_valid_number(argv[i]);
        printf("this %d input is the number %d\n",i,num);
        if (!num)  
            return 0;
        store_valid_input(i, num);
        //attribute the values to static struct
        i++;
    }
    return 1;
}