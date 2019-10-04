#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

void		*xmalloc(int size)
{
  void		*str;

  if ((str = malloc(size)) == NULL && size != 0)
    {
      my_puterror("Can't perform malloc().\n");
      exit(EXIT_FAILURE);
    }
  return (str);
}
