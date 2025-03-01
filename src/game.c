/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:06:25 by apple             #+#    #+#             */
/*   Updated: 2025/03/01 16:48:51 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_LEFT)
		move_left(mlx);
	else if (keycode == KEY_RIGHT)
		move_right(mlx);
	else if (keycode == KEY_UP)
		move_up(mlx);
	else if (keycode == KEY_DOWN)
		move_down(mlx);
	else if (keycode == KEY_ESC)
	{
		ft_printf("Closing the window...\n");
		clean_exit(mlx);
		exit(0);
	}
	display_img(mlx);
	return (0);
}

int	close_win(t_mlx *mlx, int i)
{
	i = 0;
	clean_exit(mlx);
	exit(0);
	return (i);
}

void	game(t_mlx *mlx)
{
	mlx->stars_count = 0;
	mlx->mv_num = 0;
	mlx_hook(mlx->win_ptr, 2, 1L << 0, handle_key, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_win, mlx);
}
