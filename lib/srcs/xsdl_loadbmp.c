#include	<SDL/SDL.h>

SDL_Surface	*xsdl_loadbmp(char *path)
{
  SDL_Surface	*bmp;

  if ((bmp = SDL_LoadBMP(path)) == NULL)
    {
      fprintf(stderr, "error : can't load image %s.\n", path);
      exit(EXIT_FAILURE);
    }
  return (bmp);
}
