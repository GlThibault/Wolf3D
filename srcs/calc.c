/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:27:51 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/18 18:48:34 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calc(t_fractol *t)
{
	int	x;

	t->posX = 22;
	t->posY = 12;
	t->planeX = 0;
	t->planeY = 0.66;
	x = 0;
	while (x < winX)
	{
		t->cameraX = 2 * x / winX - 1;
		t->rayPosX = t->PosX;
		t->rayPosY = t->PosY;
		t->rayDirX = t->dirX + t->planeX * t->cameraX;
		t->rayDirY = t->dirY + t->planeY * t->cameraX;
		t->mapX = rayPosX;
		t->mapY = rayPosY;
	}
}
