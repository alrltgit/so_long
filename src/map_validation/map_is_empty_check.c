/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_empty_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:04:52 by apple             #+#    #+#             */
/*   Updated: 2025/03/01 17:38:48 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_is_empty(t_mlx *mlx)
{
	if (mlx->data == NULL)
	{
		ft_printf("Error: the map is empty.\n");
		mlx_destroy_display(mlx->mlx_ptr);
		free_map(&mlx->data);
		free(mlx);
		exit(1);
	}
}
