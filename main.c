#include "philosophers.h"

/**
 * @brief main function of the program
 * 
 * @param argc number of arguments of the program
 * @param argv arguments of the program
 */
int main(int argc, char **argv){
    printf("number of args: %d\n",argc);
    int i = 1;
    while (i <= argc)
    {
        printf("argc num %d é : %s\n", i, argv[i-1]);
        i++;
    }


    
    // if ()
    // argc > 0  e argc == 4 || argc == 5 
    // argv[1] tem que ser int && argv[1] > 0 (num philo)     && <MAX_INT
    // argv[2] tem que ser int && argv[2] > 0 (time to die)   && <MAX_INT
    // argv[3] tem que ser int && argv[3] > 0 (time to eat)   && <MAX_INT
    // argv[4] tem que ser int && argv[4] > 0 (time to sleep)  && <MAX_INT
    // argv[5] tem que ser int && argv[5] > 0 (number of times a philosopher must eat) && <MAX_INT

    //to guarantee that the argv are numbers i need to be shore that 

    return 0;
}