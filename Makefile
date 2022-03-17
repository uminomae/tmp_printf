NAME		:= libftprintf.a
CC			:= cc
RM			:= rm -f
CFLAGS		:= -Wall -Wextra -Werror
SRCS		:= 	ft_printf.c \
				ft_convert_main.c \
				ft_convert01_get_flag.c \
				ft_convert02_get_width.c \
				ft_convert03_spec_char.c \
				ft_convert04_spec_digit.c \
				ft_convert05_to_ascii.c \
				ft_pad2put_main.c \
				ft_pad2put01_precision.c \
				ft_pad2put02_option.c \
				ft_pad2put03_field.c \
				ft_pad2put04_write.c \

OBJS	= $(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs  $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) $(B_OBJS)

fclean:	clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

