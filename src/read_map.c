/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:38:47 by alraltse          #+#    #+#             */
/*   Updated: 2025/03/01 17:10:20 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_img(t_mlx *mlx)
{
	t_map	*temp;

	temp = mlx->data;
	mlx->pos_y = 0;
	while (temp != NULL)
	{
		mlx->pos_x = 0;
		while (temp->data[mlx->pos_x] != '\0')
		{
			parse_map(mlx, temp);
			mlx->pos_x++;
		}
		mlx->pos_y++;
		temp = temp->next;
	}
}

void	read_map(t_mlx *mlx, int argc, char *argv[])
{
	char	*read_line;
	int		fd;
	t_map	*head;
	t_state	state;

	map_exists(mlx, argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
	head = NULL;
	state.cols = 0;
	read_line = get_next_line(fd);
	while (read_line)
	{
		add_to_end_node(&head, read_line);
		state.rows = count_width_of_map(read_line);
		state.cols++;
		free(read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
	mlx->data = head;
	check_map(mlx, state);
}
