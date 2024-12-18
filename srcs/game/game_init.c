/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 02:10:50 by doley             #+#    #+#             */
/*   Updated: 2024/12/18 14:03:28 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_image(t_data *data, char c, int i, int j)
{
	if (c == '1')
		put_walls(data, i, j);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, j * 32, i * 32);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->dot, j * 32, i * 32);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->pacman_right, j * 32, i * 32);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, j * 32, i * 32);
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
			put_image(data, data->map[i][j], i, j);
			j++;
		}
		i++;
	}
}

int	game_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * 32,
			(data->height + 1) * 32, "so_long");
	data->vector_x = data->x_start * 32;
	data->vector_y = data->y_start * 32;
	return (1);
}
