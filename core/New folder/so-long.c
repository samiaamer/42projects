#include <stdlib.h>
#include "minilibx-linux/mlx.h"

int main()
{
    void *mlx_ptr;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (1);

    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
    
}