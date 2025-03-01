/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_form_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:38:55 by apple             #+#    #+#             */
/*   Updated: 2025/03/01 17:35:05 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	display_error(t_mlx *mlx, int row_count, int width)
{
	if (row_count != width)
	{
		ft_printf("Error: the map is not rectangular.\n");
		mlx_destroy_display(mlx->mlx_ptr);
		free_map(&mlx->data);
		free(mlx);
		exit(1);
	}
}

void	map_form_check(t_mlx *mlx)
{
	t_map	*temp;
	int		row_count;
	int		width;

	temp = mlx->data;
	width = 0;
	while (temp->data[width] != '\0' && temp->data[width] != '\n')
		width++;
	while (temp != NULL)
	{
		row_count = 0;
		while (temp->data[row_count] != '\0' && temp->data[row_count] != '\n')
			row_count++;
		display_error(mlx, row_count, width);
		temp = temp->next;
	}
}
