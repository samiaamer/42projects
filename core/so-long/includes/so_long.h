/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samia <samia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:11:41 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/25 23:54:51 by samia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 48
# define WIDTH 48

typedef struct s_map
{
	char	**grid;
	char	**o_grid;
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	void	*floor;
	void	*wall;
	void	*player;
	void	*up;
	void	*right;
	void	*left;
	void	*collect;
	void	*exit_open;
	char	*itoa_ptr;
	char	dir;
	size_t	line_count;
	size_t	line_len;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		move_count;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		flood_collect;
	int		exit_flag;
}			t_map;

void		free_map_sl(char **map, int line_count);
void		destroy_img(t_map *game);
int			free_all(t_map *game, int flag, char *message);
void		block_img(t_map *game, size_t i, size_t j);
void		copy_grid(t_map *game);
void		init_values(t_map *game);
void		flood_fill(t_map *game, int x, int y);
void		find_player_pos(t_map *game);
void		init_values2(t_map *game);
int			check_line_boundaries(char *line, t_map *game);
int			check_first_last_lines(char *line, t_map *game);
int			check_map_boundaries(t_map *map);
int			is_valid_char(char c);
int			check_line_chars(char *line, t_map *game);
int			validate_map_char(t_map *map);
int			count_plyers(t_map *map);
int			count_exits(t_map *map);
int			count_collect(t_map *map);
int			check_rectangle_map(t_map *map);
int			read_map_file(t_map *map, char *map_name);
int			count_lines(int fd, t_map *map);
int			add_line_to_map(t_map *map, int fd);
int			validate_map(t_map *map);
int			check_player_exit_collect(t_map *map);
int			parse_map(t_map *game, char *map_name);
int			init_mlx(t_map *game);
int			img_init(t_map *game);
int			put_img(t_map *game);
int			key_hook(int keycode, t_map *game);
int			player_img(t_map *game, int i, int j);
int			img_handle(t_map *game);

#endif
