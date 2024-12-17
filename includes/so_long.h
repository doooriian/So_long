/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:42:46 by doley             #+#    #+#             */
/*   Updated: 2024/12/17 19:14:31 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include "./ft_printf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include "./mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_img
{
	char	*corner_bl;
	char	*corner_br;
	char	*corner_tl;
	char	*corner_tr;
	char	*dot;
	char	*exit;
	char	*floor;
	char	*line_h;
	char	*line_v;
	char	*pacman_down;
	char	*pacman_left;
	char	*pacman_right;
	char	*pacman_up;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	int		collectibles;
	int		character;
	int		exit;
	int		invalid_letter;
	char	**map;
	bool	**visited;
	int		x_start;
	int		y_start;
	bool	found_exit;
	int		vector_x;
	int		vector_y;
	int		xpm_height;
	int		xpm_width;
	int		moves;
	int		items;
	t_img	*img;
}	t_data;


/* FUNCTIONS */
bool	check_way_possible(t_data *data);
bool	is_exit_access(t_data *data);
void	mark_access(t_data *data, int x, int y, int *found_collec);
void	init_visited(t_data *data);
void	ft_error(int i);
int		error_malloc_map(void);
void	ft_free_error(int i, t_data *data);
bool	check_input(char *input);
bool	check_height(char *input, t_data *data);
bool	check_width(t_data *data);
bool	check_wall(t_data *data);
bool	check_letters(t_data *data);
void	cpy_map(char *input, t_data *data);
void	count_letters(t_data *data);
bool	check_map(char *input, t_data *data);
int		game_init(t_data *data);
void	init_map(t_data *data);
void	put_image(t_data *data, char c, int i, int j);
int		get_i(t_data *data, int dir);
int		get_j(t_data *data, int dir);
void	put_exit(t_data *data);
int		move_right(t_data *data);
int		move_left(t_data *data);
int		move_down(t_data *data);
int		move_up(t_data *data);
int		check_move(t_data *data, int dir);
void	put_perimeter(t_data *data, int i, int j);
void	put_walls(t_data *data, int i, int j);
int		ft_exit(t_data *data);
void	free_visited(t_data *data);
int		free_map(t_data *data);
int		main(int argc, char **argv);

#endif
