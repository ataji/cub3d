/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnewline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:26:16 by ataji             #+#    #+#             */
/*   Updated: 2023/01/10 15:10:35 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

char	**set_wordsnewline(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	tab = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j != 0)
			tab[k++] = ft_substr(s, i, j);
		if (j != 0 && !tab[k - 1])
			return (ft_freeing(tab));
		i = i + j;
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_splitnewline(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = set_wordsnewline((char *)s, c);
	return (tab);
}
