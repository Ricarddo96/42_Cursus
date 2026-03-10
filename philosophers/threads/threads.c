/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:25:35 by ridoming          #+#    #+#             */
/*   Updated: 2025/10/27 23:10:01 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	assign_memory(t_infra *infra, t_input data)
{
	long	i;

	i = 0;
	infra->threads = malloc(data.num_philosophers * sizeof(pthread_t));
	if (!infra->threads)
		return (0);
	infra->forks = malloc(data.num_philosophers * sizeof(pthread_mutex_t));
	if (!infra->forks)
		return (free(infra->threads), 0);
	while (i < data.num_philosophers)
	{
		if (pthread_mutex_init(&infra->forks[i], NULL))
			break ;
		i++;
	}
	if (i < data.num_philosophers)
	{
		free_infra(infra, i);
		return (0);
	}
	return (1);
}

int	join_structs(t_infra **infra, t_program_data **p_data, t_input input_data)
{
	*infra = malloc(sizeof(t_infra));
	if (!*infra)
		return (0);
	if (!assign_memory(*infra, input_data))
		return (free(*infra), 0);
	*p_data = malloc(sizeof(t_program_data));
	if (!*p_data)
	{
		free_infra(*infra, input_data.num_philosophers);
		return (0);
	}
	(*p_data)->infrastructure = *infra;
	(*p_data)->input = input_data;
	return (1);
}

void	init_philo(t_infra *infra, t_program_data *p_data, t_philo *philo)
{
	long	i;

	i = 0;
	while (i < p_data->input.num_philosophers)
	{
		philo[i].data = p_data;
		philo[i].id = i + 1;
		philo[i].left_fork = &infra->forks[i];
		philo[i].right_fork = &infra->forks[(i + 1)
			% p_data->input.num_philosophers];
		philo[i].last_time_i_eat = 0;
		philo[i].times_eaten = 0;
		pthread_mutex_init(&philo[i].eat_mutex, NULL);
		i++;
	}
}

static int	launch_threads(t_infra *infra, t_program_data *p_data,
				t_philo *philo, pthread_t *monitor)
{
	long	i;

	i = 0;
	while (i < p_data->input.num_philosophers)
	{
		if (pthread_create(&infra->threads[i], NULL, routine, &philo[i]))
			return (0);
		i++;
	}
	if (pthread_create(monitor, NULL, check_death_flag, philo))
		return (0);
	return (1);
}

int	run_threads(t_infra *infra, t_program_data *p_data)
{
	t_philo		*philo;
	pthread_t	monitor_death;
	long		i;

	i = 0;
	philo = malloc(p_data->input.num_philosophers * sizeof(t_philo));
	if (!philo)
		return (0);
	init_philo(infra, p_data, philo);
	if (!launch_threads(infra, p_data, philo, &monitor_death))
		return (free_philos(infra, p_data->input.num_philosophers, philo),
			free(philo), 0);
	while (i < p_data->input.num_philosophers)
		pthread_join(infra->threads[i++], NULL);
	pthread_join(monitor_death, NULL);
	i = 0;
	while (i < p_data->input.num_philosophers)
	{
		pthread_mutex_destroy(&philo[i].eat_mutex);
		i++;
	}
	free(philo);
	return (1);
}
