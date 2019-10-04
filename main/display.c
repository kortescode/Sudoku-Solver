#include	"sudoku.h"
#include	"my.h"

static char	**init_color(void)
{
  char		**color;

  color = xmalloc(sizeof(*color) * (GRID_SIZE + 1));
  color[0] = "\033[1;32m";
  color[1] = "\033[0;31m";
  color[2] = "\033[0;32m";
  color[3] = "\033[0;33m";
  color[4] = "\033[0;34m";
  color[5] = "\033[0;35m";
  color[6] = "\033[0;36m";
  color[7] = "\033[0;37m";
  color[8] = "\033[1;31m";
  color[9] = NULL;
  return (color);
}

static void	print_number(int number, int option)
{
  static int	init = TRUE;
  static char  	**color;

  if (option >= COLOR)
    {
      if (init == TRUE)
	{
	  color = init_color();
	  init = FALSE;
	}
      my_putstr(color[number - 1]);
    }
  my_putchar(number + '0');
  if (option >= COLOR)
    my_putstr("\033[0;37m");
}

void		display_grid(int **grid, int option)
{
  int		x;
  int		y;

  y = 0;
  my_putstr("|------------------|\n");
  while (grid[y])
    {
      x = 0;
      my_putchar('|');
      while (x < GRID_SIZE)
	{
	  my_putchar(' ');
	  if (grid[y][x] == 0)
	    my_putchar(' ');
	  else
	    print_number(grid[y][x], option);
	  x++;
	}
      y++;
      my_putstr("|\n");
    }
  my_putstr("|------------------|\n");
}
