#include	<stdio.h>
#include	"sudoku.h"
#include	"my.h"

static int	verif_height(char **map)
{
  int		y;

  y = 0;
  while (map[y])
    ++y;
  if (y != MAP_HEIGHT)
    {
      fprintf(stderr, "error : bad height of map.\n");
      return (FAILURE);
    }
  return (SUCCESS);
}

static int	verif_width(char **map)
{
  int		x;
  int		y;

  y = INIT;
  while (map[++y])
    {
      x = 0;
      while (map[y][x])
	++x;
      if (x != MAP_WIDTH)
	{
	  fprintf(stderr, "error : bad width of map line %d : \"%s\".\n", \
		  y + 1, map[y]);
	  return (FAILURE);
	}
    }
  return (SUCCESS);
}

static int	verif_garbage(char **map)
{
  int		x;
  int		y;

  y = INIT;
  while (map[++y])
    {
      x = INIT;
      while (map[y][++x])
	{
	  if (((y == 0 || y == (MAP_HEIGHT - 1)) && !(IS_MAP(map[y][x]))) ||
	      ((x == 0 || x == (MAP_WIDTH - 1)) && map[y][x] != '|') ||
	      (y != 0 && y != (MAP_HEIGHT - 1) && x != 0 &&
	       x != (MAP_WIDTH - 1) && !(IS_NBR(map[y][x])) && map[y][x] != ' '))
	    {
	      fprintf(stderr, "error : garbage in the map line %d : \"%s\".\n", \
		      y + 1, map[y]);
	      return (FAILURE);
	    }
	}
    }
  return (SUCCESS);
}

int		verif_map(char **map)
{
  if (!verif_height(map))
    return (FAILURE);
  if (!verif_width(map))
    return (FAILURE);
  if (!verif_garbage(map))
    return (FAILURE);
  return (SUCCESS);
}
