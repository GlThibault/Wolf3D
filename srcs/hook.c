/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:51:17 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/20 21:24:16 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_hook2(int keycode, t_wolf3d *t)
{
	if (keycode == 2 || keycode == 124)
	{
		t->x_oldDir = t->x_dir;
		t->x_dir = t->x_dir * cos(-t->rs) - t->y_dir * sin(-t->rs);
		t->y_dir = t->x_oldDir * sin(-t->rs) + t->y_dir * cos(-t->rs);
		t->x_oldPlane = t->x_plane;
		t->x_plane = t->x_plane * cos(-t->rs) - t->y_plane * sin(-t->rs);
		t->y_plane = t->x_oldPlane * sin(-t->rs) + t->y_plane * cos(-t->rs);
	}
	if (keycode == 0 || keycode == 123)
	{
		t->x_oldDir = t->x_dir;
		t->x_dir = t->x_dir * cos(t->rs) - t->y_dir * sin(t->rs);
		t->y_dir = t->x_oldDir * sin(t->rs) + t->y_dir * cos(t->rs);
		t->x_oldPlane = t->x_plane;
		t->x_plane = t->x_plane * cos(t->rs) - t->y_plane * sin(t->rs);
		t->y_plane = t->x_oldPlane * sin(t->rs) + t->y_plane * cos(t->rs);
	}
	return (0);
}

int		key_hook(int keycode, t_wolf3d *t)
{
	t->ms = 0.1;
	t->rs = 0.1;
	if (keycode == 53)
		exit(1);
	if (keycode == 13 || keycode == 126)
	{
		if (t->map[(int)(t->x_pos + t->x_dir * t->ms)][(int)(t->y_pos)] == 0)
			t->x_pos += t->x_dir * t->ms;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos + t->y_dir * t->ms)] == 0)
			t->y_pos += t->y_dir * t->ms;
	}
	if (keycode == 1 || keycode == 125)
	{
		if (t->map[(int)(t->x_pos - t->x_dir * t->ms)][(int)(t->y_pos)] == 0)
			t->x_pos -= t->x_dir * t->ms;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos - t->y_dir * t->ms)] == 0)
			t->y_pos -= t->y_dir * t->ms;
	}
	key_hook2(keycode, t);
	ray_casting(t);
	return (0);
}
