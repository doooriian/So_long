/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:55:51 by doley             #+#    #+#             */
/*   Updated: 2024/12/17 19:46:54 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (!data->map)
		return (0);
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	return (0);
}

void	free_visited(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->visited[i]);
		i++;
	}
	free(data->visited);
}

static void	free_images(t_data *data)
{
	if (data->img->corner_bl)
		mlx_destroy_image(data->mlx_ptr, data->img->corner_bl);
	if (data->img->corner_br)
		mlx_destroy_image(data->mlx_ptr, data->img->corner_br);
	if (data->img->corner_tl)
		mlx_destroy_image(data->mlx_ptr, data->img->corner_tl);
	if (data->img->corner_tr)
		mlx_destroy_image(data->mlx_ptr, data->img->corner_tr);
	if (data->img->dot)
		mlx_destroy_image(data->mlx_ptr, data->img->dot);
	if (data->img->exit)
		mlx_destroy_image(data->mlx_ptr, data->img->exit);
	if (data->img->floor)
		mlx_destroy_image(data->mlx_ptr, data->img->floor);
	if (data->img->line_h)
		mlx_destroy_image(data->mlx_ptr, data->img->line_h);
	if (data->img->line_v)
		mlx_destroy_image(data->mlx_ptr, data->img->line_v);
	if (data->img->pacman_down)
		mlx_destroy_image(data->mlx_ptr, data->img->pacman_down);
	if (data->img->pacman_left)
		mlx_destroy_image(data->mlx_ptr, data->img->pacman_left);
	if (data->img->pacman_right)
		mlx_destroy_image(data->mlx_ptr, data->img->pacman_right);
}

int	ft_exit(t_data *data)
{
	if (data->img)
	{
		free_images(data);
		if (data->img->pacman_up)
			mlx_destroy_image(data->mlx_ptr, data->img->pacman_up);
		free(data->img);
		data->img = NULL;
	}
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_map(data);
	exit (0);
}
