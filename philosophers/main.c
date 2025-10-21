/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:25:35 by ridoming          #+#    #+#             */
/*   Updated: 2025/10/21 14:44:39 by ridoming         ###   ########.fr       */
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

// PARSER (borrar print_parser)

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

void print_parser(t_input_data input_data)
{
    printf("\n--- Parser Verification ---\n");
    printf("Philosophers:\t\t\t%ld\n", input_data.num_philosophers);
    printf("Time to Die (ms):\t\t%ld\n", input_data.time_to_die);
    printf("Time to Eat (ms):\t\t%ld\n", input_data.time_to_eat);
    printf("Time to Sleep (ms):\t\t%ld\n", input_data.time_to_sleep);

    printf("Meals to Complete:\t\t");
    if (input_data.num_times_to_eat > 0)
        printf("%ld\n", input_data.num_times_to_eat);
    else
        printf("Infinite (Stop on Death)\n");

    printf("---------------------------\n\n");
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

// el input data no va con malloc porque vamos a hacer que se almacene en el stack como una variable ya que para pasar su direccion lo podemos hacer como un puntero, ademas que su contenido no va a ser dinamico en tiempo de ejecucion

int main(int argc, char **argv)
{
    t_input_data input_data;

    if (!parser(argc, argv, &input_data))
        return (1);
    print_parser(input_data);
    return (0);
}