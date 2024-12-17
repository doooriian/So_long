/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 02:11:23 by doley             #+#    #+#             */
/*   Updated: 2024/12/17 15:28:32 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_move(t_data *data, int dir)
{
	int	i;
	int	j;

	i = get_i(data, dir);
	j = get_j(data, dir);
	if (data->map[i][j] == '1')
		return (1);
	else if (data->map[i][j] == 'C')
	{
		data->items++;
		data->map[i][j] = '0';
		return (0);
	}
	else if (data->map[i][j] == 'E')
	{
		if (data->items == data->collectibles)
			ft_exit(data);
		return (0);
	}
	else
		return (0);
}

int	move_up(t_data *data)
{
	if (check_move(data, 1))
		return (0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->floor, data->vector_x, data->vector_y);
	data->vector_y -= 32;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->pacman_up, data->vector_x, data->vector_y);
	data->moves++;
	put_exit(data);
	printf("You've done %d moves.\n", data->moves);
	return (1);
}

int	move_down(t_data *data)
{
	if (check_move(data, 2))
		return (0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor,
		data->vector_x, data->vector_y);
	data->vector_y += 32;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->pacman_down, data->vector_x, data->vector_y);
	data->moves++;
	put_exit(data);
	printf("You've done %d moves.\n", data->moves);
	return (1);
}

int	move_left(t_data *data)
{
	if (check_move(data, 3))
		return (0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->floor, data->vector_x, data->vector_y);
	data->vector_x -= 32;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->pacman_left, data->vector_x, data->vector_y);
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->moves++;
	put_exit(data);
	printf("You've done %d moves.\n", data->moves);
	return (1);
}

int	move_right(t_data *data)
{
	if (check_move(data, 4))
		return (0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->floor, data->vector_x, data->vector_y);
	data->vector_x += 32;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->pacman_right, data->vector_x, data->vector_y);
	data->moves++;
	put_exit(data);
	printf("You've done %d moves.\n", data->moves);
	return (1);
}
