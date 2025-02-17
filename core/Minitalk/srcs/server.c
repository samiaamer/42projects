/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:33:12 by sabutale          #+#    #+#             */
/*   Updated: 2025/02/15 14:07:04 by sabutale         ###   ########.fr       */
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
    char *c;

    c =malloc(2);
    if(!c)
        return(NULL);
    c[0] = n_char;
    c[1] = '\0';
    n_str = ft_strjoin(str, c);
    if (!n_str)
        return (NULL);
    free(c);
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
    sig.sa_flags = SA_RESTART; 
    sigemptyset(&sig.sa_mask);
    str = ft_strdup("");  
    printf("str len %ld\n", ft_strlen(str));
    if (!str)
        return (1);
    if(sigaction(SIGUSR1, &sig, NULL) == -1)
    {
		ft_printf("Error: Could not handle SIGUSR1.\n");
		exit(1);
	}
    if (sigaction(SIGUSR2, &sig, NULL) == -1)
    {
		ft_printf("Error: Could not handle SIGUSR2.\n");
		exit(1);
	}
    while (1)
    {
        pause();
        if (!str)
        {
            str = ft_strdup("");  
            if (!str)
                return (1);
        }
        bit++;
        if (bit % 8 == 0)  
        {        
            str = reallocation(str, chr);
            if (!str)
                return (1);
            if (chr == '\0')
            {
                ft_printf("%s\n", str);
                free(str);
                str = NULL;
            }
            bit = 0;  
        }
    }
}
