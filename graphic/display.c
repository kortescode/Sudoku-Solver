#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<unistd.h>
#include	"sudoku.h"
#include	"my.h"

static void	init_display_vars(SDL_Rect *pos, SDL_Color *black, \
				  TTF_Font **font, int *coords)
{
  coords[Y] = INIT;
  (*pos).y = 155;
  (*black).r = 0;
  (*black).g = 0;
  (*black).b = 0;
  *font = xttf_openfont("./graphic/fonts/FreeSans.ttf", 25);
}

static void	free_display_vars(SDL_Surface **text, TTF_Font **font)
{
  SDL_FreeSurface(*text);
  TTF_CloseFont(*font);
}

static void	fill_grid(SDL_Surface *img, int **grid)
{
  int		coords[2];
  char		number[2];
  SDL_Rect	pos;
  TTF_Font	*font;
  SDL_Surface	*text;
  SDL_Color	black;

  init_display_vars(&pos, &black, &font, coords);
  while (grid[++(coords[Y])])
    {
      pos.x = 65;
      coords[X] = INIT;
      while (++(coords[X]) < GRID_SIZE)
	{
	  pos.x += 55;
	  if (grid[(coords[Y])][(coords[X])] != NOTHING)
	    {
	      snprintf(number, 2, "%c", grid[(coords[Y])][(coords[X])] + '0');
	      text = TTF_RenderText_Blended(font, number, black);
	      SDL_BlitSurface(text, NULL, img, &pos);
	    }
	}
      pos.y += 55;
    }
  free_display_vars(&text, &font);
}

void		display_graph_mode(SDL_Surface *img, int **grid, int mode)
{
  SDL_Rect	pos;
  SDL_Surface	*blank_grid;

  pos.x = 0;
  pos.y = 0;
  TTF_Init();
  if (mode == START)
    blank_grid = xsdl_loadbmp("./graphic/imgs/start.bmp");
  else if (mode == CURRENT)
    blank_grid = xsdl_loadbmp("./graphic/imgs/grid.bmp");
  else if (mode == FINISH)
    blank_grid = xsdl_loadbmp("./graphic/imgs/finish.bmp");
  SDL_BlitSurface(blank_grid, NULL, img, &pos);
  fill_grid(img, grid);
  xsdl_flip(img);
  if (mode == START)
    sleep(1);
  else if (mode == CURRENT)
    xusleep(50000);
  else if (mode == FINISH)
    sleep(2);
  SDL_FreeSurface(blank_grid);
  TTF_Quit();
}
