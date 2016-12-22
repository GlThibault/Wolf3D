/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 20:41:03 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/22 20:40:03 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pxl_to_img_wall(t_wolf3d *t, int x, int y, int color)
{
	int d;

	d = y * 256 - WINY * 128 + t->lineheight * 128;
	t->y_text = ((d * 64) / t->lineheight) / 256;
	t->y_text = abs(t->y_text);
	if (t->texture == 1 && x < WINX && y < WINY)
	{
		color = mlx_get_color_value(t->mlx, color);
		ft_memcpy(t->img_ptr + 4 * WINX * y + x * 4,
				&t->tex[t->id].data[t->x_text % 64 * t->tex[t->id].sizeline +
				t->y_text % 64 * t->tex[t->id].bpp / 8], sizeof(int));
	}
	else if (x < WINX && y < WINY)
	{
		color = mlx_get_color_value(t->mlx, color);
		ft_memcpy(t->img_ptr + 4 * WINX * y + x * 4,
				&color, sizeof(int));
	}
}

void	draw_line_wall(int x, int start, int end, t_wolf3d *t)
{
	t->id = t->map[t->x_map][t->y_map] - 1;
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
	while (start < end)
	{
		put_pxl_to_img_wall(t, x, start, t->color);
		start++;
	}
}

void	put_pxl_to_img(t_wolf3d *t, int x, int y, int color)
{
	if (x < WINX && y < WINY)
	{
		color = mlx_get_color_value(t->mlx, color);
		ft_memcpy(t->img_ptr + 4 * WINX * y + x * 4,
				&color, sizeof(int));
	}
}

void	draw_line(int x, int start, int end, t_wolf3d *t)
{
	while (start < end)
	{
		put_pxl_to_img(t, x, start, t->color);
		start++;
	}
}
