/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 02:13:30 by doley             #+#    #+#             */
/*   Updated: 2024/12/17 03:07:59 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


void	put_walls(t_data *data, int i, int j)
{
	if (i == 1 || i == (data->height - 1))
	
	if (data->map[i][j - 1] == '1' && data->map[i][j + 1] == '1'
		&& data->map[i - 1][j] == '1' && data->map[i + 1][j] == '1')
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, "xpm/floor.xpm",
				&data->xpm_width, &data->xpm_height);
	
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, "xpm/wall.xpm",
				&data->xpm_width, &data->xpm_height);
}