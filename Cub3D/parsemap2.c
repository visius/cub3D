/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:53:49 by dminerva          #+#    #+#             */
/*   Updated: 2021/05/18 00:53:50 by dminerva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	set_rotation(char c, t_all *s)
{
	if (c == 'E')
		s->pos.rot = 0;
	if (c == 'W')
		s->pos.rot = 90;
	if (c == 'S')
		s->pos.rot = 180;
	if (c == 'N')
		s->pos.rot = 270;
}

void	set_transform(char c, t_all *s, int x, int y)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
	{	
		if (s->err.err_plr == 1)
		{
			printf("Error\nError player\n");
			exit(0);
		}
		s->pos.y = y + 0.5;
		s->pos.x = x + 0.5;
		if (s->pos.rot != -1)
			s->err.err_pos = -90;
		set_rotation(c, s);
		s->err.err_plr = 1;
		spawn_dir(s);
	}
}

void	spawn_dir(t_all *s)
{
	if (s->pos.rot == 0)
		s->dir.y = 0;
	if (s->pos.rot == 0)
		s->dir.x = 1;
	if (s->pos.rot == 90)
		s->dir.y = 0;
	if (s->pos.rot == 90)
		s->dir.x = -1;
	if (s->pos.rot == 180)
		s->dir.y = 1;
	if (s->pos.rot == 180)
		s->dir.x = 0;
	if (s->pos.rot == 270)
		s->dir.y = -1;
	if (s->pos.rot == 270)
		s->dir.x = 0;
}
