/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:02:40 by ataji             #+#    #+#             */
/*   Updated: 2023/01/10 15:10:53 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		if (ft_strlen(s) < len)
			len = ft_strlen(s);
		str = (char *)malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (i < len)
			str[i++] = s[start++];
	}
	else
		str = (char *)malloc(1);
	str[i] = '\0';
	return (str);
}
