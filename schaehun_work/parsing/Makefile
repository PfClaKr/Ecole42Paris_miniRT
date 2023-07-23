
NAME		=	miniRT

CC		=	cc

SRC		=	main.c \
			\
			ft_strlen.c \
			ft_strcpy.c \
			ft_strstrip.c \
			ft_strcmp.c \
			ft_split.c \
			ft_cntchar.c \
			tab_to_space.c \
			get_line.c \
			\
			ft_list.c \
			\
			count_double_arr.c \
			free_double_arr.c \
			ft_atoi.c \
			ft_atof.c \
			ft_isint.c \
			ft_isdouble.c \
			\
			parse_get_data.c \
			data_check_common.c \
			data_check_unique.c \
			data_check_scene_obj.c \
			data_check_geo_obj.c \
			data_integrity_check.c \
			\
			data_get_common.c \
			data_get_unique.c \
			\
			parse_geo_obj.c \
			parse_scene_obj.c \
			parse.c \

OBJS		=	${SRC:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

FLAGS		=	-g3 -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

fs:	${OBJS}
	${CC} -fsanitize=address -g3 ${FLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}
	
re:	fclean all


.PHONY:	all clean fclean re

