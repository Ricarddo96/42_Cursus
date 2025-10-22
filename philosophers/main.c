/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:25:35 by ridoming          #+#    #+#             */
/*   Updated: 2025/10/22 15:38:02 by ridoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// UTILS

long long ft_atoll(const char *nptr)
{
    int i;
    int signo;
    long long resultado;

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

// PARSER

void print_usage(void)
{
    printf("Usage: ./philo number_of_philosophers time_to_die ");
    printf("time_to_eat time_to_sleep ");
    printf("[number_of_times_each_philosopher_must_eat]\n\n");
    printf("Arguments:\n");
    printf("  1. number_of_philosophers:\tNumber of philosophers and ");
    printf("forks (positive integer).\n");
    printf("  2. time_to_die (ms):\t\tTime (in milliseconds) a ");
    printf("philosopher can spend without eating before dying.\n");
    printf("  3. time_to_eat (ms):\t\tTime (in milliseconds) a ");
    printf("philosopher takes to eat.\n");
    printf("  4. time_to_sleep (ms):\tTime (in milliseconds) a ");
    printf("philosopher takes to sleep.\n");
    printf("  5. [OPTIONAL] num_times_to_eat:\tIf provided, the ");
    printf("simulation stops when all philosophers have eaten at ");
    printf("least this many times.\n");
    printf("\n**All numbers must be positive integers (greater than 0) ");
    printf("and fit within the range of a 'long'.**\n");
    printf("\n");
}

int check_valid_numbers(int argc, char **argv)
{
    int i;
    int j;
    long long arg;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return (0);
            j++;
        }
        arg = ft_atoll(argv[i]);
        if (arg <= 0 || arg > LONG_MAX)
            return (0);
        i++;
    }
    return (1);
}

int parser(int argc, char **argv, t_input_data *input_data)
{
    if (!(argc == 5 || argc == 6))
        return (print_usage(), 0);
    if (!check_valid_numbers(argc, argv))
        return (print_usage(), 0);
    input_data->num_philosophers = (long)ft_atoll(argv[1]);
    input_data->time_to_die = (long)ft_atoll(argv[2]);
    input_data->time_to_eat = (long)ft_atoll(argv[3]);
    input_data->time_to_sleep = (long)ft_atoll(argv[4]);
    if (argc == 6)
        input_data->num_times_to_eat = (long)ft_atoll(argv[5]);
    return (1);
}

// THREADS

int assign_memory(t_phil_thr *phil_thr, t_input_data data)
{
    long i = 0;
    
    phil_thr->threads = malloc(data.num_philosophers * sizeof(pthread_t));
    if (!phil_thr->threads)
    return (0);
    phil_thr->forks = malloc(data.num_philosophers * sizeof(pthread_mutex_t));
    if (!phil_thr->forks)
    return (free(phil_thr->threads), 0);
    while (i < data.num_philosophers)
    {
        if (pthread_mutex_init(&phil_thr->forks[i], NULL))
        break;
        i++;
    }
    if (i < data.num_philosophers)
    {
        while (--i >= 0)
        pthread_mutex_destroy(&phil_thr->forks[i]);
        free(phil_thr->threads);
        free(phil_thr->forks);
        return (0);
    }
    return (1);
}

t_program_data join_structures(t_phil_thr *phil_thr, t_input_data data)
{
    t_program_data total_data;
    
    total_data.infrastructure = phil_thr;
    total_data.input = data;
    return (total_data);
}

int init_threads_memory(t_phil_thr **thr_d, t_program_data **p_data, t_input_data dt)
{
    *thr_d = malloc(sizeof(t_phil_thr));
    if (!*thr_d)
    return (0);
    if (!assign_memory(*thr_d, dt))
    return (free(*thr_d), 0);
    *p_data = malloc(sizeof(t_program_data));
    if (!*p_data)
    {
        free((*thr_d)->threads);
        free((*thr_d)->forks);
        free(*thr_d);
        return (0);
    }
    **p_data = join_structures(*thr_d, dt);
    return (1);
}

int run_threads(t_phil_thr *thr_d, t_program_data *p_data)
{
    long i;
    
    i = 0;
    while (i < p_data->input.num_philosophers)
    {
        if (pthread_create(&thr_d->threads[i++], NULL, routine, p_data))
        return (free(thr_d->threads), free(thr_d->forks), 0);
    }
    i = 0;
    while (i < p_data->input.num_philosophers)
    pthread_join(thr_d->threads[i++], NULL);
    return (1);
}

void cleanup_threads(t_phil_thr *thr_d, t_program_data *p_data)
{
    long i = 0;
    while (i < p_data->input.num_philosophers)
    pthread_mutex_destroy(&thr_d->forks[i++]);
    free(thr_d->threads);
    free(thr_d->forks);
    free(thr_d);
    free(p_data);
}

// ROUTINE

void *routine(void *data)
{
    t_program_data *p_data;

    p_data = (t_program_data *)data;
    
    return (NULL);
}

// MAIN

int create_philosophers(t_input_data data)
{
    t_phil_thr *thr_d;
    t_program_data *p_data;
    
    if (!init_threads_memory(&thr_d, &p_data, data))
        return (0);
    if (!run_threads(thr_d, p_data))
    {
        cleanup_threads(thr_d, p_data);
        return (0);
    }
    cleanup_threads(thr_d, p_data);
    return (1);
}

int main(int argc, char **argv)
{
    t_input_data input_data;
    
    if (!parser(argc, argv, &input_data))
    return (EXIT_FAILURE);
    if (!create_philosophers(input_data))
    return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}