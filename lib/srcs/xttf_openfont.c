#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>

TTF_Font	*xttf_openfont(char *path, int size)
{
  TTF_Font	*font;

  if ((font = TTF_OpenFont(path, size)) == NULL)
    {
      fprintf(stderr, "error : can't open font %s.\n", path);
      exit(EXIT_FAILURE);
    }
  return (font);
}
