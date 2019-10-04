#include	<SDL/SDL.h>
#include	"sudoku.h"
#include	"my.h"

SDL_Surface	*init_graph_mode(int ac)
{
  SDL_Surface	*img;

  img = NULL;
  if (ac == GRAPH)
    {
      xsdl_init(SDL_INIT_VIDEO);
      img = xsdl_setvideomode(700, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
      SDL_WM_SetCaption("Sudoki-bi", NULL);
    }
  return (img);
}
