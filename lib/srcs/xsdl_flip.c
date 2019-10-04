#include	<SDL/SDL.h>
#include	"my.h"

void		xsdl_flip(SDL_Surface *screen)
{
  if (SDL_Flip(screen) == ERROR)
    {
      fprintf(stderr, "error : SDL Flip failed.\n");
      exit(EXIT_FAILURE);
    }
}
