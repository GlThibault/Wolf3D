/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:35:38 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/18 15:19:13 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		parser2(t_wolf3d *t, char **av)
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	*str;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (ft_get_next_line(fd, &str) > 0)
	{
		j = -1;
		k = 0;
		if (!(t->map[i] = (int *)malloc(sizeof(int) * t->lenline)))
			return (0);
		while (++j < t->lenline)
		{
			if (str[k] == ' ')
				k++;
			t->map[i][j] = ft_atoi(&str[k]);
			k++;
		}
		i++;
		ft_strdel(&str);
	}
	return (1);
}

int		parser(t_wolf3d *t, char **av)
{
	int		fd;
	char	*buff;

	buff = ft_strnew(65536);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || (read(fd, buff, 65536)) < 1)
	{
		ft_putstr("wolf3d: ");
		ft_putstr(av[1]);
		ft_putstr(": No such file\n");
		return (0);
	}
	t->lenline = ft_linelen(buff);
	t->nb_lines = ft_countlines(buff);
	t->map_name = av[1];
	close(fd);
	if (!(t->map = (int **)malloc(sizeof(int *) * t->nb_lines)))
		return (0);
	if (!(parser2(t, av)))
		return (0);
	return (1);
}
