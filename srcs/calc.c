/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:27:51 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/19 15:18:59 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>
void	put_line(t_wolf3d *t, int x, int color)
{
	while (t->drawStart < t->drawEnd)
	{
		mlx_pixel_put(t->mlx, t->win, x, t->drawStart, color);
		t->drawStart++;
	}
}

void	calc(t_wolf3d *t)
{
	int	x;

	t->posX = 1;
	t->posY = 1;
	t->planeX = 0;
	t->planeY = 0.66;
	x = 0;
	while (x < winX)
	{
		t->cameraX = 2 * x / winX - 1;
		t->rayPosX = t->posX;
		t->rayPosY = t->posY;
		t->rayDirX = t->dirX + t->planeX * t->cameraX;
		t->rayDirY = t->dirY + t->planeY * t->cameraX;
		t->mapX = t->rayPosX;
		t->mapY = t->rayPosY;
		t->deltaDistX = sqrt(1 + (t->rayDirY * t->rayDirY) / (t->rayDirX * t->rayDirX));
		t->deltaDistY = sqrt(1 + (t->rayDirX * t->rayDirX) / (t->rayDirY * t->rayDirY));
		t->hit = 0;
		if (t->rayDirX < 0)
		{
			t->stepX = -1;
			t->sideDistX = (t->rayPosX - t->mapX) * t->deltaDistX;
		}
		else
		{
			t->stepX = 1;
			t->sideDistX = (t->mapX + 1.0 - t->rayPosX) * t->deltaDistX;
		}
		if (t->rayDirY < 0)
		{
			t->stepY = -1;
			t->sideDistY = (t->rayPosY -t->mapY) * t->deltaDistY;
		}
		else
		{
			t->stepY = 1;
			t->sideDistY = (t->mapY + 1.0 - t->rayPosY) * t->deltaDistY;
		}
		while (t->hit == 0)
		{
			if (t->sideDistX < t->sideDistY)
			{
				t->sideDistX += t->deltaDistX;
				t->mapX += t->stepX;
				t->side = 0;
			}
			else
			{
				t->sideDistY += t->deltaDistY;
				t->mapY += t->stepY;
				t->side = 1;
			}
			if (t->map[t->mapX][t->mapY] > 0)
				t->hit = 1;
			x++;
		}
		if (t->side == 0)
			t->perpWallDist = (t->mapX - t->rayPosX + (1 - t->stepX) / 2) / t->rayDirX;
		else
			t->perpWallDist = (t->mapY - t->rayPosY + (1 - t->stepY) / 2) / t->rayDirY;
		t->lineHeight = winY / t->perpWallDist;
		t->drawStart = -t->lineHeight / 2 + winY / 2;
		if (t->drawStart < 0)
			t->drawStart = 0;
		t->drawEnd = t->lineHeight / 2 + winY / 2;
		if (t->drawEnd < 0)
			t->drawEnd = 0;
		put_line(t, x, 0xFFFFFF);
	}
}
