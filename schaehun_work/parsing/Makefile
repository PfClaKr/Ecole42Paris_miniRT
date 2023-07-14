
NAME		=	miniRT

CC		=	cc

SRC		=	main.c \
			ft_strlen.c \
			ft_strcpy.c \
			ft_strstrip.c \
			ft_strcmp.c \
			ft_split.c \
			tab_to_space.c \
			get_line.c \
			free_double_arr.c \

OBJS		=	${SRC:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

FLAGS		=	#-Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}
	
re:	fclean all


.PHONY:	all clean fclean re

