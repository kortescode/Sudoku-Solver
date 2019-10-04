#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

char		*get_next_line(int fd)
{
  int		n;
  char		buffer[2];
  char		*line;
  int		verif;

  n = 0;
  line = xmalloc(sizeof(*line) * LINE_SIZE);
  verif = read(fd, &buffer, 1);
  while (verif == 1)
    {
      if (buffer[0] != '\n')
        line[n++] = buffer[0];
      else
        break;
      verif = read(fd, &buffer, 1);
    }
  if (verif == 0 || n == 0)
    return (NULL);
  line[n] = '\0';
  return (line);
}
