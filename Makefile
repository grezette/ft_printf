NAME		=	libftprintf.a

LIBFT		=	libft/libft.a

LIBFT_DIR	=	libft

SRCS		=	./srcs/ft_printf.c \
				./srcs/ft_pars_flag.c \
				./srcs/ft_converters.c \
				./srcs/ft_conv_diuxx.c \
			
OBJS		=	${SRCS:.c=.o}

INC_PATH	=	-I./includes

CC		=	gcc

FLAGS		=	-Wall -Wextra -Werror

.c.o:			${SRCS} ${SRCS_BONUS}
			${CC} ${FLAGS} ${INC_PATH} -c $<  -o ${<:.c=.o}

all:			$(NAME)

$(NAME):	$(LIBFT) ${OBJS}
			ar rc ${NAME} ${OBJS}

$(LIBFT):	
			make bonus -C $(LIBFT_DIR)
			cp $(LIBFT) $(NAME)


clean:		
			make clean -C $(LIBFT_DIR)
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			rm -f ${NAME}

re:			fclean all
