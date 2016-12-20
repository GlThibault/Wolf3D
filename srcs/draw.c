/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 20:41:03 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/20 21:12:09 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pxl_to_img(t_wolf3d *t, int x, int y, int color)
{
	if (x < winX && y < winY)
	{
		color = mlx_get_color_value(t->mlx, color);
		ft_memcpy(t->img_ptr + 4 * winX * y + x * 4,
				&color, sizeof(int));
	}
}

void	draw_line(int x, t_wolf3d *t, int color)
{
	while (t->start > t->end)
	{
		put_pxl_to_img(t, x, t->start, color);
		t->start--;
	}
}
