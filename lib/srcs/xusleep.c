#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

void		xusleep(int usec)
{
  if (usleep(usec) == ERROR)
    {
      fprintf(stderr, "Can't perform usleep().\n");
      exit(EXIT_FAILURE);
    }
}
