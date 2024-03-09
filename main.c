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
    if (!check_args(argc, argv))
        printf(INVALID_INPUT);
    else 
        printf("valid argument format\n");
    return 0;
}