/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:23:59 by doley             #+#    #+#             */
/*   Updated: 2024/12/16 17:57:01 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	check_map(char *input, t_data *data)
{
	if (!check_input(input))
		return (ft_error(1), 0);
	if (!check_height(input, data))
		return (ft_error(2), 0);
	cpy_map(input, data);
	if (!check_width(data))
		return (ft_free_error(3, data), 0);
	if (data->height > data->width)
		return (ft_free_error(4, data), 0);
	if (!check_wall(data))
		return (ft_free_error(5, data), 0);
	if (!check_letters(data))
		return (ft_free_error(6, data), 0);
	if (!check_way_possible(data))
		return (ft_free_error(7, data), 0);
	if (data->height > 21 || data->width > 40)
		return (ft_free_error(8, data), 0);
	return (1);
}
