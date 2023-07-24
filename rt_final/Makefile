# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychun <ychun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 06:53:45 by ychun             #+#    #+#              #
#    Updated: 2023/07/24 23:55:00 by ychun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRCS =	main.c \
		\
		init/init_objects.c \
		init/init_mlx.c \
		\
		list/ft_list.c \
		\
		parsing/parse_get_data.c \
		parsing/data_check_common.c \
		parsing/data_check_unique.c \
		parsing/data_check_scene_obj.c \
		parsing/data_check_geo_obj.c \
		parsing/data_integrity_check.c \
		parsing/data_get_common.c \
		parsing/data_get_unique.c \
		parsing/parse_geo_obj.c \
		parsing/parse_scene_obj.c \
		parsing/parse.c \
		\
		raytracing/prep_rt.c \
		raytracing/raytracing.c \
		raytracing/hit_sphere.c \
		\
		string/ft_strlen.c \
		string/ft_strcpy.c \
		string/ft_strstrip.c \
		string/ft_strcmp.c \
		string/ft_split.c \
		string/ft_cntchar.c \
		string/tab_to_space.c \
		string/get_line.c \
		\
		utils/count_double_arr.c \
		utils/free_double_arr.c \
		utils/ft_atoi.c \
		utils/ft_atof.c \
		utils/ft_isint.c \
		utils/ft_error.c \
		utils/ft_isdouble.c \
		utils/v_utils1.c \
		utils/v_utils2.c \
		utils/v_utils3.c \
		utils/get_tan.c \
		utils/ft_clamp.c \
		utils/get_color.c \
		utils/mlx_utils.c


OBJS = $(SRCS:.c=.o)
#ODIR        := ./obj
#OBJS        := $(addprefix $(ODIR)/,$(SRC:.c=.o))

RM = rm -rf

LD_FLAGS = -L mlx
MLX_FLAGS = -lm -lmlx -lXext -lX11
HEAD = -I includes -I mlx

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

.c.o :
#${ODIR}/%.o : %.c
#${CC} ${CFLAGS} ${HEAD} -o $@ -c $<
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME) : ${ODIR} ${OBJS}
	make -C mlx
	${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} ${MLX_FLAGS}

$(ODIR) :
	mkdir -p $@

all : ${NAME}

clean :
	make clean -C mlx
	${RM} ${OBJS} ${ODIR}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re