/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:25:35 by ridoming          #+#    #+#             */
/*   Updated: 2025/10/27 23:10:01 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdbool.h>

void	think(t_philo *philo)
{
	long long	think_time;

	pthread_mutex_lock(&philo->data->sim_mutex);
	if (philo->data->sim_finished)
	{
		pthread_mutex_unlock(&philo->data->sim_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->sim_mutex);
	pthread_mutex_lock(&philo->data->write_mutex);
	printf("%lld %ld is thinking\n",
		get_timestamp(philo->data->start_time), philo->id);
	pthread_mutex_unlock(&philo->data->write_mutex);
	if (philo->data->input.num_philosophers % 2 == 1)
	{
		think_time = (philo->data->input.time_to_eat * 2)
			- philo->data->input.time_to_sleep;
		if (think_time > 0 && think_time < philo->data->input.time_to_die)
			ft_usleep(think_time, philo->data);
	}
}

int	eat(t_philo *philo)
{
	long long	now;

	if (lock_forks(philo))
		return (1);
	pthread_mutex_lock(&philo->data->sim_mutex);
	if (philo->data->sim_finished)
	{
		pthread_mutex_unlock(&philo->data->sim_mutex);
		unlock_forks(philo);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->sim_mutex);
	now = get_timestamp(philo->data->start_time);
	pthread_mutex_lock(&philo->data->write_mutex);
	printf("%lld %ld is eating\n", now, philo->id);
	pthread_mutex_unlock(&philo->data->write_mutex);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_time_i_eat = now;
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->eat_mutex);
	ft_usleep(philo->data->input.time_to_eat, philo->data);
	unlock_forks(philo);
	return (0);
}

void	go_to_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->sim_mutex);
	if (philo->data->sim_finished)
	{
		pthread_mutex_unlock(&philo->data->sim_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->sim_mutex);
	pthread_mutex_lock(&philo->data->write_mutex);
	printf("%lld %ld is sleeping\n",
		get_timestamp(philo->data->start_time), philo->id);
	pthread_mutex_unlock(&philo->data->write_mutex);
	ft_usleep(philo->data->input.time_to_sleep, philo->data);
}

void	*routine(void *philo_data)
{
	t_philo	*philo;
	long	i;

	philo = (t_philo *)philo_data;
	i = 0;
	init_routine(philo);
	while (!sim_is_done(philo))
	{
		if (philo->data->input.num_times_to_eat != -1
			&& i >= philo->data->input.num_times_to_eat)
			break ;
		if (eat(philo))
			break ;
		if (sim_is_done(philo))
			break ;
		go_to_sleep(philo);
		if (sim_is_done(philo))
			break ;
		think(philo);
		i++;
	}
	return (NULL);
}
