/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:05:52 by apple             #+#    #+#             */
/*   Updated: 2025/03/01 17:36:50 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_char(t_mlx *mlx, t_map *temp, int i)
{
	if (temp->data[i] == 'E')
		mlx->exit_num++;
	else if (temp->data[i] == 'C')
		mlx->coll_num++;
	else if (temp->data[i] == 'P')
		mlx->player_num++;
}

void	count_maps_chars(t_mlx *mlx)
{
	t_map	*temp;
	int		i;

	mlx->exit_num = 0;
	mlx->coll_num = 0;
	mlx->player_num = 0;
	temp = mlx->data;
	while (temp != NULL)
	{
		i = 0;
		while (temp->data[i] != '\0')
		{
			check_char(mlx, temp, i);
			i++;
		}
		temp = temp->next;
	}
	if (mlx->exit_num != 1 || mlx->player_num != 1 || mlx->coll_num < 1)
	{
		ft_printf("Error: the map is not valid.\n");
		mlx_destroy_display(mlx->mlx_ptr);
		free_map(&mlx->data);
		free(mlx);
		exit(1);
	}
}

void	check_compose(t_mlx *mlx)
{
	t_map	*temp;
	int		i;

	temp = mlx->data;
	while (temp != NULL)
	{
		i = 0;
		while (temp->data[i] != '\0')
		{
			if (temp->data[i] != '1' && temp->data[i] != '0'
				&& temp->data[i] != 'C' && temp->data[i] != 'P'
				&& temp->data[i] != 'E' && temp->data[i] != '\n')
			{
				ft_printf("Error: the map is not valid.\n");
				mlx_destroy_display(mlx->mlx_ptr);
				free_map(&mlx->data);
				free(mlx);
				exit(1);
			}
			i++;
		}
		temp = temp->next;
	}
}
