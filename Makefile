# -*- MakeFile -*-

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -c
INCLUDES = -I$(wildcard *.h) -Ilibft/libft.h
OFILES = $(patsubst %.c, %.o, $(wildcard *.c))
LIBFT = ./libft
all: $(NAME)
$(NAME): $(OFILES)
	Make bonus --directory=$(LIBFT)
	cp libft/libft.a $(NAME)
	ar -crs $(NAME) $(OFILES) 

%.o: %.c $(INCLUDES)
	$(CC) $(FLAGS) $< $(INCLUDES)

clean:
	make clean --directory=$(LIBFT)
	rm -rf $(OFILES)

fclean:
	make fclean --directory=$(LIBFT)
	rm -rf $(OFILES) $(NAME)

re: fclean all