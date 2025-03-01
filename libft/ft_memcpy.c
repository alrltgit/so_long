/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:19:54 by alraltse          #+#    #+#             */
/*   Updated: 2024/12/21 11:26:48 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	if (!dest && !src)
		return (NULL);
	ptr1 = dest;
	ptr2 = src;
	while (n > 0)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
		n--;
	}
	return (dest);
}
