NAME	=	sudoki-bi

LIB	=	./lib/

CC	=	gcc
RM	=	rm -f
PRINTF	=	printf

MAIN	=	./main/
PREPARE	=	./prepare/
BT	=	./backtracing/
GRAPHIC	=	./graphic/

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	`sdl-config --cflags`
CFLAGS	+=	-I./include/ -I./lib/include/

LDFLAGS	+=	-L./lib/ -lmy
LDFLAGS	+=	`sdl-config --libs` -lSDL_ttf

SRCS	=	$(MAIN)main.c		\
		$(MAIN)sudoku.c		\
		$(MAIN)display.c	\
		$(PREPARE)verif.c	\
		$(PREPARE)map.c		\
		$(PREPARE)grid.c	\
		$(BT)solv.c		\
		$(BT)away.c		\
		$(GRAPHIC)init.c	\
		$(GRAPHIC)display.c

OBJS	=	$(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)
		@$(PRINTF) "\033[32m*** Compilation of $(NAME) done ***\n\033[00m"

all	:	lib $(NAME)

clean	:
		@$(RM) $(OBJS)
		@$(RM) *~ \#*\#
		@printf "\033[31m*** Objects are removed ***\n\033[00m"

fclean	:	clean
		@$(RM) $(NAME)
		@printf "\033[31m*** Binary $(NAME) is removed ***\n\033[00m"

re	:	fclean all

lib	:
		@make -C $(LIB)

.PHONY:		all clean fclean re lib