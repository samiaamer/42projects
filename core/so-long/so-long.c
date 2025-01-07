#include <stdlib.h>
#include <mlx.h>


typedef struct s_long
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}                  t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dest;

    dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dest = color;
}

int main()
{
    void    *mlx_ptr;
    t_data  img;
    void    *mlx_win;
    int     x;
    int     y;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (1);
	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "Hello World!");
    img.img = mlx_new_image(mlx_ptr, 500, 500);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    x = 100;
    y = 100;
    while (x < 400)
    {
        my_mlx_pixel_put(&img, x, y, 0x00FF0000);
        x++;
    }
    while (y < 300)
    {
        my_mlx_pixel_put(&img, x, y, 0x00FF0000);
        y++;
    }
    while (x > 100)
    {
        my_mlx_pixel_put(&img, x, y, 0x00FF0000);
        x--;
    }
    while (y > 100)
    {
        my_mlx_pixel_put(&img, x, y, 0x00FF0000);
        y--;
    }
    x = 100;
    y = 100;
    while (x < 200 && y < 150)
    {
        my_mlx_pixel_put(&img, x, y, 0x00FF0000);
        x++;
        y--;
    }
    
    
    
    

    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
    mlx_loop(mlx_ptr);
    free(mlx_ptr);
    
}
