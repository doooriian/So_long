/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:24:43 by doley             #+#    #+#             */
/*   Updated: 2024/12/18 15:48:38 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	cpy_map(char *input, t_data *data)
{
	int	i;
	int	len;
	int	fd;

	len = 0;
	fd = open(input, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
	{
		close(fd);
		error_malloc_map();
	}
	i = 0;
	while (i <= data->height)
	{
		data->map[i] = get_next_line(fd);
		if (!data->map[i])
			break ;
		len = ft_strlen(data->map[i]);
		if (len > 0 && data->map[i][len - 1] == '\n')
			data->map[i][len - 1] = '\0';
		i++;
	}
	close(fd);
}

static bool	is_invalid(char c)
{
	return (c != '0' && c != '1' && c != 'X');
}

void	count_letters(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->collectibles++;
			else if (data->map[i][j] == 'P')
			{
				data->character++;
				data->x_start = j;
				data->y_start = i;
			}
			else if (data->map[i][j] == 'E')
				data->exit++;
			else if (is_invalid(data->map[i][j]))
				data->invalid_letter++;
			j++;
		}
		i++;
	}
}
