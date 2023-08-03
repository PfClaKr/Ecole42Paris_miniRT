# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychun <ychun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 06:53:45 by ychun             #+#    #+#              #
#    Updated: 2023/08/03 02:20:18 by ychun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
NAME_BONUS = miniRT_bonus
VPATH = src/ src/init/ src/list/ src/parsing/ src/raytracing/ src/string/ src/utils/ \
		src_bonus/ src_bonus/init/ src_bonus/list/ src_bonus/parsing/ \
		src_bonus/raytracing/ src_bonus/string/ src_bonus/utils/

SRCS =	main.c \
		\
		init_objects.c \
		init_mlx.c \
		init_ray.c \
		\
		ft_list.c \
		\
		parse_get_data.c \
		data_check_common.c \
		data_check_unique.c \
		data_check_scene_obj.c \
		data_check_geo_obj.c \
		data_integrity_check.c \
		filename_check.c \
		data_get_common.c \
		data_get_unique.c \
		parse_geo_obj.c \
		parse_scene_obj.c \
		parse.c \
		\
		raytracing.c \
		hit_sphere.c \
		hit_plane.c \
		hit_cylinder.c \
		light_model.c \
		light_model_phong.c \
		\
		ft_strlen.c \
		ft_strcpy.c \
		ft_strrchr.c \
		ft_strstrip.c \
		ft_strcmp.c \
		ft_split.c \
		ft_cntchar.c \
		tab_to_space.c \
		get_line.c \
		\
		count_double_arr.c \
		free_double_arr.c \
		ft_atoi.c \
		ft_atof.c \
		ft_isint.c \
		ft_error.c \
		ft_isdouble.c \
		v_utils1.c \
		v_utils2.c \
		v_utils3.c \
		get_tan.c \
		ft_clamp.c \
		get_color.c \
		mlx_utils.c

SRCS_BONUS = main_bonus.c \
		\
		init_objects_bonus.c \
		init_mlx_bonus.c \
		init_ray_bonus.c \
		\
		ft_list_bonus.c \
		\
		parse_get_data_bonus.c \
		data_check_common_bonus.c \
		data_check_texture_bonus.c \
		data_check_unique_bonus.c \
		data_check_scene_obj_bonus.c \
		data_check_geo_obj_bonus.c \
		data_integrity_check_bonus.c \
		filename_check_bonus.c \
		data_get_common_bonus.c \
		data_get_texture_bonus.c \
		data_get_unique_bonus.c \
		parse_geo_obj_bonus.c \
		parse_scene_obj_bonus.c \
		parse_bonus.c \
		\
		raytracing_bonus.c \
		hit_sphere_bonus.c \
		hit_plane_bonus.c \
		hit_cylinder_bonus.c \
		hit_cone_bonus.c \
		hit_cube_bonus.c \
		light_model_bonus.c \
		light_model_phong_bonus.c \
		set_obj_color_bonus.c \
		set_obj_mapping_bonus.c \
		get_uv_value_bonus.c \
		\
		ft_strlen_bonus.c \
		ft_strcpy_bonus.c \
		ft_strrchr_bonus.c \
		ft_strstrip_bonus.c \
		ft_strcmp_bonus.c \
		ft_split_bonus.c \
		ft_cntchar_bonus.c \
		tab_to_space_bonus.c \
		get_line_bonus.c \
		\
		count_double_arr_bonus.c \
		free_double_arr_bonus.c \
		ft_atoi_bonus.c \
		ft_atof_bonus.c \
		ft_isint_bonus.c \
		ft_error_bonus.c \
		ft_isdouble_bonus.c \
		v_utils1_bonus.c \
		v_utils2_bonus.c \
		v_utils3_bonus.c \
		v_utils4_bonus.c \
		get_tan_bonus.c \
		get_rand_num_bonus.c \
		ft_clamp_int_bonus.c \
		ft_clamp_double_bonus.c \
		get_color_bonus.c \
		mlx_utils_bonus.c

OBJDIR = .obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJDIR)/%.o)

RM = rm -rf

LD_FLAGS = -L mlx
MLX_FLAGS = -lm -lmlx -lXext -lX11
HEAD = -I includes -I mlx

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

${OBJDIR}/%.o : %.c | $(OBJDIR)
	${CC} ${CFLAGS} ${HEAD} -c $< -o $@

$(NAME) : ${OBJS}
	make -C mlx
	${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} ${MLX_FLAGS}

$(OBJDIR) :
	mkdir -p $@

all : ${NAME}

bonus : $(NAME_BONUS)

$(NAME_BONUS) : ${OBJS_BONUS}
	make -C mlx
	${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS_BONUS} -o ${NAME_BONUS} ${MLX_FLAGS}

clean :
	make clean -C mlx
	${RM} ${OBJDIR}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY : all clean fclean re bonus
