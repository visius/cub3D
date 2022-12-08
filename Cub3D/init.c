/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:54:10 by dminerva          #+#    #+#             */
/*   Updated: 2021/05/18 00:54:13 by dminerva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	base_init(t_all *s)
{
	s->ray.x = 0;
	s->ray.y = 0;
	s->ray.v = 0;
	s->ray.w = 0;
	s->ray.i = 0;
	s->dir.x = 0;
	s->dir.y = 0;
	s->map.x = 0;
	s->map.y = 0;
	s->win.x = 0;
	s->win.y = 0;
	s->pos.x = 0;
	s->pos.y = 0;
}

void	err_init(t_all *s)
{
	s->err.save = -1;
	s->err.err_plr = -1;
	s->err.err_tex = 0;
	s->err.err_res = 0;
	s->err.err_map = 0;
	s->err.err_pos = 0;
	s->err.err_color = 0;
	s->err.is_error = 0;
	s->err.err_line = 0;
}

void	tex_init(t_all *s)
{
	s->tex.c = -1;
	s->tex.f = -1;
	s->spr = NULL;
	s->tex.no = NULL;
	s->tex.so = NULL;
	s->tex.we = NULL;
	s->tex.ea = NULL;
	s->tex.s = NULL;
	s->tex.noptr = NULL;
	s->tex.soptr = NULL;
	s->tex.weptr = NULL;
	s->tex.eaptr = NULL;
	s->tex.sptr = NULL;
}

void	cub_init(t_all *s)
{
	base_init(s);
	tex_init(s);
	err_init(s);
}
