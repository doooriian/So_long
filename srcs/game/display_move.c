/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:30:46 by doley             #+#    #+#             */
/*   Updated: 2024/12/18 15:32:11 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	nlen(int nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static char	*ft_itoa(int nbr)
{
	char	*cnum;
	int		len;
	int		i;

	len = nlen(nbr);
	i = 0;
	if (nbr < 0)
		i++;
	len = len + i;
	cnum = (char *)malloc((len + 1) * sizeof(char));
	if (!cnum)
		return (NULL);
	cnum[0] = '-';
	cnum[len] = '\0';
	while ((len - 1) >= i)
	{
		cnum[len - 1] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (cnum);
}

void	display_moves(t_data *data)
{
	char	*moves_str;

	moves_str = ft_itoa(data->moves);
	if (!moves_str)
		return ;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->floor, data->width * 32 / 2, data->height * 32);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		data->width * 32 / 2, data->height * 32 + 16, 0xFFFFFF, moves_str);
	free(moves_str);
}
