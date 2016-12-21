/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 20:41:03 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/21 11:50:24 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
