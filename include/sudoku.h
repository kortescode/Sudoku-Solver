#ifndef		SUDOKU_H_
# define	SUDOKU_H_

#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>

/*************
*   MACROS   *
**************/

/*
** To start a loop
*/
# define	INIT		-1

/*
** Values returned from functions
*/
enum		RETURN		{FAILURE, SUCCESS};

/*
** Coord for array
*/
enum		COORD		{X, Y};

/*
** Possible options
*/
enum		OPTIONS		{NOTHING = 0, GRAPH = 1, ALTER = 2, COLOR = 4};

/*
** Mode for the display in the graphic mode
*/
enum		MODE		{START, CURRENT, FINISH};

/*
** Size of the map get on the standard input
*/
# define	MAP_HEIGHT	11
# define	MAP_WIDTH	20

/*
** Size of a basic sudoku grid
*/
# define	GRID_SIZE	9
# define	END		GRID_SIZE * GRID_SIZE

/*
** Numbers in a basic sudoku grid
*/
# define	NOTHING		0
# define	NBR_MIN		1
# define	NBR_MAX		9

/*
** Parametrized macros
*/
# define	IS_NBR(x)	(x) >= '1' && (x) <= '9'
# define	IS_MAP(x)      	(x) == '-' || (x) == '|' || (x) == ' '

/*****************
*   PROTOTYPES   *
******************/

/*
** Sudoku functions
*/
int		verif_map(char **);
char    	**create_map_tab(void);
int		**get_grid(char **);
int		sudoku(int);
int		solv_grid(SDL_Surface *, int **, int);
int     	away_nbr(int **, int, int, int);
void		display_grid(int **, int);

/*
** Graphic mode functions
*/
SDL_Surface	*init_graph_mode(int);
void		display_graph_mode(SDL_Surface *, int **, int);

#endif		/* !SUDOKU_H_ */
