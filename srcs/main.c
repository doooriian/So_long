/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:34:28 by doley             #+#    #+#             */
/*   Updated: 2024/12/18 15:10:39 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	data_init(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->height = 0;
	data->width = 0;
	data->collectibles = 0;
	data->character = 0;
	data->exit = 0;
	data->invalid_letter = 0;
	data->map = NULL;
	data->visited = NULL;
	data->x_start = -1;
	data->y_start = -1;
	data->found_exit = 0;
	data->vector_x = 0;
	data->vector_y = 0;
	data->xpm_height = 32;
	data->xpm_width = 32;
	data->moves = 0;
	data->items = 0;
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		ft_exit(data);
}

static void	img_init(t_data *data)
{
	data->img->corner_bl = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/corner_BL.xpm", &data->xpm_width, &data->xpm_height);
	data->img->corner_br = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/corner_BR.xpm", &data->xpm_width, &data->xpm_height);
	data->img->corner_tl = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/corner_TL.xpm", &data->xpm_width, &data->xpm_height);
	data->img->corner_tr = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/corner_TR.xpm", &data->xpm_width, &data->xpm_height);
	data->img->dot = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/dot.xpm", &data->xpm_width, &data->xpm_height);
	data->img->floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/floor.xpm", &data->xpm_width, &data->xpm_height);
	data->img->line_h = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/line_H.xpm", &data->xpm_width, &data->xpm_height);
	data->img->line_v = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/line_V.xpm", &data->xpm_width, &data->xpm_height);
	data->img->pacman_down = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/pacman_down.xpm", &data->xpm_width, &data->xpm_height);
	data->img->pacman_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/pacman_left.xpm", &data->xpm_width, &data->xpm_height);
	data->img->pacman_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/pacman_right.xpm", &data->xpm_width, &data->xpm_height);
	data->img->pacman_up = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/pacman_up.xpm", &data->xpm_width, &data->xpm_height);
}

static void	check_img(t_data *data)
{
	data->img->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/exit.xpm", &data->xpm_width, &data->xpm_height);
	data->img->ball = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/pacman_ball.xpm", &data->xpm_width, &data->xpm_height);
	data->img->enemy = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/enemy.xpm", &data->xpm_width, &data->xpm_height);
	if (!data->img->corner_bl || !data->img->corner_br || !data->img->corner_bl
		|| !data->img->corner_tl || !data->img->corner_tr || !data->img->dot
		|| !data->img->floor || !data->img->line_h || !data->img->line_v
		|| !data->img->pacman_down || !data->img->pacman_left
		|| !data->img->pacman_right || !data->img->pacman_up
		|| !data->img->exit)
		ft_exit(data);
}

static int	on_keypress(int keycode, void *data)
{
	if (keycode == 65307)
		return (ft_exit(data));
	else if (keycode == 119 || keycode == 65362)
		return (move_up(data));
	else if (keycode == 115 || keycode == 65364)
		return (move_down(data));
	else if (keycode == 97 || keycode == 65361)
		return (move_left(data));
	else if (keycode == 100 || keycode == 65363)
		return (move_right(data));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\nIncorrect number of arguments! It must be 2!\n");
		return (0);
	}
	data_init(&data);
	if (argc == 2 && check_map(argv[1], &data))
	{
		game_init(&data);
		img_init(&data);
		check_img(&data);
		init_map(&data);
		mlx_hook(data.win_ptr, 2, 1, &on_keypress, &data);
		mlx_hook(data.win_ptr, 17, 0, &ft_exit, &data);
		mlx_loop(data.mlx_ptr);
	}
}
