/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:14:25 by apple             #+#    #+#             */
/*   Updated: 2025/02/27 14:16:43 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_map	*create_node(char *read_line)
{
	t_map	*new_node;

	new_node = (t_map *)malloc(sizeof(t_map));
	if (!new_node)
	{
		ft_printf("Memory allocation failed!");
		return (NULL);
	}
	new_node->data = ft_strdup(read_line);
	new_node->next = NULL;
	return (new_node);
}

void	add_to_end_node(t_map **head, char *read_line)
{
	t_map	*new_node;
	t_map	*temp;

	new_node = create_node(read_line);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}
