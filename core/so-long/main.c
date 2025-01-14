#include "so_long.h"
//free the map in case of an error or at the end of it
void     free_map_sl(char **game, int line_count)
{
    int i;
    
    i = 0;
    while (i < line_count)
    {
        free(game[i]);
        i++;
    }
    free(game);
}


int main(int argc, char **argv) 
{
    t_map  game;
    size_t i  = 0;
    int j = 0;
    if (argc == 2)
    {
        if (read_map_file(&game, argv[1])) 
        {
            fprintf(stderr, "Error reading map file.\n");
            return 1;
        }
        while (i < game.line_count)
        {
            j  = 0;
            while (j < 13)
            {
                printf("%c", game.grid[i][j]);
                j++;
            }
            i++;
            printf("\n");
        }
        free_map_sl(game.grid, game.line_count);
        // game.mlx_ptr = mlx_init();
        // if (game.mlx_ptr == NULL)
        //     return (1);
    	// game.mlx_win = mlx_new_window(game.mlx_ptr, , 500, "Hello World!");
    }
    return 0;
}