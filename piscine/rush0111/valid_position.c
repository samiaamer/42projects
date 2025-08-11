/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numberInColumn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:19:04 by nagha             #+#    #+#             */
/*   Updated: 2024/06/21 10:19:23 by nagha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	g_size;

int	is_valid_position(char **board, int row, int column, int number)

{
	int	i;

	i = 0;
	while (i < g_size)
	{
		if (board[i][column] == number || board[row][i] == number)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

