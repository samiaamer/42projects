/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:33:12 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/12 19:47:15 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char chr = 0;

void    signal_handler(int sig)
{     
        static int j = 7;
        static char c = 0;
        if(sig == SIGUSR1)
                c |= 1 << j;
        else if (sig == SIGUSR2)
                c |= 0 << j;
        j--;
        if (j < 0)
        {
            j = 7;
            chr = c;
            c = 0;
        }
}

char    *reallocation(char *str, char n_char)
{
    char *n_str;

    n_str = ft_strjoin(str, &n_char);
    if (!n_str)
        return (NULL);
    free(str);
    return (n_str);
}

int main()
{
    struct sigaction sig;
    char *str;
    int pid = getpid();
    int bit = 0;

    ft_printf("%d\n", pid);
    sig.sa_handler = signal_handler;
    sigemptyset(&sig.sa_mask);

    str = ft_strdup("");  // Initialize string to store message
    if (!str)
        return (1);

    while (1)
    {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        bit++;

        if (bit % 8 == 0)  // Every 8 bits, a character is complete
        {        
            str = reallocation(str, chr);
            if (!str)
                return (1);
            if (chr == '\0')
            {
                ft_printf("message is %s\n", str);
                free(str);
                str = ft_strdup("");  // Reset str for next message
                if (!str)
                    return (1);
            }
            bit = 0;  // Reset bit counter after processing a character
        }
        pause();
    }
}
