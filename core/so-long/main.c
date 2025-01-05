#include "so-long.h"
//free the map in case of an error or at the end of it
void     free_map(char **map, int line_count)
{
    int i;
    
    i = 0;
    while (i < line_count)
    {
        free(map[i]);
        i++;
    }
    free(map);
}


int main() 
{
    t_map map;
    if (read_map_file(&map)) 
    {
        fprintf(stderr, "Error reading map file.\n");
        return 1;
    }
    return 0;
}