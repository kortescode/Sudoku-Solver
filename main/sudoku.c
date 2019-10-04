#include	<SDL/SDL.h>
#include	<stdlib.h>
#include	"sudoku.h"
#include	"my.h"

static void    	display_management(SDL_Surface *img, int **grid, int option)
{
  static int	first = TRUE;

  if (option == GRAPH)
    {
      display_graph_mode(img, grid, START);
      solv_grid(img, grid, 0);
      display_graph_mode(img, grid, FINISH);
    }
  else
    {
      if (first == FALSE)
	my_putstr("####################\n");
      if (option == ALTER || option == (ALTER + COLOR))
	display_grid(grid, option);
      solv_grid(img, grid, 0);
      display_grid(grid, option);
    }
  first = FALSE;
}

int		sudoku(int option)
{
  int		**grid;
  char		**map;
  SDL_Surface	*img;

  img = init_graph_mode(option);
  while ((map = create_map_tab()))
    {
      if (!verif_map(map))
	return (FAILURE);
      grid = get_grid(map);
      free(map);
      display_management(img, grid, option);
      free(grid);
    }
  if (option == GRAPH)
    {
      SDL_FreeSurface(img);
      SDL_Quit();
    }
  return (SUCCESS);
}
