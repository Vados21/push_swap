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

#include <stdlib.h>

void	*ft_free(char **res, size_t pos)
{
	while (pos != 0)
	{
		free(res[pos]);
		pos--;
	}
	free(res[pos]);
	free(res);
	return (NULL);
}

void	ft_word(char const *str, size_t *first, size_t *last, char c)
{
	*first = *last;
	while (str[*first] == c)
		*first = *first + 1;
	*last = *first;
	while (str[*last] != c && str[*last] != '\0')
		*last = *last + 1;
}

size_t	ft_count(char const *str, char c)
{
	size_t	count;
	size_t	first;
	size_t	last;

	count = 0;
	first = 0;
	last = 0;
	while (str[last] != '\0')
	{
		ft_word(str, &first, &last, c);
		if (last == first)
			break ;
		else
			count++;
	}
	return (count);
}

char	*ft_fill(char const *str, size_t first, size_t last)
{
	char	*word;
	size_t	pos;

	pos = 0;
	word = malloc(sizeof(char) * (last - first + 1));  // +1 для нулевого символа
	if (!word)
		return (NULL);
	while (first < last)
	{
		word[pos++] = str[first++];
	}
	word[pos] = '\0';  // Добавляем завершающий нулевой символ
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	size_t	first;
	size_t	last;
	size_t	pos;
	size_t	word_count;

	if (!str)
		return (NULL);

	word_count = ft_count(str, c);  // Вызываем ft_count один раз
	res = malloc(sizeof(char *) * (word_count + 1));  // +1 для NULL в конце
	if (!res)
		return (NULL);
	last = 0;
	first = 0;
	pos = 0;
	while (pos < word_count)
	{
		ft_word(str, &first, &last, c);
		if (last == first)
			break ;
		res[pos] = ft_fill(str, first, last);
		if (!res[pos])
			return (ft_free(res, pos));  // Освобождаем память в случае ошибки
		pos++;
	}
	res[pos] = NULL;  // Завершаем массив указателем NULL
	return (res);
}

