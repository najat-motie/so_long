/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:38:55 by nmotie-           #+#    #+#             */
/*   Updated: 2024/09/05 20:20:57 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	line_length(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	check_empty(char **map)
{
	if (map[0] == NULL)
		return (1);
	else
		return (0);
}

int	check_rectangular(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1] != NULL)
	{
		if (line_length(map[i]) != line_length(map[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

void	check_errors(int column, t_data *data)
{
	if (check_empty(data->map) || check_rectangular(data->map)
		|| check_letters_of_map(data->map) || check_player(data)
		|| check_collectibles(data->map) || check_exit(data->map)
		|| check_walls(column, data->map) || check_path(data->map))
	{
		double_free(data->map);
		write(2, "Error!\n", 7);
		exit(1);
	}
}
