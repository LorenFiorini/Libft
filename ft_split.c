/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:50:16 by lfiorini          #+#    #+#             */
/*   Updated: 2022/11/13 13:56:12 by lfiorini         ###   ########.fr       */
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

static	void ft_copy_word(char *dst, char const *src, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[start + i];
		i++;
	}
	dst[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ans = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!ans)
		return (NULL);
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			k = ft_word_len(s, c, i);
			ans[j] = (char *)malloc(sizeof(char) * (k + 1));
			ft_copy_word(ans[j], s, i, k + 1);

		}
		/*if (!ans[j])
		{
			while (j--)
				free(ans[j]);
			free(ans);
			return (NULL);
		}
		while (s[i] != c && s[i] != '\0')
			ans[j][k++] = s[i++];
		if (k != 0)
			ans[j++][k] = '\0';*/
	}
	ans[j] = NULL;
	return (ans);
}
