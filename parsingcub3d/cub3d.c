/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:31:02 by ataji             #+#    #+#             */
/*   Updated: 2023/01/11 22:53:52 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_arguments(int numofargs, char *mapname)
{
	char	**lastmap;

	if (numofargs != 2)
		return (printf(ERRARGUMENTS), false);
	if (check_point(mapname) == true)
	{
		lastmap = ft_split(mapname, '.');
		if (ft_strcmp(lastmap[1], "cub"))
			return (printf(ERRNAME), false);
	}
	else
		return (printf(ERRNAME), false);
	ft_free(lastmap);
	return (true);
}

bool	readfromfile(char *mapname, t_data *data)
{
	int		fd;

	data->i = -1;
	data->countlines = countlines(mapname);
	if (data->countlines == -1)
		return (false);
	data->allmap = (char **)malloc(sizeof(char *) * data->countlines + 1);
	if (!data->allmap)
		return (false);
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR ");
		return (false);
	}
	while (++data->i < data->countlines)
		data->allmap[data->i] = get_next_line(fd);
	data->allmap[data->i] = NULL;
	close (fd);
	return (true);
}
