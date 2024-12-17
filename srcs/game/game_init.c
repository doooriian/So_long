/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 02:10:50 by doley             #+#    #+#             */
/*   Updated: 2024/12/17 02:20:15 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_image(t_data *data, char c, int i, int j)
{
	if (c == '1')
		put_walls(data, i , j);
	else if (c == '0')
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, "xpm/floor.xpm",
				&data->xpm_width, &data->xpm_height);
	else if (c == 'C')
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, "xpm/ball.xpm",
				&data->xpm_width, &data->xpm_height);
	else if (c == 'P')
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, data->player,
				&data->xpm_width, &data->xpm_height);
	else if (c == 'E')
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, "xpm/floor.xpm",
				&data->xpm_width, &data->xpm_height);
	if (!data->img)
		ft_exit(data);
}

void	init_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0')
			{	
				get_image(data, '0', i, j);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img,
					j * 32, i * 32);
				mlx_destroy_image(data->mlx_ptr, data->img);
			}
			get_image(data, data->map[i][j], i, j);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img,
				j * 32, i * 32);
			mlx_destroy_image(data->mlx_ptr, data->img);
			j++;
		}
		i++;
	}
}

int	game_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * 32,
			data->height * 32, "so_long");
	data->vector_x = data->x_start * 32;
	data->vector_y = data->y_start * 32;
	init_map(data);
	return (1);
}
