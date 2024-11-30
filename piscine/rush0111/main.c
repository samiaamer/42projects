/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malja-fa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:08:48 by malja-fa          #+#    #+#             */
/*   Updated: 2024/06/22 15:22:22 by malja-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include<stdlib.h>
int	solver(char **board);
void	print_board(char **board);
void fill_clues(char *argv[]);
int g_size;

int error_hand(int argc, char **argv)
{
    if (argc != 2)
    {
    write (1, "1Error\n", 6);
    return (0);
    }
    int i;
    i = 0;
    
    while (argv[1][i] != '\0')
    {
        if (argv [1][i] == '-')
        {
            write (1, "2Error\n", 6);
            return (0);
        }
        i++;
    }
    if(i != 31)
        {
            write (1, "3Error\n", 6);
            return (0);
        }
        return (1);
}



int main(int argc, char **argv)
{
g_size = 4;
    if(error_hand(argc,argv))
    {
    char **grid = (char **) malloc (g_size* 1); //to run through th indeces in the grid (make it 2D array)
    int i;
    i =0;
    while (i < g_size) 
    {
        grid[i++] = (char *) malloc (g_size  * 1);
        int j;
        j = 0;
        while (j < g_size)
            grid[i][j++] = '0'; // Initialize with zeros
    }
    fill_clues(argv);
    if (solver(grid))// Print the solved board
        print_board(grid);
    else
        write (1, "4Error\n", 6);
    i = 0;
    while (i < g_size)
        free(grid[i++]);
    free(grid);
    }
    return (0);
}

