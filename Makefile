CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME = libft.a
SRCS	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_strnstr.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_calloc.c ft_memchr.c ft_memcmp.c\
			ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memmove.c\
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strjoin.c ft_substr.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_strtrim.c ft_split.c
#SRC_BONUS = ft_lstlast.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS	= ${SRCS:.c=.o}
#OBJ_BONUS = $(SRC_BONUS:.c=.o)
LIBC	= ar rc
RM 		= rm -f

all: $(NAME)

$(NAME): ${OBJS}
		${LIBC} ${NAME} ${OBJS}
		
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

#bonus: ${OBJ_BONUS}
#	${LIBC} ${NAME} ${OBJ_BONUS}

clean:
	${RM} ${OBJS} ${OBJ_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all
