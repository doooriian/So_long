/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:12:11 by doley             #+#    #+#             */
/*   Updated: 2024/12/17 01:16:05 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	check_input(char *input)
{
	int	i;
	int	fd;

	i = ft_strlen(input);
	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (0);
	close (fd);
	if (input[--i] != 'r')
		return (0);
	if (input[--i] != 'e')
		return (0);
	if (input[--i] != 'b')
		return (0);
	if (input[--i] != '.')
		return (0);
	return (1);
}

bool	check_height(char *input, t_data *data)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		data->height++;
	}
	close(fd);
	if (data->height < 3)
		return (0);
	return (1);
}

bool	check_width(t_data *data)
{
	int	i;
	int	prev_width;

	i = 0;
	prev_width = 0;
	while (data->map[i])
	{
		data->width = ft_strlen(data->map[i]);
		if (prev_width != data->width && i != 0)
			return (0);
		prev_width = data->width;
		i++;
	}
	return (1);
}

bool	check_wall(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (data->map[0][j])
	{
		if (data->map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (data->map[data->height - 1][j])
	{
		if (data->map[data->height - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < data->height - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

bool	check_letters(t_data *data)
{
	count_letters(data);
	if (data->collectibles < 1 || data->character != 1 || data->exit != 1
		|| data->invalid_letter > 0)
		return (0);
	else
		return (1);
}