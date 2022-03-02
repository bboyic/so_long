# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:11:54 by aconchit          #+#    #+#              #
#    Updated: 2021/11/17 13:05:06 by aconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
DIR = src/
C_F = main.c check.c parsing.c move.c focus.c utils.c \
imgwork.c gnl/get_next_line.c gnl/get_next_line_utils.c
C_FILES = $(addprefix $(DIR), $(C_F))
O_FILES = $(C_FILES:.c=.o)
INCLUDES = includes/
HEADER = $(INCLUDES)main.h $(INCLUDES)get_next_line.h $(INCLUDES)libft.h
FLAGS = -Wall -Wextra -Werror
LMX = -lmlx -framework OpenGL -framework Appkit
CC = gcc -Wall -Wextra -Werror

.c.o: 
	$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES)

all: $(NAME)

$(NAME): $(O_FILES) $(HEADER)
	$(CC) $(FLAGS) $(LMX) -o $@ $(O_FILES) src/libft.a -I $(INCLUDES)

clean:
	rm -rf $(O_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re