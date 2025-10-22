/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:07:18 by ridoming          #+#    #+#             */
/*   Updated: 2025/10/22 14:52:00 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include <stdbool.h>


typedef struct philo_input
{
    long num_philosophers;           
    long time_to_die;               
    long time_to_eat;               
    long time_to_sleep;             
    long num_times_to_eat;
} t_input_data;

typedef struct philo_threads
{
    pthread_t   *threads;
    pthread_mutex_t *forks;
} t_phil_thr;

typedef struct s_program_data
{
    t_input_data    input;
    t_phil_thr      *infrastructure;
    long            start_time_ms;
    pthread_mutex_t write_mutex;
    bool            sim_finished;
} t_program_data;

typedef struct s_philo {
    long id;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_program_data *data;
} t_philo;

#endif