/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 20:41:03 by tglandai          #+#    #+#             */
/*   Updated: 2017/01/02 13:28:20 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>
void	put_pxl_to_img_wall(t_wolf3d *t, int x, int y, int color)
{
	if (t->texture == 1 && x < WINX && y < WINY)
	{
		t->y_text = abs((((y * 256 - WINY * 128 + t->lineheight * 128) * 64)
					/ t->lineheight) / 256);
		ft_memcpy(t->img_ptr + 4 * WINX * y + x * 4,
				&t->tex[t->id].data[t->y_text % 64 * t->tex[t->id].sizeline +
				t->x_text % 64 * t->tex[t->id].bpp / 8], sizeof(int));
	}
	else if (x < WINX && y < WINY)
		ft_memcpy(t->img_ptr + 4 * WINX * y + x * 4,
				&color, sizeof(int));
}

void	draw_line_wall(int x, int start, int end, t_wolf3d *t)
{
	if (t->texture == 1)
	{
		t->id = t->map[t->x_map][t->y_map];
		if (t->side == 0)
			t->x_wall = t->y_raypos + t->walldist * t->y_raydir;
		else
			t->x_wall = t->x_raypos + t->walldist * t->x_raydir;
		t->x_text = (int)(t->x_wall * (double)(64));
		if (t->side == 0 && t->x_raydir > 0)
			t->x_text = 64 - t->x_text - 1;
		if (t->side == 1 && t->y_raydir < 0)
			t->x_text = 64 - t->x_text - 1;
		t->x_text = abs(t->x_text);
	}
	while (++start <= end)
		put_pxl_to_img_wall(t, x, start, t->color);
}

void	put_pxl_to_img(t_wolf3d *t, int x)
{
	t->curdist = WINY / (2.0 * t->y - WINY);
	t->weight = fabs(t->curdist / t->walldist);
	//printf("%f\n", t->weight);
	t->x_curfloortext = t->weight * t->x_floor + (1.0 - t->weight) * t->x_pos;
	t->y_curfloortext = t->weight * t->y_floor + (1.0 - t->weight) * t->y_pos;
	t->x_floortext = (int)((int)(t->x_curfloortext * 64) % 64);
	t->y_floortext = (int)((int)(t->y_curfloortext * 64) % 64);
	//printf("%d, %d\n", t->x_floortext, t->y_floortext);
	ft_memcpy(t->img_ptr + 4 * WINX * t->y + x * 4,
			&t->tex[t->id].data[t->y_floortext * t->tex[t->id].sizeline +
			t->x_floortext * t->tex[t->id].bpp / 8], sizeof(int));
	ft_memcpy(t->img_ptr + 4 * WINX * (WINY - t->y) + x * 4,
			&t->tex[t->id].data[t->y_floortext % 64 * t->tex[t->id].sizeline +
			t->x_floortext % 64 * t->tex[t->id].bpp / 8], sizeof(int));
}

void	draw_floor_and_ceiling(t_wolf3d *t, int x)
{
	if (t->side == 0 && t->x_raydir > 0)
	{
		t->x_floor = t->x_map;
		t->y_floor = t->y_map + t->x_wall;
	}
	else if (t->side == 0 && t->x_raydir < 0)
	{
		t->x_floor = t->x_map + 1.0;
		t->y_floor = t->y_map + t->x_wall;
	}
	else if (t->side == 1 && t->y_raydir > 0)
	{
		t->x_floor = t->x_map + t->x_wall;
		t->y_floor = t->y_map;
	}
	else
	{
		t->x_floor = t->x_map + t->x_wall;
		t->y_floor = t->y_map + 1.0;
	}
	t->id = 4;
	t->y = -1;
	while (++t->y < t->start)
		put_pxl_to_img(t, x);
}
