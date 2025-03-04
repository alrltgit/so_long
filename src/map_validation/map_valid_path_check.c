/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:59:35 by apple             #+#    #+#             */
/*   Updated: 2025/03/04 10:25:45 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_the_path(t_mlx *mlx, t_state state, int x, int y)
{
	while ((x >= 1 && y >= 1) && (x < state.rows && y < state.cols))
	{
		if (state.grid[x][y] == '1')
		{
			ft_printf("Error: the map doesn't have a valid path.\n");
			mlx_destroy_display(mlx->mlx_ptr);
			free_map(&mlx->data);
			free(mlx);
			exit(1);
		}
		if (state.grid[x][y] == 'E')
			return (1);
		if (dfs(mlx, state, x - 1, y))
			return (1);
		if (dfs(mlx, state, x + 1, y))
			return (1);
		if (dfs(mlx, state, x, y - 1))
			return (1);
		if (dfs(mlx, state, x, y + 1))
			return (1);
		return (0);
	}
	return (1);
}

int	dfs(t_mlx *mlx, t_state state, int x, int y)
{
	if (x < 0 || y < 0 || x >= state.rows || y >= state.cols)
	{
		ft_printf("Error: the map doesn't have a valid path.\n");
		mlx_destroy_display(mlx->mlx_ptr);
		free_map(&mlx->data);
		free(mlx);
		return (0);
	}
	return (check_the_path(mlx, state, x, y));
}

char	**map_to_arr(t_mlx *mlx, t_map *head, t_state state)
{
	char	**grid;
	char	**temp;
	int		j;

	grid = malloc(sizeof(char *) * state.cols);
	if (!grid)
	{
		ft_printf("Grid is not allocated.\n");
		mlx_destroy_display(mlx->mlx_ptr);
		free_map(&mlx->data);
		free(mlx);
		return (NULL);
	}
	temp = grid;
	j = 0;
	while (head && j < state.cols)
	{
		temp[j] = ft_strdup(head->data);
		j++;
		head = head->next;
	}
	return (grid);
}

void	valid_path(t_mlx *mlx, t_state state)
{
	state.x = 0;
	state.y = 0;
	state.grid = map_to_arr(mlx, mlx->data, state);
	if (!state.grid)
	{
		ft_printf("Error: the map is empty.\n");
		mlx_destroy_display(mlx->mlx_ptr);
		free_map(&mlx->data);
		free(mlx);
		exit(1);
	}
	if (!find_coords(mlx, &state.x, &state.y, 'P'))
	{
		ft_printf("Player doesn't exist.\n");
		free_grid(state.grid, state.cols);
		mlx_destroy_display(mlx->mlx_ptr);
		free_map(&mlx->data);
		free(mlx);
	}
	dfs(mlx, state, state.x, state.y);
	free_grid(state.grid, state.cols);
}
