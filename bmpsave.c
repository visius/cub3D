#include"cub3d.h"

static void	dib_header(t_all *s, int fd)
{
	int	tmp;
	int	ret;

	tmp = 40;
	ret = write(fd, &tmp, 4);
	tmp = s->win.x;
	ret = write(fd, &tmp, 4);
	tmp = s->win.y;
	ret = write(fd, &tmp, 4);
	tmp = 1;
	ret = write(fd, &tmp, 2);
	tmp = 32;
	ret = write(fd, &tmp, 2);
	tmp = 0;
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	if (ret < 0)
		return ;
}

static void	bmp_header(t_all *s, int fd)
{
	int	tmp;
	int	ret;

	tmp = 0x42;
	ret = write(fd, &tmp, 1);
	tmp = 0x4D;
	ret = write(fd, &tmp, 1);
	tmp = (s->win.x * s->win.y) * 4 + 14 + 40;
	ret = write(fd, &tmp, 4);
	tmp = 0;
	ret = write(fd, &tmp, 2);
	ret = write(fd, &tmp, 2);
	tmp = 54;
	ret = write(fd, &tmp, 4);
	if (ret < 0)
		return ;
}

void	bmp_write(t_all *s, int fd, int x, int y)
{
	int	line;
	int	tmp;

	line = s->mlx.len / (s->mlx.bit / 8);
	while (y > -1)
	{
		x = 0;
		while (x < s->win.x)
		{
			tmp = s->mlx.data[line * y + x];
			if (write(fd, &tmp, 4) < 0)
			{
				return ;
			}
			x++;
		}
		y--;
	}
}

void	bmp_make(t_all *s)
{
	int		fd;
	int		x;
	int		y;
	mode_t	mode;

	mode = S_IRWXU | S_IRGRP | S_IROTH;
	fd = open("cub3d.bmp", O_RDWR | O_CREAT, mode);
	bmp_header(s, fd);
	dib_header(s, fd);
	y = s->win.y - 1;
	bmp_write(s, fd, x, y);
	s->err.save = -1;
	cub_exit(s);
}
