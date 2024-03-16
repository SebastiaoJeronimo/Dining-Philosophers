#include "philosophers.h"

t_data *get_data(){
    static t_data data;
    
    return (&data);
}
