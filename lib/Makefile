NAME	=	libmy.a

CC	=	gcc
AR	=	ar rc
RAN	=	ranlib
RM	=	rm -f

MY	=	./srcs/

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-D_BSD_SOURCE
CFLAGS	+=	-I./include/

SRCS	=	$(MY)xwrite.c			\
		$(MY)get_next_line.c		\
		$(MY)xmalloc.c			\
		$(MY)my_putchar.c		\
		$(MY)my_putstr.c		\
		$(MY)xread.c			\
		$(MY)xusleep.c			\
		$(MY)my_puterror.c		\
		$(MY)xsdl_init.c		\
		$(MY)xsdl_loadbmp.c		\
		$(MY)xsdl_setvideomode.c	\
		$(MY)xsdl_flip.c		\
		$(MY)xttf_openfont.c

OBJS	=	$(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
		@$(AR) $(NAME) $(OBJS)
		@$(RAN) $(NAME)
		@$(RM) $(OBJS)
		@printf "\033[32m*** Lib $(NAME) is compiled ***\n\033[00m"

all	:	$(NAME)

clean	:
		@$(RM) $(OBJS)
		@$(RM) *~ \#*\#
		@printf "\033[31m*** Objects are removed ***\n\033[00m"

fclean	:	clean
		@$(RM) $(NAME)
		@printf "\033[31m*** Lib $(NAME) is removed ***\n\033[00m"

re	:	fclean all

.PHONY	:	all clean fclean re