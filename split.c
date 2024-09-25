/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:41:47 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/13 12:41:51 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			res++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (res);
}

static int	get_word_len(const char *s, char c)
{
	int	res;

	res = 0;
	while (s[res] && s[res] != c)
		res++;
	return (res);
}

static void	*handle_malloc_fail(char **res, int i)
{
	while (--i >= 0)
		free(res[i]);
	free(res);
	return (NULL);
}

static void	copy_word(char **res, const char *str, int i, int word_len)
{
	res[i][word_len] = '\0';
	while (--word_len >= 0)
		res[i][word_len] = str[word_len];
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_count;
	int		i;
	int		word_len;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s && *s == c)
			s++;
		word_len = get_word_len(s, c);
		res[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!res[i])
			return (handle_malloc_fail(res, i));
		copy_word(res, s, i++, word_len);
		s += word_len;
	}
	res[word_count] = NULL;
	return (res);
}
