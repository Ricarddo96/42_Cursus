/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:25:35 by ridoming          #+#    #+#             */
/*   Updated: 2025/10/23 15:25:02 by ridoming         ###   ########.fr       */
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

void free_infra(t_infra *infra, long num_philosophers)
{
    long i;

    i = 0;
    while (i < num_philosophers)
        pthread_mutex_destroy(&infra->forks[i++]);
    free(infra->threads);
    free(infra->forks);
    free(infra);
}

void cleanup_threads(t_infra *thr_d, t_program_data *p_data)
{
    free_infra(thr_d, p_data->input.num_philosophers);
    pthread_mutex_destroy(&p_data->write_mutex);
    free(p_data);
}

long long get_timestamp(struct timeval time_start)
{
    struct timeval current_time;
    long long elapsed_ms;

    if (gettimeofday(&current_time, NULL) == -1)
        return (0);
    elapsed_ms = (current_time.tv_sec - time_start.tv_sec) * 1000;
    elapsed_ms += (current_time.tv_usec - time_start.tv_usec) / 1000;
    return (elapsed_ms);
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

int parser(int argc, char **argv, t_input *input_data)
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

int assign_memory(t_infra *infra, t_input data)
{
    long i = 0;

    infra->threads = malloc(data.num_philosophers * sizeof(pthread_t));
    if (!infra->threads)
        return (0);
    infra->forks = malloc(data.num_philosophers * sizeof(pthread_mutex_t));
    if (!infra->forks)
        return (free(infra->threads), 0);
    while (i < data.num_philosophers)
    {
        if (pthread_mutex_init(&infra->forks[i], NULL))
            break;
        i++;
    }
    if (i < data.num_philosophers)
    {
        free_infra(infra, i);
        return (0);
    }
    return (1);
}

int join_structs(t_infra **infra, t_program_data **p_data, t_input input_data)
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

int run_threads(t_infra *infra, t_program_data *p_data)
{
    t_philo *philo; // hay que refactorizar esta funcion y crear otra para inicializar cada filosofo y unir estructuras (lo del primer while)
    long i;

    i = 0;
    philo = malloc(p_data->input.num_philosophers * sizeof(t_philo));
    if (!philo)
        return (0);
    while (i < p_data->input.num_philosophers)
    {
        philo[i].data = p_data;
        philo[i].id = i + 1;
        philo[i].left_fork = &infra->forks[i];
        philo[i].right_fork = &infra->forks[(i + 1) % p_data->input.num_philosophers];
        i++;
    }
    i = 0;
    while (i < p_data->input.num_philosophers)
    {
        if (pthread_create(&infra->threads[i], NULL, routine, &philo[i]))
            return (free_infra(infra, p_data->input.num_philosophers), free(philo), 0);
        i++;
    }
    i = 0;
    while (i < p_data->input.num_philosophers)
        pthread_join(infra->threads[i++], NULL);
    return (free(philo), 1);
}

// ROUTINE

void *routine(void *philo_data)
{
    t_philo *philo;
    long i;

    philo = (t_philo *)philo_data;
    i = 0;
    pthread_mutex_lock(&philo->data->write_mutex);
    printf("%lld %ld is thinking\n", get_timestamp(philo->data->start_time), philo->id);
    pthread_mutex_unlock(&philo->data->write_mutex);
    if (philo->data->input.num_times_to_eat > 0)
    {
        while (i < philo->data->input.num_times_to_eat)
        {
            pthread_mutex_lock(philo->left_fork);
            pthread_mutex_lock(&philo->data->write_mutex);
            printf("%lld %ld has taken left fork\n", get_timestamp(philo->data->start_time), philo->id);
            pthread_mutex_unlock(&philo->data->write_mutex);

            pthread_mutex_lock(philo->right_fork);
            pthread_mutex_lock(&philo->data->write_mutex);
            printf("%lld %ld has taken right fork\n", get_timestamp(philo->data->start_time), philo->id);
            pthread_mutex_unlock(&philo->data->write_mutex);

            pthread_mutex_lock(&philo->data->write_mutex);
            printf("%lld %ld is eating\n", get_timestamp(philo->data->start_time), philo->id);
            pthread_mutex_unlock(&philo->data->write_mutex);
            usleep(philo->data->input.time_to_eat * 1000);
            i++;
            pthread_mutex_unlock(philo->left_fork);
            pthread_mutex_unlock(philo->right_fork);
        }
    }
    pthread_mutex_lock(&philo->data->write_mutex);
    printf("%lld %ld is sleeping\n", get_timestamp(philo->data->start_time), philo->id);
    pthread_mutex_unlock(&philo->data->write_mutex);
    usleep(philo->data->input.time_to_sleep * 1000);
    return (NULL);
}

// MAIN

int create_philosophers(t_input input_data, struct timeval *start_time)
{
    t_infra *infra;
    t_program_data *p_data;
   
    if (!join_structs(&infra, &p_data, input_data))
        return (0);
    p_data->start_time = *start_time;
    pthread_mutex_init(&p_data->write_mutex, NULL);
    if (!run_threads(infra, p_data))
    {
        cleanup_threads(infra, p_data);
        return (0);
    }
    cleanup_threads(infra, p_data);
    return (1);
}

int main(int argc, char **argv)
{
    t_input input_data;
    struct timeval start_time;
    
    if (!parser(argc, argv, &input_data))
        return (EXIT_FAILURE);
    if (gettimeofday(&start_time, NULL) == -1)
        return (EXIT_FAILURE);
    if (!create_philosophers(input_data, &start_time))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}