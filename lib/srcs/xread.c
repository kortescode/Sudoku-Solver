#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

int		xread(int fd, void *str, int size)
{
  int		ret;

  if ((ret = read(fd, str, size)) == ERROR)
    {
      my_puterror("Can't perform read().\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}
