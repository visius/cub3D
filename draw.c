#include"cub3d.h"

unsigned int	get_pixel(t_all *s, double i)
{
	int	index;

	if (floor(s->hit.y) == s->hit.y)
	{
		index = 64 * floor(64 * i) + 64 * (s->hit.x - floor(s->hit.x));
		if (s->ray.w == 1)
			return (s->tex.so[index]);
		else if (s->ray.w == 0)
			return (s->tex.no[index]);
	}
	else if (floor(s->hit.x) == s->hit.x)
	{
		index = 64 * floor(64 * i) + 64 * (s->hit.y - floor(s->hit.y));
		if (s->ray.v == 1)
			return (s->tex.ea[index]);
		else if (s->ray.v == 0)
			return (s->tex.we[index]);
	}
	return (0x00000000);
}

void	drawlinevert(t_all *s, int posx, int h, int c)
{
	int	y;
	int	line;
	int	index;
	int	hl;
	int	shift;

	c = 4;
	y = 0;
	hl = h;
	shift = 0;
	if (h > s->win.y)
	{
		hl = s->win.y;
		shift += (h - hl) / 2;
	}
	line = s->mlx.len / (s->mlx.bit / 8);
	while (y < hl)
	{
		index = line * y + line * ((s->win.y - hl) / 2) + posx;
		s->mlx.data[index] = get_pixel(s, (double)(y + shift) / h);
		y++;
	}
}

void	fillcolor(t_all *s, int posy, int h, int c)
{
	int	x;
	int	y;
	int	index;
	int	line;

	x = -1;
	y = -1;
	line = s->mlx.len / (s->mlx.bit / 8);
	while (++y < h)
	{
		while (++x < s->win.x)
		{
			index = line * y + line * posy + x;
			s->mlx.data[index] = c;
		}
		x = -1;
	}
}

int	cub_frame(t_all *s)
{
	s->stk = malloc(sizeof(t_stk) * s->win.x);
	while (s->ray.i < s->win.x)
	{
		if (s->ray.i % 1 == 0)
		{
			cub_ray(s);
			ray_dir(s);
			ray_verttical(s);
			ray_horizontal(s);
			cub_hline(s);
			cub_stock(s);
			drawlinevert(s, s->ray.i, s->hit.hl, light(s, 30));
		}
		s->ray.i++;
	}
	cub_sprite(s);
	s->ray.i = 0;
	return (0);
}

void	cub_sdraw(t_all *s, int loc, double dist)
{
	unsigned int	col;
	double			size;
	t_counters		c;

	c.i = 0;
	c.j = 0;
	c.line = s->mlx.len / (s->mlx.bit / 8);
	size = s->win.y / dist;
	loc = loc - size / 2;
	while (c.i < size)
	{
		while ((loc + c.i >= 0 && loc + c.i < s->win.x) && \
				(c.j < size && s->stk[loc + c.i].d > dist))
		{
			col = 64 * floor(64 * (double)c.j / size) + (double)c.i / size * 64;
			c.index = loc + c.i + ((s->win.y / 2) - ((int)size / 2) + c.j) * c.line;
			if (c.index < s->win.x * s->win.y && !(s->tex.s[col] >> 24))
				s->mlx.data[c.index] = s->tex.s[col];
			c.j++;
		}
		c.i++;
		c.j = 0;
	}
}
