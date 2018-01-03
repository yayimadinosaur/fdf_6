# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfung <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/11 14:50:44 by wfung             #+#    #+#              #
#    Updated: 2018/01/02 18:41:40 by wfung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

SRCS	=	main.c\
			parse_fdf.c\
			set_values2.c\
			create_struct.c\
			rotate.c\
			translate.c\
			draw1.c\
			set_slope.c\

OBJ =		${SRCS:.c=.o}

INCLUDE	=	-I fdf.h -L ./libft -lft -L ./minilibx_macos -lmlx\
			-framework OpenGL -framework AppKit\

all: $(NAME)

$(OBJ):
		@$(CC) $(FLAG) -c $(SRCS)

$(NAME): $(OBJ)
		@make all -C libft
		@make all -C minilibx_macos
		@$(CC) $(FLAG) $(INCLUDE) $(OBJ) -o $(NAME)

clean:
		@make clean -C libft
		@make clean -C minilibx_macos
		@/bin/rm -f $(OBJ)

fclean: clean
		@make fclean -C libft
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
