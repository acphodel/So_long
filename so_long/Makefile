NAME = so_long

SRCS = get_next_line.c \
	   valid_borders.c \
	   validation.c \
	   reading.c \
	   testing.c \
	   testing1.c\
	   freeing.c\
	   validation_shortage.c\
	   trim_back.c\
	   mlx.c\
	   mlx1.c\
	   mlx_anim.c\

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm
FLAGS = -Wall -Wextra -Werror -Ift_printf -Lft_printf -lftprintf #-g3 -fsanitize=address
GLAGS = -Wall -Wextra -Werror -Ilibft -Llibft -lft -g

all: $(NAME)

$(NAME): $(OBJS)
		make -s -C ft_printf
		make -s -C libft
		$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -Lft_printf -lftprintf $(LDFLAGS) -o $(NAME)

%.o: %.c so_long.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -s -C ft_printf
	make clean -s -C libft

fclean: clean
	make fclean -s -C ft_printf
	make fclean -s -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re