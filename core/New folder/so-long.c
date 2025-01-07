#include <stdlib.h>
#include <mlx.h>

int main()
{
    void *mlx_ptr;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (1);
	mlx_new_window(mlx_ptr, 500, 500, "title");
    mlx_loop(mlx_ptr);
    free(mlx_ptr);
    
}
