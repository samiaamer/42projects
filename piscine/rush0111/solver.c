/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:39:16 by nagha             #+#    #+#             */
/*   Updated: 2024/06/21 11:39:20 by nagha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
extern int g_size;


int	satisfies_clues(char **board);
int	is_valid_position(char **board, int row, int column, int number);
int	solver(char **board);

int	solver_value(char **board, int row, int col, char value)
{
	if (row == -1 && col == -1)
		return (1);
	while (value <= '0' + g_size)
	{
		if (is_valid_position(board, row, col, value))
		{
			board[row][col] = value;
			if (solver(board) && satisfies_clues(board))
				return (1);
			else
				board[row][col] = '0';
		}
		value++;
	}
	return (0);
}
/*void	row_col_value(int *row, int *col, int i, int j)
{
	if (board[i][j] == '0')
	{
		*row = i;
		*col = j;
	}
}*/
int	solver(char **board)
{
	int		i;
	int		j;
	int		row;
	int		col;
	char	value;

	i = 0;
	j = 0;
	row = -1;
	col = -1;
	value = '1';
	while (i < g_size)
	{
		while (j < g_size)
		{
			if (board[i][j] == '0')
	{
		row = i;
		col = j;
		break ;
	}
			j++;
		}
		if (row != -1)
			break ;
		i++;
	}
	return(solver_value(board, row, col, value));
	
}
void	print_board(char **board)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < g_size)
	{
		while (j < g_size)
		{
			c = board[i][j] + 48;
			write(1, &c, 1);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}			
