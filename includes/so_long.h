/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:42:46 by doley             #+#    #+#             */
/*   Updated: 2024/12/15 18:44:52 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
// # include "./ft_printf/ft_printf.h"
// # include "./gnl/get_next_line.h"
// # include "./mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

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
	void	*img;
	int		xpm_height;
	int		xpm_width;
	int		moves;
	int		items;
	char	*player;
}	t_data;

#endif
