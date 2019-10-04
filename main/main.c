#include	<string.h>
#include	<stdlib.h>
#include	"my.h"
#include	"sudoku.h"

static int	char_match(char c, char *base)
{
  int		i;

  i = INIT;
  while (base[++i])
    if (base[i] == c)
      return (SUCCESS);
  return (FAILURE);
}

static int	get_option_value(char *av)
{
  int		value;

  value = NOTHING;
  if (char_match('g', av))
    value += GRAPH;
  if (char_match('a', av))
    value += ALTER;
  if (char_match('c', av))
    value += COLOR;
  return (value);
}

static int	check_option(char *av)
{
  int		option;

  option = get_option_value(av);
  if (!option || option > (ALTER + COLOR) ||
      option == (GRAPH + ALTER) || option == (GRAPH + COLOR))
    return (FAILURE);
  return (SUCCESS);
}

int		main(int ac, char **av)
{
  if ((ac == 2 && !check_option(av[1])) || ac > 2)
    {
      fprintf(stderr, "usage : %s -[g : graphic mode] %s", \
	      av[0], "-[[c : color print] [a : alternative print]].\n");
      return (EXIT_FAILURE);
    }
  if (ac == 2)
    ac = get_option_value(av[1]);
  else
    ac = NOTHING;
  if (!sudoku(ac))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
