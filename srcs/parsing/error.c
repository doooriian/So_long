/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:26:41 by doley             #+#    #+#             */
/*   Updated: 2024/12/18 17:03:21 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_error(t_data *data, int i)
{
	free(data->img);
	if (i == 1)
		ft_printf("Error\nCan't find the map\n");
	else if (i == 2)
		ft_printf("Error\nNot enough lines\n");
}

int	error_malloc_map(t_data *data)
{
	free(data->img);
	ft_printf("Error\n Malloc of the map didn't work\n");
	exit (0);
}

void	ft_free_error(int i, t_data *data)
{
	free_map(data);
	free(data->img);
	if (i == 3)
		ft_printf("Error\nEach lines must have the same length\n");
	else if (i == 4)
		ft_printf("Error\nMap must be closed by walls\n");
	else if (i == 5)
	{
		ft_printf("Error\nMap must contain :\n- one 'P' (player)\n");
		ft_printf("- one 'E' (exit)\n- at least one 'C' (collectibles)\n");
		ft_printf("- and several '0' and '1' for spaces and walls\n");
	}
	else if (i == 6)
		ft_printf("Error\nMap can't be finished, no way found\n");
	else if (i == 7)
		ft_printf("Error\nMap is too big\n");
}
