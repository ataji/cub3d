/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass_colore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:55:37 by ataji             #+#    #+#             */
/*   Updated: 2023/01/10 10:42:42 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	checkrgb(t_data *data, char **elements)
{
	if (!ft_strcmp(elements[0], "F"))
	{
		if (checkcolore(elements) == false)
			return (false);
		data->f++;
	}
	if (!ft_strcmp(elements[0], "C"))
	{
		if (checkcolore(elements) == false)
			return (false);
		data->c++;
	}
	return (true);
}

bool	checkfile(char **elements)
{
	int		fd;
	size_t	size;

	fd = open(elements[1], O_RDONLY);
	if (fd < 0)
	{
		perror ("ERROR ");
		return (false);
	}
	size = ft_strlen(elements[1]);
	if (elements[1][size - 1] != 'm' || elements[1][size - 2] != 'p'
		|| elements[1][size - 3] != 'x' || elements[1][size - 4] != '.')
	{
		printf(ERRIMGNAME);
		return (false);
	}
	close (fd);
	return (true);
}

bool	checktexture(t_data *data, char **elements)
{
	if (!ft_strcmp(elements[0], "WE"))
	{
		if (checkfile(elements) == false)
			return (false);
		data->we++;
	}
	if (!ft_strcmp(elements[0], "SO"))
	{
		if (checkfile(elements) == false)
			return (false);
		data->so++;
	}
	if (!ft_strcmp(elements[0], "NO"))
	{
		if (checkfile(elements) == false)
			return (false);
		data->no++;
	}
	if (!ft_strcmp(elements[0], "EA"))
	{
		if (checkfile(elements) == false)
			return (false);
		data->ea++;
	}
	return (true);
}

bool	checknumbers(char **colors)
{
	int	i;

	i = -1;
	if (countecolors(colors) != 3)
		return (printf(ERRNUMCOLOR), false);
	if (ft_atoi(colors[0]) < 0 || ft_atoi(colors[0]) > 255)
	{
		printf(ERRSYNCOLOR);
		return (false);
	}
	if (ft_atoi(colors[1]) < 0 || ft_atoi(colors[1]) > 255)
	{
		printf(ERRSYNCOLOR);
		return (false);
	}
	if (ft_atoi(colors[2]) < 0 || ft_atoi(colors[2]) > 255)
	{
		printf(ERRSYNCOLOR);
		return (false);
	}
	return (true);
}

bool	checkcolore(char **elements)
{
	char	**colors;
	int		i;
	int		countcomma;

	countcomma = 0;
	i = -1;
	while (elements[1] && elements[1][++i])
		if (elements[1][i] == ',')
			countcomma++;
	if (countcomma != 2)
	{
		printf(ERRSYNCOLOR);
		return (false);
	}
	colors = ft_split(elements[1], ',');
	if (checknumbers(colors) == false)
		return (false);
	ft_free(colors);
	return (true);
}
