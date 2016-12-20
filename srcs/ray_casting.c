/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:49:39 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/20 21:28:30 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	dda_init(t_wolf3d *t)
{
	t->x_deltaDist = sqrt(1 + (t->y_rayDir * t->y_rayDir)
			/ (t->x_rayDir * t->x_rayDir));
	t->y_deltaDist = sqrt(1 + (t->x_rayDir * t->x_rayDir)
			/ (t->y_rayDir * t->y_rayDir));
	if (t->x_rayDir < 0)
	{
		t->x_step = -1;
		t->x_sideDist = (t->x_rayPos - t->x_map) * t->x_deltaDist;
	}
	else
	{
		t->x_step = 1;
		t->x_sideDist = (t->x_map + 1.0 - t->x_rayPos) * t->x_deltaDist;
	}
	if (t->y_rayDir < 0)
	{
		t->y_step = -1;
		t->y_sideDist = (t->y_rayPos - t->y_map) * t->y_deltaDist;
	}
	else
	{
		t->y_step = 1;
		t->y_sideDist = (t->y_map + 1.0 - t->y_rayPos) * t->y_deltaDist;
	}
}

void	dda(t_wolf3d *t)
{
	t->hit = 0;
	while (t->hit == 0)
	{
		if (t->x_sideDist < t->y_sideDist)
		{
			t->x_sideDist += t->x_deltaDist;
			t->x_map += t->x_step;
			t->side = 0;
		}
		else
		{
			t->y_sideDist += t->y_deltaDist;
			t->y_map += t->y_step;
			t->side = 1;
		}
		if (t->map[t->x_map][t->y_map] > 0)
			t->hit = 1;
	}
}

void	ray_casting_init(t_wolf3d *t, int x)
{
	t->x_cam = 2 * x / winX - 1;
	t->x_rayPos = t->x_pos;
	t->y_rayPos = t->y_pos;
	t->x_rayDir = t->x_dir + t->x_plane * t->x_cam;
	t->y_rayDir = t->y_dir + t->y_plane * t->x_cam;
	t->x_map = t->x_rayPos;
	t->y_map = t->y_rayPos;
	dda_init(t);
	dda(t);
	if (t->side == 0)
		t->wallDist = (t->x_map - t->x_rayPos +
				(1 - t->x_step / 2) / t->x_rayDir);
	else
		t->wallDist = (t->y_map - t->y_rayPos +
				(1 - t->y_step / 2) / t->y_rayDir);
}

void	ray_casting(t_wolf3d *t)
{
	int	x;

	x = 0;
	t->img = mlx_new_image(t->mlx, winX, winY);
	t->img_ptr = mlx_get_data_addr(t->img, &t->bpp, &t->sl, &t->endian);
	while (x < winX)
	{
		ray_casting_init(t, x);
		printf("%d\n", t->lineHeight);
		t->lineHeight = winY / t->wallDist;
		t->start = -t->lineHeight / 2 + winY / 2;
		if (t->start < 0)
			t->start = 0;
		t->end = t->lineHeight / 2 + winY / 2;
		if (t->end >= winY)
			t->end = winY - 1;
		if (t->side == 1)
			draw_line(x, t, 0xdd8800);
		else
			draw_line(x, t, 0x0088dd);
		x++;
	}
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_destroy_image(t->mlx, t->img);
}
