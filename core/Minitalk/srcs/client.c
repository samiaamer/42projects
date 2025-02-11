/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:40:06 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/11 15:52:55 by sabutale         ###   ########.fr       */
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
            write(1,"ERROR\n", 5);
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
        kill(pid, SIGUSR2);
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
                printf("1");
                //kill(pid, SIGUSR1);
            else if (!((*str >> i) & 1))
                printf("0");
                //kill(pid, SIGUSR2);
            i--;
        }
        
        str++;
        printf("\n");
    }
    end_str(pid);
}

int main(int argc, char **argv)
{
    if(argc == 3)
    {
        int pid;
        
        pid = check_pid(argv[1]);
        // printf("%d\n", pid);
        convert(pid, argv[2]);
    }
}