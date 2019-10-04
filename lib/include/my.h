#ifndef		MY_H_
# define	MY_H_

#include	<stdio.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>

/*************
*   MACROS   *
**************/

/*
** Boolean values
*/
enum		BOOLEAN		{FALSE, TRUE};

/*
** Error value
*/
# define	ERROR		-1

/*
** Max size for get_next_line()
*/
# define	LINE_SIZE	128

/*****************
*   PROTOTYPES   *
******************/

/*
** Lib My
*/
char		*get_next_line(int);
void		my_puterror(char *);
void		my_putchar(char);
void		my_putstr(char *);

/*
** Lib C
*/
void		*xmalloc(int);
void		xwrite(int, void *, int);
int		xread(int, void *, int);
void		xusleep(int);

/*
** Lib SDL
*/
void		xsdl_init(Uint32);
SDL_Surface	*xsdl_loadbmp(char *);
SDL_Surface	*xsdl_setvideomode(int, int, int, Uint32);
TTF_Font	*xttf_openfont(char *, int);
void		xsdl_flip(SDL_Surface *);

#endif		/* !MY_H_ */
