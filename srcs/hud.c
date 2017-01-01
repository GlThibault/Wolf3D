/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:32:00 by tglandai          #+#    #+#             */
/*   Updated: 2017/01/01 16:56:35 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	help_text(t_wolf3d *t)
{
	mlx_string_put(t->mlx, t->win, 10, 10,
			0xEEEEEE, "Press W A S D or the arrow keys to move.");
	mlx_string_put(t->mlx, t->win, 10, 30, 0xEEEEEE, "Press SHIFT to sprint.");
	mlx_string_put(t->mlx, t->win, 10, 50,
			0xEEEEEE, "Press DEL to reset the level.");
	mlx_string_put(t->mlx, t->win, 10, 70,
			0xEEEEEE, "Press T to show or hide textures.");
	mlx_string_put(t->mlx, t->win, 10, 90,
			0xEEEEEE, "Press H to show or hide this help.");
	mlx_string_put(t->mlx, t->win, 10, 110,
			0xEEEEEE, "Press ESC to quit.");
}
