/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:10:02 by apple             #+#    #+#             */
/*   Updated: 2025/03/01 15:38:14 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_length(unsigned int val)
{
	int	count;

	if (val == 0)
		return (1);
	count = 0;
	while (val > 0)
	{
		val /= 16;
		count++;
	}
	return (count);
}

static char	*convert_to_hex(unsigned int val, char *hex_num, int *i)
{
	char	temp;
	int		idx;

	idx = *i;
	while (val != 0)
	{
		temp = val % 16;
		if (temp < 10)
			hex_num[idx] = temp + '0';
		else
			hex_num[idx] = temp - 10 + 'a';
		idx++;
		val /= 16;
	}
	hex_num[idx] = '\0';
	*i = idx;
	return (hex_num);
}

static char	*reverse_str(char *hex_num, int length)
{
	char	temp;
	int		j;
	int		end;

	j = 0;
	end = length - 1;
	while (j < end)
	{
		temp = hex_num[j];
		hex_num[j] = hex_num[end];
		hex_num[end] = temp;
		j++;
		end--;
	}
	return (hex_num);
}

int	ft_print_hex_lower(unsigned int val)
{
	int		i;
	char	*hex_num;
	int		str_size;
	int		length;

	length = find_length(val);
	hex_num = malloc(sizeof(char) * (length + 1));
	if (hex_num == NULL)
		return (0);
	i = 0;
	if (val == 0)
	{
		hex_num[0] = '0';
		hex_num[1] = '\0';
	}
	else
	{
		convert_to_hex(val, hex_num, &i);
		reverse_str(hex_num, i);
	}
	ft_print_str(hex_num);
	str_size = ft_strlen_pf(hex_num);
	free(hex_num);
	return (str_size);
}
