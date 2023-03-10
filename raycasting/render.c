/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataji <ataji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:28:59 by aanjaimi          #+#    #+#             */
/*   Updated: 2023/01/20 15:54:35 by ataji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsingcub3d/cub3d.h"

void	set_rays_hor(t_data *data, int i, double ray_angle)
{
	dda(data, data->ray.next_hor_touch_x, data->ray.next_hor_touch_y);
	data->rays[i].x = data->ray.next_hor_touch_x;
	data->rays[i].y = data->ray.next_hor_touch_y;
	data->rays[i].ang = ray_angle;
	data->rays[i].up = data->ray.is_up;
	data->rays[i].down = data->ray.is_down;
	data->rays[i].right = data->ray.is_right;
	data->rays[i].left = data->ray.is_left;
	data->rays[i].dis = data->hor_dis;
	data->rays[i].cor = data->rays[i].dis * \
	cos(ray_angle - data->ply.rotation_angle);
	data->rays[i].ver = 0;
}

void	set_rays_ver(t_data *data, int i, double ray_angle)
{
	dda(data, data->ray.next_ver_touch_x, data->ray.next_ver_touch_y);
	data->rays[i].x = data->ray.next_ver_touch_x;
	data->rays[i].y = data->ray.next_ver_touch_y;
	data->rays[i].ang = ray_angle;
	data->rays[i].up = data->ray.is_up;
	data->rays[i].down = data->ray.is_down;
	data->rays[i].right = data->ray.is_right;
	data->rays[i].left = data->ray.is_left;
	data->rays[i].dis = data->ver_dis;
	data->rays[i].cor = data->rays[i].dis * \
	cos(ray_angle - data->ply.rotation_angle);
	data->rays[i].ver = 1;
}

void	ray_cast(t_data *data, double ray_angle)
{
	check_dir_ray(data, ray_angle);
	check_hor_int(data, data->ply.x1, data->ply.y1, ray_angle);
	check_ver_int(data, data->ply.x1, data->ply.y1, ray_angle);
	calcule_distances(data);
}

void	render_rays(t_data *data)
{
	double	ray_angle;
	int		i;

	i = -1;
	ray_angle = data->ply.rotation_angle - (data->fov_angle / 2);
	while (++i < data->num_rays)
	{
		ray_angle = mod(ray_angle, (2 * M_PI));
		ray_cast(data, ray_angle);
		if (data->hor_dis < data->ver_dis)
			set_rays_hor(data, i, ray_angle);
		else
			set_rays_ver(data, i, ray_angle);
		ray_angle += data->fov_angle / data->num_rays;
	}
}

int	render(t_data *data)
{
	mlx_clear_window(data->var.mlx, data->var.win);
	render_map(data);
	render_rays(data);
	draw_circle(data, data->ply.x1, data->ply.y1, SIZE_MINI / 8);
	generate3dprojection(data);
	mlx_put_image_to_window(data->var.mlx, data->var.win, \
	data->var.img_map.img, 0, 0);
	mlx_put_image_to_window(data->var.mlx, data->var.win, \
	data->var.img_mini.img, 0, 0);
	data->ply.rotation_angle = mod(data->ply.rotation_angle, 2 * M_PI);
	return (0);
}
