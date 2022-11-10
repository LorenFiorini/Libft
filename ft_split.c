/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:50:16 by lfiorini          #+#    #+#             */
/*   Updated: 2022/11/04 16:00:15 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (count);
}

static	int	ft_word_len(char const *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start + i] && s[start + i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	ans = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!ans || !s)
		return (NULL);
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			ans[j] = (char *)malloc(sizeof(char) * (ft_word_len(s, c, i) + 1));
		while (s[i] != c && s[i] != '\0')
			ans[j][k++] = s[i++];
		if (k != 0)
			ans[j++][k] = '\0';
	}
	ans[j] = NULL;
	return (ans);
}
