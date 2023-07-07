# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychun <ychun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 06:53:45 by ychun             #+#    #+#              #
#    Updated: 2023/05/29 06:59:30 by ychun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRCS = main.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

LD_FLAGS = -L libft -L mlx
MLX_FLAGS = -lm -lmlx -lXext -lX11
HEAD = -I includes -I libft -I mlx

CC = gcc
CFLAGS = -g3 #-fsanitize=address -g3 #-Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	make -C libft
	make -C mlx
	${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all : ${NAME}

clean :
	make clean -C libft
	make clean -C mlx
	${RM} ${OBJS}

fclean : clean
	make fclean -C libft
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re