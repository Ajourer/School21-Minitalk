SRCS = server.c \
		client.c \

NAME1 = server
NAME2 = client

LIB_D = libft/
LIB = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(LIB_D) -I.

all:	$(NAME1) $(NAME2)

$(NAME1): $(LIB_D)$(LIB) server.o minitalk.h
		$(CC) $(CFLAGS) -L./libft -lft server.o -o $(NAME1)

$(NAME2): $(LIB_D)$(LIB) client.o minitalk.h
		$(CC) $(CFLAGS) -L./libft -lft client.o -o $(NAME2)

$(LIB_D)$(LIB) : $(LIB_D)
		$(MAKE) -C $(LIB_D)

clean:
		$(MAKE) -C $(LIB_D) clean
		$(RM) $(LIB_D)$(LIB)
		$(RM) server.o client.o

fclean: clean
		$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
