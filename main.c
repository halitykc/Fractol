#include "ft_fractol.h"

// cc main.c utils.c -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
void	fractal_initializer(t_fractol *fract, char *name)
{
	fract->f_connection = mlx_init();
	fract->f_window = mlx_new_window(fract->f_connection, WIDTH, HEIGHT, name);
	if (!fract->f_window)
	{
		mlx_destroy_display(fract->f_connection);
		free(fract->f_connection);
		return ;
	}
	fract->img.img_ptr = mlx_new_image(fract->f_connection,WIDTH,HEIGHT);
	if (!fract->img.img_ptr)
	{
		mlx_destroy_window(fract->f_connection, fract->f_window);
		mlx_destroy_display(fract->f_connection);
		free(fract->f_connection);
		return ;
    }
	fract->img.pixel_ptr = mlx_get_data_addr(fract->img.img_ptr,&fract->img.bitperpixel,&fract->img.size_line, &fract->img.endian);
}

int	cls_win(t_fractol *fract)
{
	mlx_destroy_image(fract->f_connection,fract->img.img_ptr);
	mlx_destroy_window(fract->f_connection, fract->f_window);
	mlx_destroy_display(fract->f_connection);
	free(fract->f_connection);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fractol frctl;
	if ((argc == 2 && !ft_strcmp(argv[1], "Mandelbrot")) || (argc == 4 && !ft_strcmp(argv[1], "Julia")))
	{
		fractal_initializer(&frctl, argv[1]);
		mlx_hook(frctl.f_window, 17, 0, cls_win, &frctl);
		mlx_loop(frctl.f_connection);		
	}
	else
	{
		// HATA MESAJİ YAZ BURA 
		// GEÇERLI SETLERI LISTELE
		exit(1);
	}
}
