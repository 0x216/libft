/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlysenko <mlysenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:15:48 by ant               #+#    #+#             */
/*   Updated: 2023/12/04 01:13:50 by mlysenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
		else
		{
			while (s[i] && s[i] == c)
			{
				i++;
			}
		}
	}
	return (count);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

static char	**free_array(char **array, size_t word_count)
{
	size_t	i;

	i = 0;
	while (i < word_count)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char	**split(char const *s, char c, size_t word_count)
{
	char	**array;
	size_t	i;
	size_t	j;
	size_t	word_len;

	array = malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_count)
	{
		while (s[j] && s[j] == c)
			j++;
		word_len = get_word_len(&s[j], c);
		array[i] = ft_substr(s, j, word_len);
		if (!array[i])
			return (free_array(array, i));
		j += word_len;
		i++;
	}
	array[word_count] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	return (split(s, c, word_count));
}
