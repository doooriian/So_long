/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:43:39 by doley             #+#    #+#             */
/*   Updated: 2024/12/17 19:04:59 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	put_top(t_data *data, int i, int j)
{
	if (j == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_br, j * 32, i * 32);
	else if (j == (data->width - 1))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_bl, j * 32, i * 32);
	else if (data->map[i + 1][j - 1] == '1' && data->map[i + 1][j] == '1'
		&& data->map[i + 1][j + 1] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, j * 32, i * 32);
	else if (data->map[i + 1][j] == '1' && data->map[i + 1][j - 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_bl, j * 32, i * 32);
	else if (data->map[i + 1][j] == '1' && data->map[i + 1][j + 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_br, j * 32, i * 32);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->line_h, j * 32, i * 32);
}

static void	put_bottom(t_data *data, int i, int j)
{
	if (j == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tr, j * 32, i * 32);
	else if (j == (data->width - 1))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tl, j * 32, i * 32);
	else if (data->map[i - 1][j - 1] == '1' && data->map[i - 1][j] == '1'
		&& data->map[i - 1][j + 1] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, j * 32, i * 32);
	else if (data->map[i - 1][j] == '1' && data->map[i - 1][j - 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tl, j * 32, i * 32);
	else if (data->map[i - 1][j] == '1' && data->map[i - 1][j + 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tr, j * 32, i * 32);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->line_h, j * 32, i * 32);
}

static void	put_left(t_data *data, int i, int j)
{
	if (data->map[i - 1][j + 1] == '1' && data->map[i][j + 1] == '1'
		&& data->map[i + 1][j + 1] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, j * 32, i * 32);
	else if (data->map[i][j + 1] == '1' && data->map[i - 1][j + 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tr, j * 32, i * 32);
	else if (data->map[i][j + 1] == '1' && data->map[i + 1][j + 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_br, j * 32, i * 32);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->line_v, j * 32, i * 32);
}

static void	put_right(t_data *data, int i, int j)
{
	if (data->map[i - 1][j - 1] == '1' && data->map[i][j - 1] == '1'
		&& data->map[i + 1][j - 1] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, j * 32, i * 32);
	else if (data->map[i][j - 1] == '1' && data->map[i - 1][j - 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_tl, j * 32, i * 32);
	else if (data->map[i][j - 1] == '1' && data->map[i + 1][j - 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->corner_bl, j * 32, i * 32);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->line_v, j * 32, i * 32);
}

void	put_perimeter(t_data *data, int i, int j)
{
	if (i == 0)
		put_top(data, i, j);
	else if (i == (data->height - 1))
		put_bottom(data, i, j);
	else if (j == 0)
		put_left(data, i, j);
	else if (j == (data->width - 1))
		put_right(data, i, j);
}
