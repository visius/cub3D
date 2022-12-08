#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

typedef struct s_mlx
{
	void			*mlx;
	void			*frame;
	int				*data;
	int				len;
	int				end;
	int				bit;
	int				screen_x;
	int				screen_y;
}				t_mlx;

typedef struct s_win
{
	void			*pwin;
	int				x;
	int				y;
}				t_win;

typedef struct s_map
{
	char			**map;
	int				x;
	int				y;
	int				spr;
}				t_map;

typedef struct s_dir
{
	double			x;
	double			y;
	double			a;
}				t_dir;

typedef struct s_move
{
	int				is_arrows;
	double			mx;
	double			my;
	double			move;
	double			strafe;
	double			turn;
	int				q;
}				t_move;

typedef struct s_pos
{
	double			x;
	double			y;
	double			rot;
}				t_pos;

typedef struct s_spr
{
	double			x;
	double			y;
	double			d;
}				t_spr;

typedef struct s_stk
{
	double			x;
	double			y;
	double			d;
}				t_stk;

typedef struct s_ray
{
	int				i;
	double			x;
	double			y;
	double			v;
	double			w;
	double			a;
}				t_ray;

typedef struct s_tex
{
	void			*noptr;
	void			*soptr;
	void			*weptr;
	void			*eaptr;
	void			*sptr;
	unsigned int	*no;
	unsigned int	*so;
	unsigned int	*we;
	unsigned int	*ea;
	unsigned int	*s;
	unsigned int	*i;
	int				c;
	int				f;
	int				xres;
	int				yres;
	int				len;
	int				end;
	int				bit;
}				t_tex;

typedef struct s_hit
{
	double			x;
	double			y;
	double			d;
	double			hl;
	int				grad;
}				t_hit;

typedef struct s_err
{
	int			err_res;
	int			err_tex;
	int			err_color;
	int			bmp_save;
	int			err_map;
	int			err_plr;
	int			save;
	int			err_pos;
	int			errn;
	int			err_line;
	int			is_error;
}				t_err;

typedef struct s_vector
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_vector;

typedef struct s_counters
{
	int			i;
	int			j;
	int			k;
	int			index;
	int			line;
}				t_counters;

#endif