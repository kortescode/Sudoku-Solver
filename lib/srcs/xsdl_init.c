#include	<SDL/SDL.h>
#include	"my.h"

void		xsdl_init(Uint32 flags)
{
  if (SDL_Init(flags) == ERROR)
    {
      fprintf(stderr, "error : SDL Init failed.\n");
      exit(EXIT_FAILURE);
    }
}
