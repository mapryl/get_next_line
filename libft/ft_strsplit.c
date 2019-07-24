/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <mapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:47:04 by mapryl            #+#    #+#             */
/*   Updated: 2019/05/17 21:37:31 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_words(char const *str, char c)
{
	size_t word;

	word = 0;
	while (*str)
	{
		if (*str != c)
			word++;
		while (*str != c && *(str + 1))
			str++;
		str++;
	}
	return (word);
}

static size_t		ft_letter(char const **str, char c)
{
	size_t len;

	if (*str == '\0')
		return (0);
	len = 0;
	while (**str != '\0' && **str == c)
		(*str)++;
	while (**str != '\0' && **str != c)
	{
		(*str)++;
		len++;
	}
	return (len);
}

static void			ft_fresh_str(char ***str)
{
	while (**str != '\0')
	{
		free(**str);
		str++;
	}
	free(*str);
	*str = NULL;
}

char				**ft_strsplit(char const *str, char c)
{
	char		**array_str;
	size_t		i;
	size_t		count_word;
	size_t		len_word;

	if (!str)
		return (0);
	count_word = ft_words(str, c);
	if (!(array_str = (char**)malloc(sizeof(char*) * (count_word + 1))))
		return (0);
	i = 0;
	while (i < count_word)
	{
		len_word = ft_letter(&str, c);
		if (len_word == 0)
			return (0);
		if (!(array_str[i] = ft_strndup(str - len_word, len_word)))
		{
			ft_fresh_str(&array_str);
			return (0);
		}
		i++;
	}
	array_str[count_word] = NULL;
	return (array_str);
}
