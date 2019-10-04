#include	"sudoku.h"
#include	"my.h"

static int     	away_from_line(int **map, int y, int nbr)
{
  int		x;

  x = INIT;
  while (++x < GRID_SIZE)
    if (map[y][x] == nbr)
      return (FALSE);
  return (TRUE);
}

static int     	away_from_column(int **map, int x, int nbr)
{
  int		y;

  y = INIT;
  while (map[++y])
    if (map[y][x] == nbr)
      return (FALSE);
  return (TRUE);
}

static int     	away_from_bloc(int **map, int x, int y, int nbr)
{
  int		x_bis;
  int		y_bis;

  x_bis = x - (x % 3);
  y_bis = y - (y % 3);
  y = y_bis;
  while (y < y_bis + 3)
    {
      x = x_bis;
      while (x < x_bis + 3)
	{
	  if (map[y][x] == nbr)
	    return (FALSE);
	  x++;
	}
      y++;
    }
  return (TRUE);
}

int     	away_nbr(int **map, int x, int y, int nbr)
{
  if (!away_from_line(map, y, nbr))
    return (FALSE);
  if (!away_from_column(map, x, nbr))
    return (FALSE);
  if (!away_from_bloc(map, x, y, nbr))
    return (FALSE);
  return (TRUE);
}
