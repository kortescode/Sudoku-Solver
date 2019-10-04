#include	<unistd.h>
#include	<SDL/SDL.h>
#include	"my.h"
#include	"sudoku.h"

static void	key_management(SDL_Surface *img, int **grid)
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN &&
				 event.key.keysym.sym == SDLK_ESCAPE))
    {
      free(grid);
      SDL_FreeSurface(img);
      SDL_Quit();
      exit(EXIT_SUCCESS);
    }
  display_graph_mode(img, grid, CURRENT);
}

static int	test_possibilites(SDL_Surface *img, int **grid,
				  int pos, int *count)
{
  int		nbr;
  int		n;

  n = 0;
  if (img && (pos % 18) == 0)
    key_management(img, grid);
  while (n < 5)
    {
      if (away_nbr(grid, count[X], count[Y], nbr = NBR_MIN + n))
	{
	  grid[count[Y]][count[X]] = nbr;
	  if (solv_grid(img, grid, pos + 1))
	    return (TRUE);
	}
      if (away_nbr(grid, count[X], count[Y], nbr = NBR_MAX - n))
	{
	  grid[count[Y]][count[X]] = nbr;
	  if (solv_grid(img, grid, pos + 1))
	    return (TRUE);
	}
      ++n;
    }
  grid[count[Y]][count[X]] = NOTHING;
  return (FALSE);
}

int		solv_grid(SDL_Surface *img, int **grid, int pos)
{
  int		count[2];

  count[X] = pos % NBR_MAX;
  count[Y] = pos / NBR_MAX;
  if (pos == END)
    return (TRUE);
  if (grid[count[Y]][count[X]] != NOTHING)
    return (solv_grid(img, grid, pos + 1));
  return (test_possibilites(img, grid, pos, count));
}
