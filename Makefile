NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

SRCS		= ft_printf.c \
			  ft_print_text.c \
			  ft_print_nums.c \
			  ft_print_hex.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re