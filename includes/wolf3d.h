/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:51:03 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/18 15:05:05 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# define winX 512
# define winY 384
# define USAGE "usage: wolf3d \"map\"\n"

typedef struct	s_wolf3d
{
	int			**map;
	int			nb_lines;
	int			lenline;
	int			bpp;
	int			endian;
	int			sl;
	char		*map_name;
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			delete1;
}				t_wolf3d;

void			quit(void);
int				parser(t_wolf3d *t, char **av);
int				parser2(t_wolf3d *t, char **av);
#endif
