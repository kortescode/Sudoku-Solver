#include	<stdlib.h>
#include	"sudoku.h"
#include	"my.h"

static void	get_line(char **map, int **grid, int y)
{
  int		x;
  int		j;

  j = 2;
  x = INIT;
  grid[y] = xmalloc(sizeof(**grid) * (GRID_SIZE + 1));
  while (++x < GRID_SIZE)
    {
      grid[y][x] = NOTHING;
      if (IS_NBR(map[y + 1][j]))
	grid[y][x] = map[y + 1][j] - '0';
      j += 2;
    }
}

int		**get_grid(char **map)
{
  int		y;
  int		**grid;

  y = 0;
  grid = xmalloc(sizeof(*grid) * (GRID_SIZE + 1));
  while (y < GRID_SIZE)
    get_line(map, grid, y++);
  grid[y] = NULL;
  return (grid);
}
