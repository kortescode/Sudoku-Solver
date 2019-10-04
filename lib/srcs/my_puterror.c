#include	<unistd.h>
#include	<string.h>

void		my_puterror(char *str)
{
  write(2, str, strlen(str));
}
