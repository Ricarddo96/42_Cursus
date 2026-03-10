/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:25:35 by ridoming          #+#    #+#             */
/*   Updated: 2025/10/27 23:10:01 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_infra(t_infra *infra, long num_philosophers)
{
	long	i;

	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_destroy(&infra->forks[i]);
		i++;
	}
	free(infra->threads);
	free(infra->forks);
	free(infra);
}

void	free_philos(t_infra *infra, long num_philosophers, t_philo *philo)
{
	long	i;

	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_destroy(&infra->forks[i]);
		pthread_mutex_destroy(&philo[i].eat_mutex);
		i++;
	}
	free(infra->threads);
	free(infra->forks);
	free(infra);
}

void	cleanup_threads(t_infra *thr_d, t_program_data *p_data)
{
	free_infra(thr_d, p_data->input.num_philosophers);
	pthread_mutex_destroy(&p_data->write_mutex);
	pthread_mutex_destroy(&p_data->sim_mutex);
	free(p_data);
}
