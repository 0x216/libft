/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlysenko <mlysenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:59:06 by mlysenko          #+#    #+#             */
/*   Updated: 2023/12/05 10:02:53 by mlysenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	if ((nitems * size) < nitems || (nitems * size) < size)
		return (NULL);
	ptr = malloc(size * nitems);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, size * nitems);
	return (ptr);
}
