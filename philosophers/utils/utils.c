/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:25:35 by ridoming          #+#    #+#             */
/*   Updated: 2025/10/27 23:10:01 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	ft_atoll(const char *nptr)
{
	int			i;
	int			signo;
	long long	resultado;

	i = 0;
	signo = 1;
	resultado = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		signo = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		resultado = resultado * 10 + (nptr[i] - '0');
		i++;
	}
	return (signo * resultado);
}

long long	get_timestamp(struct timeval start_time)
{
	struct timeval	current_time;
	long long		elapsed_ms;

	if (gettimeofday(&current_time, NULL) == -1)
		return (0);
	elapsed_ms = (current_time.tv_sec - start_time.tv_sec) * 1000;
	elapsed_ms += (current_time.tv_usec - start_time.tv_usec) / 1000;
	return (elapsed_ms);
}

void	ft_usleep(long long duration, t_program_data *data)
{
	long long	start;
	bool		finished;

	start = get_timestamp(data->start_time);
	while (1)
	{
		pthread_mutex_lock(&data->sim_mutex);
		finished = data->sim_finished;
		pthread_mutex_unlock(&data->sim_mutex);
		if (finished || get_timestamp(data->start_time) - start >= duration)
			break ;
		usleep(50);
	}
}

int	philo_is_dead(t_philo *philo, t_program_data *data, long i)
{
	long long	now;

	now = get_timestamp(data->start_time);
	if (philo[i].last_time_i_eat <= 0
		|| (now - philo[i].last_time_i_eat) < data->input.time_to_die)
		return (0);
	pthread_mutex_lock(&data->write_mutex);
	pthread_mutex_lock(&data->sim_mutex);
	if (!data->sim_finished)
	{
		data->sim_finished = true;
		printf("%lld %ld died\n", now, philo[i].id);
	}
	pthread_mutex_unlock(&data->sim_mutex);
	pthread_mutex_unlock(&data->write_mutex);
	return (1);
}

long	check_all_philos(t_philo *philo, t_program_data *data)
{
	long	i;
	long	finished;

	i = 0;
	finished = 0;
	while (i < philo->data->input.num_philosophers)
	{
		pthread_mutex_lock(&data->sim_mutex);
		if (data->sim_finished)
			return (pthread_mutex_unlock(&data->sim_mutex), -1);
		pthread_mutex_unlock(&data->sim_mutex);
		pthread_mutex_lock(&philo[i].eat_mutex);
		if (philo_is_dead(philo, data, i))
			return (pthread_mutex_unlock(&philo[i].eat_mutex), -1);
		if (data->input.num_times_to_eat != -1
			&& philo[i].times_eaten >= data->input.num_times_to_eat)
			finished++;
		pthread_mutex_unlock(&philo[i].eat_mutex);
		i++;
	}
	return (finished);
}
