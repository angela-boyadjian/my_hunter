##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## A Makefile for projetcs
##

CC	=	gcc -l c_graph_prog

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include

NAME	=	my_hunter

SRCS	=	srcs/main.c \
		srcs/create_my_window.c \
		srcs/events.c \
		srcs/init_functions.c \
		srcs/create_text.c \
		srcs/end_game.c \
		srcs/move.c \
		srcs/size.c \
		srcs/error.c \
		srcs/init_game.c \
		srcs/display.c

OBJS	=	$(SRCS:.c=.o)

LIB =		-L./lib -lmy

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(RM) lib/*.a
	make -C ./lib/my fclean


re: fclean all

.PHONY: all clean fclean re