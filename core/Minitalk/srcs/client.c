/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:40:06 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/15 11:18:25 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int check_pid(char *pid)
{
    int i;
    int nbr;

    nbr = 0;
    i = 0;
    while (pid[i])
    {
        if (!(pid[i] >= '0' && pid[i] <= '9'))
        {
            ft_printf("ERROR\n");
                exit(1);
        }
        i++;
    }
    nbr = ft_atoi(pid);
    if (nbr < 0)
        exit(1);
    return (nbr);
}

void    end_str(int pid)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if(kill(pid, SIGUSR2) == -1)
            return;
        i++;
        usleep(400);
    }
}

void    convert(int pid, char *str)
{
    int     i;
    
    (void) pid;
    while (*str)
    {
         i = 7;
        while (i >= 0)
        {
            if ((*str >> i) & 1)
            {
                if(kill(pid, SIGUSR1) == -1)
                    return;
            }
            else if (!((*str >> i) & 1))
            {    
                if(kill(pid, SIGUSR2) == -1)
                    return;
            }
            i--;
            usleep(400);
        }
        str++;
    }
    end_str(pid);
}

int main(int argc, char **argv)
{
    if(argc == 3)
    {
        int pid;
        
        pid = check_pid(argv[1]);
        convert(pid, argv[2]);
    }
    return (0);
}