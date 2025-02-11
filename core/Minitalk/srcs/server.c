/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:33:12 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/11 16:33:18 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    signal_handler(int signal)
{
    char c;

    c = 0;
    if(signal == SIGUSR1)
        c |=  1;
    else if (signal == SIGUSR2)
        c |= 0;
    
}

int main()
{
    struct sigaction sig;
    int pid = getpid();
    ft_printf("%d", pid);
    sig.sa_handler = signal_handler;
    sigemptyset(&sig.sa_mask);
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    while(1)
        pause();
}