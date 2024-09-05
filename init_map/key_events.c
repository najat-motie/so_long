/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:37:58 by nmotie-           #+#    #+#             */
/*   Updated: 2024/09/05 22:42:53 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void	update_p_pos(t_data *data, int y_move, int x_move)
{
	int			y;
	int			x;
	int			status;
	static int	movements_num;

	y = data->p_pos.y;
	x = data->p_pos.x;
	status = 0;
	if (data->map[y + y_move][x + x_move] != '1')
	{
		if (data->map[y + y_move][x + x_move] == 'E')
		{
			if (!check_collectibles(data->map))
				return ;
			status = 1;
		}
		data->map[y][x] = '0';
		data->map[y + y_move][x + x_move] = 'P';
		ft_putnbr(++movements_num);
		write(1, "\n", 1);
		data->p_pos.y += y_move;
		data->p_pos.x += x_move;
		if (status == 1)
			exit_succes(data);
	}
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit_succes(data);
	if (keycode == LEFT)
	{
		update_p_pos(data, 0, -1);
		build_window(data);
	}
	if (keycode == RIGHT)
	{
		update_p_pos(data, 0, +1);
		build_window(data);
	}
	if (keycode == DOWN)
	{
		update_p_pos(data, +1, 0);
		build_window(data);
	}
	if (keycode == UP)
	{
		update_p_pos(data, -1, 0);
		build_window(data);
	}
	return (0);
}
