/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytro <dmytro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:20:18 by dstarov           #+#    #+#             */
/*   Updated: 2023/11/18 18:02:25 by dmytro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s || !s[i])
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	*addword(char const *s, char c)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	len = wordlen(s, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (len > 0)
	{
		word[i] = *s;
		i++;
		s++;
		len--;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word;

	if (!s)
		return (NULL);
	word = 0;
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			res[word++] = addword(s, c);
			s++;
		}
		while (*s && *s != c)
			s++;
	}
	res[word] = NULL;
	return (res);
}
