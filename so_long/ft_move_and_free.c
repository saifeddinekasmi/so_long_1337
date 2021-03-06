/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:09:17 by skasmi            #+#    #+#             */
/*   Updated: 2022/04/23 21:14:19 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_map *t)
{
	int	i;

	i = 0;
	while (t->str[i])
	{
		free(t->str[i]);
		i++;
	}
	free(t->str);
}

int	ft_close(t_map *t)
{
	ft_free(t);
	exit(0);
	return (0);
}

int	ft_close_with_message(t_map *t)
{
	ft_free(t);
	ft_printf("=== GAME END ===\n");
	exit(0);
	return (0);
}

int	ft_move(int keycode, t_map *t)
{
	if (keycode == 53)
		ft_close_with_message(t);
	else if (keycode == 13 || keycode == 126)
		ft_move_up(t);
	else if (keycode == 1 || keycode == 125)
		ft_move_down(t);
	else if (keycode == 0 || keycode == 123)
		ft_move_left(t);
	else if (keycode == 2 || keycode == 124)
		ft_move_right(t);
	draw_map(t);
	return (0);
}
