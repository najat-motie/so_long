/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:38:50 by nmotie-           #+#    #+#             */
/*   Updated: 2024/09/05 22:25:10 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_letters_of_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_walls(int column, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i] != '\0' && map[0][i] != '\n')
	{
		if (map[0][i] != '1' || map[column - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	j = 0;
	j = line_length(map[j]) - 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_player(t_data *my_data)
{
	int	i;
	int	j;
	int	len_p;

	i = 0;
	j = 0;
	len_p = 0;
	while (my_data->map[i])
	{
		j = 0;
		while (my_data->map[i][j])
		{
			if (my_data->map[i][j] == 'P')
			{
				len_p++;
				my_data->p_pos.y = i;
				my_data->p_pos.x = j;
			}
			j++;
		}
		i++;
	}
	if (len_p == 0 || len_p > 1)
		return (1);
	return (0);
}

int	check_collectibles(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_exit(char **map)
{
	int	i;
	int	j;
	int	len_e;

	i = 0;
	j = 0;
	len_e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				len_e++;
			j++;
		}
		i++;
	}
	if (len_e == 0 || len_e > 1)
		return (1);
	else
		return (0);
}
