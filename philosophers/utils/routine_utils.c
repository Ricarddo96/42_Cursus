/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:25:35 by ridoming          #+#    #+#             */
/*   Updated: 2025/10/27 23:10:01 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	sim_is_done(t_philo *philo)
{
	bool	finished;

	pthread_mutex_lock(&philo->data->sim_mutex);
	finished = philo->data->sim_finished;
	pthread_mutex_unlock(&philo->data->sim_mutex);
	return (finished);
}

void	init_routine(t_philo *philo)
{
	while (get_timestamp(philo->data->start_time) == 0)
		usleep(1);
	if ((philo->id - 1) % 2 == 0)
		ft_usleep(philo->data->input.time_to_eat, philo->data);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_time_i_eat = get_timestamp(philo->data->start_time);
	pthread_mutex_unlock(&philo->eat_mutex);
}

int	take_fork(pthread_mutex_t *fork, t_philo *philo)
{
	pthread_mutex_lock(fork);
	pthread_mutex_lock(&philo->data->sim_mutex);
	if (philo->data->sim_finished)
	{
		pthread_mutex_unlock(&philo->data->sim_mutex);
		pthread_mutex_unlock(fork);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->sim_mutex);
	pthread_mutex_lock(&philo->data->write_mutex);
	printf("%lld %ld has taken a fork\n",
		get_timestamp(philo->data->start_time), philo->id);
	pthread_mutex_unlock(&philo->data->write_mutex);
	return (0);
}

int	handle_single_philo(t_philo *philo)
{
	if (take_fork(philo->right_fork, philo))
		return (1);
	ft_usleep(philo->data->input.time_to_die, philo->data);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}
