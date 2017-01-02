/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:51:17 by tglandai          #+#    #+#             */
/*   Updated: 2017/01/02 18:35:58 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press2(int keycode, t_wolf3d *t)
{
	if (keycode == 4)
	{
		if (t->help == 0)
			t->help = 1;
		else
			t->help = 0;
	}
	else if (keycode == 17)
	{
		if (t->texture == 0)
			t->texture = 1;
		else
			t->texture = 0;
	}
	return (0);
}

int		key_press(int keycode, t_wolf3d *t)
{
	if (keycode == 13 || keycode == 126)
		t->move_up = 1;
	else if (keycode == 1 || keycode == 125)
		t->move_down = 1;
	else if (keycode == 2 || keycode == 124)
		t->move_right = 1;
	else if (keycode == 0 || keycode == 123)
		t->move_left = 1;
	else if (keycode == 257 || keycode == 258)
		t->ms = 0.1;
	else if (keycode == 53)
		exit(1);
	else if (keycode == 117)
		wolf3d_init(t);
	else
		key_press2(keycode, t);
	return (0);
}

int		key_release(int keycode, t_wolf3d *t)
{
	if (keycode == 13 || keycode == 126)
		t->move_up = 0;
	else if (keycode == 1 || keycode == 125)
		t->move_down = 0;
	else if (keycode == 2 || keycode == 124)
		t->move_right = 0;
	else if (keycode == 0 || keycode == 123)
		t->move_left = 0;
	else if (keycode == 257 || keycode == 258)
		t->ms = 0.05;
	return (0);
}

void	move_side(t_wolf3d *t)
{
	if (t->move_right == 1)
	{
		t->x_olddir = t->x_dir;
		t->x_dir = t->x_dir * cos(-t->rs) - t->y_dir * sin(-t->rs);
		t->y_dir = t->x_olddir * sin(-t->rs) + t->y_dir * cos(-t->rs);
		t->x_oldplane = t->x_plane;
		t->x_plane = t->x_plane * cos(-t->rs) - t->y_plane * sin(-t->rs);
		t->y_plane = t->x_oldplane * sin(-t->rs) + t->y_plane * cos(-t->rs);
	}
	if (t->move_left == 1)
	{
		t->x_olddir = t->x_dir;
		t->x_dir = t->x_dir * cos(t->rs) - t->y_dir * sin(t->rs);
		t->y_dir = t->x_olddir * sin(t->rs) + t->y_dir * cos(t->rs);
		t->x_oldplane = t->x_plane;
		t->x_plane = t->x_plane * cos(t->rs) - t->y_plane * sin(t->rs);
		t->y_plane = t->x_oldplane * sin(t->rs) + t->y_plane * cos(t->rs);
	}
}

int		move(t_wolf3d *t)
{
	if (t->move_up == 1)
	{
		if (t->map[(int)(t->x_pos + t->x_dir * t->ms)][(int)(t->y_pos)] == 0)
			t->x_pos += t->x_dir * t->ms;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos + t->y_dir * t->ms)] == 0)
			t->y_pos += t->y_dir * t->ms;
	}
	if (t->move_down == 1)
	{
		if (t->map[(int)(t->x_pos - t->x_dir * t->ms)][(int)(t->y_pos)] == 0)
			t->x_pos -= t->x_dir * t->ms;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos - t->y_dir * t->ms)] == 0)
			t->y_pos -= t->y_dir * t->ms;
	}
	move_side(t);
	ray_casting(t);
	if (t->help == 1)
		help_text(t);
	return (0);
}
