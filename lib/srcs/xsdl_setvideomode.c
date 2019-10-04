#include	<SDL/SDL.h>

SDL_Surface	*xsdl_setvideomode(int width, int height, int bpp, Uint32 flags)
{
  SDL_Surface	*img;

  if ((img = SDL_SetVideoMode(width, height, bpp, flags)) == NULL)
    {
      fprintf(stderr, "error : SDL Set Video Mode failed.\n");
      exit(EXIT_FAILURE);
    }
  return (img);
}
