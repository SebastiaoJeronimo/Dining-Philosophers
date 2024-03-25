threads.c

#include "../inc/philo.h"

int	init_threads(t_table *f)
{
	int	i;

	i = 0;
	while (i < f->data->number_of_philo)
	{
		if (pthread_create(&f->philo[i].thread,
				NULL, (void *)routine, &(f->philo[i])))
			return (0);
		i++;
	}
	return (1);
}

int	join_threads(t_table *f)
{
	int	i;

	i = 0;
	while (i < f->data->number_of_philo)
	{
		if (pthread_join(f->philo[i].thread, NULL))
			return (0);
		i++;
	}
	return (1);
}