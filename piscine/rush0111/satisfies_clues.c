/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:47:33 by nagha             #+#    #+#             */
/*   Updated: 2024/06/21 10:47:41 by nagha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#define g_size 4
extern const int g_size;
char top_clues[4];
char bottom_clues[4];
char right_clues[4];
char left_clues[4];


void fill_clues(char *str)
{
int i;
i = 0;
	while (i <g_size)
	{
		top_clues[i] = str[i*2];
		bottom_clues[i] = str[8 + (i * 2)];
		right_clues[i] = str[16 + (i * 2)];
		left_clues[i] = str[24 + (i * 2)];
		i++;
	}
}



int	topclues(char **board)

{
	int		i;
	int		j;
	char	max_height;
	char	visible_count;

	i = 0;
	j = 0;
	max_height = '0';
	visible_count = '0';
	while (i < g_size)
	{
		while (j < g_size)
		{
			if (board[j][i] > max_height)
			{
				max_height = board[j][i];
				visible_count++;
			}
			j++;
		}
		if (visible_count != top_clues[i] && top_clues[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	bottomclues(char **board)

{
	int		i;
	int		j;
	char	max_height;
	char	visible_count;

	i = 0;
	j = 3;
	max_height = '0';
	visible_count = '0';
	while (i < g_size)
	{
		while (j >= 0)
		{
			if (board[j][i] > max_height)
			{
				max_height = board[j][i];
				visible_count++;
			}
			j--;
		}
		if (visible_count != bottom_clues[i] && bottom_clues[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	rightclues(char **board)

{
	int		i;
	int		j;
	char	max_height;
	char	visible_count;

	i = 0;
	j = 3;
	max_height = '0';
	visible_count = '0';
	while (i < g_size)
	{
		while (j >= 0)
		{
			if (board[i][j] > max_height)
			{
				max_height = board[j][i];
				visible_count++;
			}
			j++;
		}
		if (visible_count != right_clues[i] && right_clues[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	leftclues(char **board)

{
	int		i;
	int		j;
	char	max_height;
	char	visible_count;

	i = 0;
	j = 0;
	max_height = '0';
	visible_count = '0';
	while (i < g_size)
	{
		while (j < g_size)
		{
			if (board[i][j] > max_height)
			{
				max_height = board[j][i];
				visible_count++;
			}
			j++;
		}
		if (visible_count != left_clues[i] && left_clues[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	satisfies_clues(char **board)

{
	if ((topclues(board) && bottomclues(board)) && ( rightclues(board) && leftclues(board)))
	{
		return (1);
	}
	return (0);
}
