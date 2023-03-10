/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:54:51 by ataji             #+#    #+#             */
/*   Updated: 2023/01/19 21:25:25 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	checkkeys(t_data *data, char **elements)
{
	if (!ft_strcmp(elements[0], "WE") || !ft_strcmp(elements[0], "SO")
		|| !ft_strcmp(elements[0], "NO") || !ft_strcmp(elements[0], "EA"))
	{
		settexture(data, elements);
		if (checktexture(data, elements) == false)
			return (false);
		data->counter++;
	}
	else if (!ft_strcmp(elements[0], "F") || !ft_strcmp(elements[0], "C"))
	{
		if (checkrgb(data, elements) == false)
			return (false);
		data->counter++;
	}
	else
	{
		printf(ERRSYNMAP);
		return (false);
	}
	return (true);
}

bool	checkplayerstart(t_data *data)
{
	int	player;
	int	i;
	int	j;

	player = 0;
	i = -1;
	while (data->secondlines[++i])
	{
		j = -1;
		while (data->secondlines[i][++j])
		{
			if (data->secondlines[i][j] == 'N' || data->secondlines[i][j] == 'S'
				|| data->secondlines[i][j] == 'W'
					|| data->secondlines[i][j] == 'E')
				player++;
		}
	}
	if (player != 1)
		return (printf(PLAYERSTART), false);
	return (true);
}

bool	parsecharsecondmap(t_data *data)
{
	int		i;
	int		j;
	char	helper;

	i = -1;
	while (data->secondlines[++i])
	{
		j = -1;
		while (data->secondlines[i][++j])
		{
			helper = data->secondlines[i][j];
			if (helper != '1' && helper != '0' && helper != 'N' && helper != 'W'
				&& helper != 'E' && helper != 'S' && helper != ' ')
				return (printf(INTRUDER), false);
		}
	}
	return (true);
}

bool	parsemap(t_data *data)
{
	if (parsefirstofmap(data) == false)
		return (false);
	if (parsesecondofmap(data) == false)
		return (false);
	if (parsecharsecondmap(data) == false)
		return (false);
	return (true);
}

bool	allparsing(int ac, char **av, t_data *data)
{
	if (check_arguments(ac, av[1]) == false)
		return (false);
	if (readfromfile(av[1], data) == false)
		return (false);
	data->countfirstlines = countlinesfirstmap(data);
	data->countsecondlines = countlinessecondmap(data);
	if (dividingmap(data) == false)
		return (false);
	if (parsemap(data) == false)
		return (false);
	return (true);
}
