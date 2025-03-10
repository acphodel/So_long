NAME   			= libftprintf.a
HEADER 			= ft_printf.h
SRCS   			= ft_printf.c printf_char.c printf_string.c printf_Xx.c change_base.c printf_num.c
OBJS   			= $(SRCS:.c=.o)
FLAGS			= -Wall -Wextra -Werror
RMF				= rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)
%.o: %.c
	gcc -c $< -o $@ $(FLAGS)

clean:
	$(RMF) $(OBJS)

fclean: clean
	$(RMF) $(NAME)

re: fclean all

.PHONY: all clean fclean re
