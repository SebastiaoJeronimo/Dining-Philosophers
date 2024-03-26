#include "philosophers.h"

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
        printf("valid argument format\n"); //REMOVE THIS PRINT
    start_program();
    //free philosophers
    free_struct();
    return 0;
}