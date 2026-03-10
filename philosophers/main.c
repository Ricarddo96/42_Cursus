/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:25:35 by ridoming          #+#    #+#             */
/*   Updated: 2025/10/27 23:10:01 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lock_forks(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->data->input.num_philosophers == 1)
		return (handle_single_philo(philo));
	if ((philo->id - 1) % 2 == 0)
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	else
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	if (take_fork(first, philo))
		return (1);
	if (take_fork(second, philo))
		return (pthread_mutex_unlock(first), 1);
	return (0);
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	create_philosophers(t_input input_data, struct timeval *start_time)
{
	t_infra			*infra;
	t_program_data	*p_data;

	if (!join_structs(&infra, &p_data, input_data))
		return (0);
	p_data->start_time = *start_time;
	p_data->sim_finished = false;
	pthread_mutex_init(&p_data->write_mutex, NULL);
	pthread_mutex_init(&p_data->sim_mutex, NULL);
	if (!run_threads(infra, p_data))
	{
		cleanup_threads(infra, p_data);
		return (0);
	}
	cleanup_threads(infra, p_data);
	return (1);
}

void	*check_death_flag(void *arg)
{
	t_philo			*philo;
	t_program_data	*data;
	long			finished;

	philo = (t_philo *)arg;
	data = philo[0].data;
	while (1)
	{
		finished = check_all_philos(philo, data);
		if (finished == -1)
			return (NULL);
		if (data->input.num_times_to_eat != -1
			&& finished >= data->input.num_philosophers)
		{
			pthread_mutex_lock(&data->sim_mutex);
			data->sim_finished = true;
			pthread_mutex_unlock(&data->sim_mutex);
			return (NULL);
		}
		usleep(10);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_input			input_data;
	struct timeval	start_time;

	if (!parser(argc, argv, &input_data))
		return (EXIT_FAILURE);
	if (gettimeofday(&start_time, NULL) == -1)
		return (EXIT_FAILURE);
	if (!create_philosophers(input_data, &start_time))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
