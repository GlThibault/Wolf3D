/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 14:44:53 by tglandai          #+#    #+#             */
/*   Updated: 2017/01/02 14:46:07 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_textures(t_wolf3d *t)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[0].img = mlx_xpm_file_to_image(t->mlx, "textures/wood.xpm", &a, &b);
	t->tex[0].data = mlx_get_data_addr(t->tex[0].img, &t->tex[0].bpp,
			&t->tex[0].sizeline, &t->tex[0].endian);
	t->tex[1].img = mlx_xpm_file_to_image(t->mlx, "textures/stone.xpm", &a, &b);
	t->tex[1].data = mlx_get_data_addr(t->tex[1].img, &t->tex[1].bpp,
			&t->tex[1].sizeline, &t->tex[1].endian);
	t->tex[2].img = mlx_xpm_file_to_image(t->mlx, "textures/mossy.xpm", &a, &b);
	t->tex[2].data = mlx_get_data_addr(t->tex[2].img, &t->tex[2].bpp,
			&t->tex[2].sizeline, &t->tex[2].endian);
	t->tex[3].img = mlx_xpm_file_to_image(t->mlx,
			"textures/redbrick.xpm", &a, &b);
	t->tex[3].data = mlx_get_data_addr(t->tex[3].img, &t->tex[3].bpp,
			&t->tex[3].sizeline, &t->tex[3].endian);
	t->tex[4].img = mlx_xpm_file_to_image(t->mlx, "textures/wood.xpm", &a, &b);
	t->tex[4].data = mlx_get_data_addr(t->tex[4].img, &t->tex[4].bpp,
			&t->tex[4].sizeline, &t->tex[4].endian);
	load_textures2(t, a, b);
}

void	load_textures2(t_wolf3d *t, int a, int b)
{
	t->tex[5].img = mlx_xpm_file_to_image(t->mlx, "textures/sand.xpm", &a, &b);
	t->tex[5].data = mlx_get_data_addr(t->tex[5].img, &t->tex[5].bpp,
			&t->tex[5].sizeline, &t->tex[5].endian);
	a = 512;
	b = 512;
	t->tex[6].img = mlx_xpm_file_to_image(t->mlx, "textures/sky.xpm", &a, &b);
	t->tex[6].data = mlx_get_data_addr(t->tex[6].img, &t->tex[6].bpp,
			&t->tex[6].sizeline, &t->tex[6].endian);
}
