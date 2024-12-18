/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 02:13:30 by doley             #+#    #+#             */
/*   Updated: 2024/12/18 16:31:28 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	put_corners_two(t_data *data, int i, int j)
{
	if (data->map[i][j - 1] == '1' && data->map[i][j + 1] == '1'
		&& data->map[i - 1][j] == '1' && data->map[i - 1][j - 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tl, j * 32, i * 32);
	else if (data->map[i][j - 1] == '1' && data->map[i][j + 1] == '1'
		&& data->map[i + 1][j] == '1' && data->map[i + 1][j + 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_br, j * 32, i * 32);
	else if (data->map[i][j - 1] == '1' && data->map[i][j + 1] == '1'
		&& data->map[i - 1][j] == '1' && data->map[i + 1][j - 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_bl, j * 32, i * 32);
	else if (data->map[i][j + 1] == '1' && data->map[i - 1][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tr, j * 32, i * 32);
	else if (data->map[i][j - 1] == '1' && data->map[i - 1][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tl, j * 32, i * 32);
	else if (data->map[i][j - 1] == '1' && data->map[i + 1][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_bl, j * 32, i * 32);
	else if (data->map[i][j + 1] == '1' && data->map[i + 1][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_br, j * 32, i * 32);
}

static void	put_corners(t_data *data, int i, int j)
{
	if (data->map[i][j + 1] == '1' && data->map[i + 1][j] == '1'
		&& data->map[i - 1][j] == '1' && data->map[i + 1][j + 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_br, j * 32, i * 32);
	else if (data->map[i][j - 1] == '1' && data->map[i + 1][j] == '1'
		&& data->map[i - 1][j] == '1' && data->map[i - 1][j - 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tl, j * 32, i * 32);
	else if (data->map[i][j - 1] == '1' && data->map[i + 1][j] == '1'
		&& data->map[i - 1][j] == '1' && data->map[i + 1][j - 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_bl, j * 32, i * 32);
	else if (data->map[i][j - 1] == '1' && data->map[i][j + 1] == '1'
		&& data->map[i - 1][j] == '1' && data->map[i - 1][j + 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tr, j * 32, i * 32);
	else if (data->map[i][j - 1] == '1' && data->map[i][j + 1] == '1'
		&& data->map[i - 1][j] == '1' && data->map[i - 1][j - 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tl, j * 32, i * 32);
	else
		put_corners_two(data, i, j);
}

static bool	put_lines(t_data *data, int i, int j)
{
	if ((data->map[i][j + 1] == '1' || data->map[i][j - 1] == '1')
		&& data->map[i - 1][j] != '1' && data->map[i + 1][j] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->line_h, j * 32, i * 32);
		return (1);
	}
	else if ((data->map[i - 1][j] == '1' || data->map[i + 1][j] == '1')
		&& data->map[i][j - 1] != '1' && data->map[i][j + 1] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->line_v, j * 32, i * 32);
		return (1);
	}
	else if ((data->map[i - 1][j] != '1' || data->map[i + 1][j] != '1')
		&& data->map[i][j - 1] != '1' && data->map[i][j + 1] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->line_v, j * 32, i * 32);
		return (1);
	}
	else
		return (0);
}

void	put_walls(t_data *data, int i, int j)
{
	if (i == 0 || i == (data->height - 1) || j == 0 || j == (data->width - 1))
		put_perimeter(data, i, j);
	else if (data->map[i][j - 1] == '1' && data->map[i][j + 1] == '1'
		&& data->map[i - 1][j] == '1' && data->map[i + 1][j] == '1'
		&& data->map[i - 1][j - 1] == '1' && data->map[i - 1][j + 1] == '1'
		&& data->map[i + 1][j - 1] == '1' && data->map[i + 1][j + 1] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, j * 32, i * 32);
	else if (put_lines(data, i, j))
		return ;
	else if ((data->map[i][j + 1] == '1' && data->map[i][j - 1] == '1')
		&& (data->map[i - 1][j] != '1' || data->map[i + 1][j] != '1'))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->line_h, j * 32, i * 32);
	else if ((data->map[i - 1][j] == '1' && data->map[i + 1][j] == '1')
		&& (data->map[i][j + 1] != '1' || data->map[i][j - 1] != '1'))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->line_v, j * 32, i * 32);
	else if (data->map[i][j + 1] == '1' && data->map[i + 1][j] == '1'
		&& data->map[i - 1][j] == '1' && data->map[i - 1][j + 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tr, j * 32, i * 32);
	else
		put_corners(data, i, j);
}
