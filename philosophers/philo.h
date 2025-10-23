/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:07:18 by ridoming          #+#    #+#             */
/*   Updated: 2025/10/23 15:21:01 by ridoming         ###   ########.fr       */
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

typedef struct s_philo_input
{
    long num_philosophers;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long num_times_to_eat;
} t_input;

typedef struct s_philo_infrastructure
{
    pthread_t *threads;
    pthread_mutex_t *forks;
} t_infra;

typedef struct s_program_data
{
    t_input input;
    t_infra *infrastructure;
    struct timeval start_time;
    pthread_mutex_t write_mutex;
    bool sim_finished;
} t_program_data;

typedef struct s_philo
{
    long id;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_program_data *data;
} t_philo;

// UTILS
long long ft_atoll(const char *nptr);

// CLEANUP
void free_infra(t_infra *infra, long num_philosophers);
void cleanup_threads(t_infra *thr_d, t_program_data *p_data);

// PARSER
void print_usage(void);
int check_valid_numbers(int argc, char **argv);
int parser(int argc, char **argv, t_input *input_data);

// THREADS
int assign_memory(t_infra *infra, t_input data);
int join_structs(t_infra **infra, t_program_data **p_data, t_input input_data);
int run_threads(t_infra *infra, t_program_data *p_data);

// ROUTINE
void *routine(void *program_data);

// MAIN
int create_philosophers(t_input input_data, struct timeval *start_time);

#endif