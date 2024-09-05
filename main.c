/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:39:12 by nmotie-           #+#    #+#             */
/*   Updated: 2024/09/06 00:07:28 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	luanch_game(t_data *data, int line, int column)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, line * 50, column * 50, "so_long");
	extract_images(data);
	build_window(data);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 17, 0, exit_succes, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		line;
	int		column;

	if (ac == 2)
	{
		check_args(av[1]);
		data.map = read_map(av[1]);
		column = 0;
		line = line_length(data.map[0]);
		while (data.map[column])
			column++;
		if (line > 52 || column > 26)
		{
			double_free(data.map);
			write(1, "The Size Of Window Is Greater Than Screen!\n", 43);
			exit(1);
		}
		check_errors(column, &data);
		luanch_game(&data, line, column);
	}
	else
		write(1, "Invalid Arguments!\n", 19);
	return (0);
}
