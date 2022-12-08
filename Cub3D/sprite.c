/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:51:46 by dminerva          #+#    #+#             */
/*   Updated: 2021/05/18 02:19:03 by dminerva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	cub_slocate(t_all *s, double dirx, double diry, double dist)
{
	double	angle;

	dirx = (dirx - s->pos.x) / dist;
	diry = (diry - s->pos.y) / dist;
	if (diry <= 0)
		angle = acos(dirx) * 180 / M_PI;
	else
		angle = 360 - acos(dirx) * 180 / M_PI;
	angle = s->dir.a - angle + 33;
	if (angle >= 180)
		angle -= 360;
	else if (angle <= -180)
		angle += 360;
	cub_sdraw(s, angle * s->win.x / 66, dist);
}

void	cub_sorder(t_all *s)
{
	t_spr	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < s->map.spr - 1)
	{
		j = i + 1;
		while (j < s->map.spr)
		{
			if (s->spr[i].d < s->spr[j].d)
			{
				tmp = s->spr[i];
				s->spr[i] = s->spr[j];
				s->spr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	cub_sprite(t_all *s)
{
	int		i;
	double	dist;

	dist = hypot(s->dir.x, s->dir.y);
	if (s->dir.y <= 0)
		s->dir.a = acos(s->dir.x / dist) * 180 / M_PI;
	else
		s->dir.a = 360 - acos(s->dir.x / dist) * 180 / M_PI;
	i = 0;
	while (i < s->map.spr)
	{
		s->spr[i].d = hypot(s->spr[i].x - s->pos.x, s->spr[i].y - s->pos.y);
		i++;
	}
	cub_sorder(s);
	i = 0;
	while (i < s->map.spr)
	{
		if (s->spr[i].d > 0.1)
			cub_slocate(s, s->spr[i].x, s->spr[i].y, s->spr[i].d);
		i++;
	}
	free(s->stk);
}

int	cub_slist(t_all *s)
{
	t_vector	c;

	spr_count(s);
	if (s->spr != NULL)
		free(s->spr);
	s->spr = malloc(sizeof(t_spr) * s->map.spr);
	if (!s->spr)
		return (-1);
	c.r = 0;
	c.g = 0;
	while (c.g < s->map.y)
	{
		c.b = 0;
		while (c.b < s->map.x)
		{
			if (s->map.map[c.g][c.b] == '2')
			{
				s->spr[c.r].y = (double)c.g + 0.5;
				s->spr[c.r++].x = (double)c.b + 0.5;
			}
			c.b++;
		}
		c.g++;
	}
	return (1);
}

int	spr_count(t_all *s)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (j < s->map.y)
	{
		k = 0;
		while (k < s->map.x)
		{
			if (s->map.map[j][k] == '2')
			{
				i++;
				s->map.spr = i;
			}
			k++;
		}
		j++;
	}
	return (1);
}
