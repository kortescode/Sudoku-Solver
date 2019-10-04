#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

void		xwrite(int fd, void *str, int size)
{
  if (write(fd, str, size) == ERROR)
    {
      my_puterror("Can't perform write().\n");
      exit(EXIT_FAILURE);
    }
}
