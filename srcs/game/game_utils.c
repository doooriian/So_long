/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 02:11:15 by doley             #+#    #+#             */
/*   Updated: 2024/12/17 02:12:41 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_exit(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	if (data->items == data->collectibles)
	{
		while (data->map[++i])
		{
			j = 0;
			while (data->map[i][j])
			{
				if (data->map[i][j] == 'E')
				{
					data->img = mlx_xpm_file_to_image(data->mlx_ptr, \
"xpm/hoop.xpm", &data->xpm_width, &data->xpm_height);
					if (!data->img)
						ft_exit(data);
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img, j * 32, i * 32);
					mlx_destroy_image(data->mlx_ptr, data->img);
				}
				j++;
			}
		}
	}
}

int	get_j(t_data *data, int dir)
{
	int	j;

	if (dir == 3)
		j = (data->vector_x - 32) / 32;
	else if (dir == 4)
		j = (data->vector_x + 32) / 32;
	else
		j = data->vector_x / 32;
	return (j);
}

int	get_i(t_data *data, int dir)
{
	int	i;

	if (dir == 1)
		i = (data->vector_y - 32) / 32;
	else if (dir == 2)
		i = (data->vector_y + 32) / 32;
	else
		i = data->vector_y / 32;
	return (i);
}