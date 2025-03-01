/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:07:55 by apple             #+#    #+#             */
/*   Updated: 2025/03/01 16:38:57 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	so_long(int argc, char *argv[])
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
	{
		ft_printf("mlx is NULL");
	}
	mlx->mlx_ptr = mlx_init();
	read_map(mlx, argc, argv);
	game(mlx);
	mlx_loop(mlx->mlx_ptr);
	clean_exit(mlx);
	ft_printf("TEST.\n");
}

int	main(int argc, char *argv[])
{
	so_long(argc, argv);
	ft_printf("TEST.\n");
	return (0);
}
