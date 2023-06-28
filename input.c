#include "cub3d.h"

int	cub_key_press(int keycode, t_all *s)
{
	if (keycode == ESC)
		cub_exit(s);
	if (keycode == LEFT)
		s->move.turn = -1;
	if (keycode == RIGHT)
		s->move.turn = 1;
	if (keycode == W)
		s->move.move = 1;
	if (keycode == S)
		s->move.move = -1;
	if (keycode == A)
		s->move.strafe = -0.5;
	if (keycode == D)
		s->move.strafe = 0.5;
	if (keycode == LEFT || keycode == RIGHT)
		s->move.is_arrows = 1;
	return (1);
}

int	cub_key_release(int keycode, t_all *s)
{
	if (keycode == LEFT)
		s->move.turn = 0;
	if (keycode == RIGHT)
		s->move.turn = 0;
	if (keycode == W)
		s->move.move = 0;
	if (keycode == S)
		s->move.move = 0;
	if (keycode == A)
		s->move.strafe = 0;
	if (keycode == D)
		s->move.strafe = 0;
	if (keycode == LEFT || keycode == RIGHT)
		s->move.is_arrows = 0;
	return (1);
}

int	cub_mouse(t_all *s)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(s->win.pwin, &x, &y);
	s->move.turn = x - s->move.mx;
	s->move.turn = s->move.turn / 20;
	s->move.mx = x;
	if (s->move.mx > s->win.x)
	{
		mlx_mouse_move(s->win.pwin, 0, y);
		s->move.mx = 0;
	}
	if (s->move.mx < 0)
	{
		mlx_mouse_move(s->win.pwin, s->win.x, y);
		s->move.mx = s->win.x;
	}
	return (1);
}

void	input_check(t_all *s)
{
	if (s->move.move > 1)
		s->move.move = 1;
	if (s->move.move < -1)
		s->move.move = -1;
	if (s->move.strafe > 1)
		s->move.strafe = 1;
	if (s->move.strafe < -1)
		s->move.strafe = -1;
}

int	cub_input(t_all *s)
{
	input_check(s);
	cub_strafe(s->move.strafe, s);
	cub_moveforward(s->move.move, s);
	cub_rotate(s->move.turn, s);
	if (s->move.is_arrows == 0)
		cub_mouse(s);
	return (1);
}
