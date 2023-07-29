# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychun <ychun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 06:53:45 by ychun             #+#    #+#              #
#    Updated: 2023/07/29 15:15:58 by ychun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRCS =	main.c \
		\
		src/init/init_objects.c \
		src/init/init_mlx.c \
		src/init/init_ray.c \
		\
		src/list/ft_list.c \
		\
		src/parsing/parse_get_data.c \
		src/parsing/data_check_common.c \
		src/parsing/data_check_unique.c \
		src/parsing/data_check_scene_obj.c \
		src/parsing/data_check_geo_obj.c \
		src/parsing/data_integrity_check.c \
		src/parsing/filename_check.c \
		src/parsing/data_get_common.c \
		src/parsing/data_get_unique.c \
		src/parsing/parse_geo_obj.c \
		src/parsing/parse_scene_obj.c \
		src/parsing/parse.c \
		\
		src/raytracing/raytracing.c \
		src/raytracing/hit_sphere.c \
		src/raytracing/hit_plane.c \
		src/raytracing/hit_cylinder.c \
		src/raytracing/light_model.c \
		src/raytracing/light_model_phong.c \
		\
		src/string/ft_strlen.c \
		src/string/ft_strcpy.c \
		src/string/ft_strrchr.c \
		src/string/ft_strstrip.c \
		src/string/ft_strcmp.c \
		src/string/ft_split.c \
		src/string/ft_cntchar.c \
		src/string/tab_to_space.c \
		src/string/get_line.c \
		\
		src/utils/count_double_arr.c \
		src/utils/free_double_arr.c \
		src/utils/ft_atoi.c \
		src/utils/ft_atof.c \
		src/utils/ft_isint.c \
		src/utils/ft_error.c \
		src/utils/ft_isdouble.c \
		src/utils/v_utils1.c \
		src/utils/v_utils2.c \
		src/utils/v_utils3.c \
		src/utils/get_tan.c \
		src/utils/ft_clamp.c \
		src/utils/get_color.c \
		src/utils/mlx_utils.c


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