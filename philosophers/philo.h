/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridoming <ridoming@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:07:18 by ridoming          #+#    #+#             */
/*   Updated: 2025/10/21 13:27:03 by ridoming         ###   ########.fr       */
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


typedef struct philo_input
{
    long num_philosophers;           
    long time_to_die;               
    long time_to_eat;               
    long time_to_sleep;             
    long num_times_to_eat;
} t_input_data;


#endif