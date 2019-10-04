#include	<stdlib.h>
#include	"sudoku.h"
#include	"my.h"

char    	**create_map_tab(void)
{
  int		n;
  char		**map;

  n = 0;
  map = xmalloc(sizeof(*map) * (MAP_HEIGHT + 1));
  while (n < MAP_HEIGHT)
    map[n++] = get_next_line(0);
  map[n] = NULL;
  if (!map[0])
    return (NULL);
  return (map);
}
