/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlysenko <mlysenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:17:09 by mlysenko          #+#    #+#             */
/*   Updated: 2023/12/04 00:36:25 by mlysenko         ###   ########.fr       */
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
