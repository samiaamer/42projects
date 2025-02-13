/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:30:43 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/13 16:07:24 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINTALK_H

# define _DEFAULT_SOURCE
# define _POSIX_SOURCE
# include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct s_minitalk
{
    int len;
}       t_minitalk;


int check_pid(char *pid);

# endif