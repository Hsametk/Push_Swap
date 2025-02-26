NAME=push_swap

# Paths
FT_PRINTF_PATH=srcs/library_srcs/printf
FT_PRINTF=$(FT_PRINTF_PATH)/libftprintf.a
LIBFT_PATH=srcs/library_srcs/libft
LIBFT=$(LIBFT_PATH)/libft.a

# Compilation Flags
CC = cc
CFLAGS=-Wall -Wextra -Werror #-fsanitize=address
FT_PRINTF_LIB_FLAGS=-L $(FT_PRINTF_PATH) -lftprintf -I $(FT_PRINTF_PATH)
FT_LIBFT_LIB_FLAGS=-L $(LIBFT_PATH) -lft -I $(LIBFT_PATH)

# Source Files and Objects
SRC=srcs/push_swap.c srcs/arg_checks.c srcs/stack_operations.c srcs/rotations/rotate.c srcs/rotations/reverse_rotate.c
OBJ=$(SRC:.c=.o)

# Targets
all: $(NAME)

# Önce kütüphaneleri derle
libs: $(LIBFT) $(FT_PRINTF)

# Ana program derleme
$(NAME): libs $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(FT_PRINTF_LIB_FLAGS) $(FT_LIBFT_LIB_FLAGS)

# Her .o dosyası için derleme kuralı
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes

$(LIBFT):
	make -C $(LIBFT_PATH)

$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH)

clean:
	$(RM) $(OBJ)
	make -C $(FT_PRINTF_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(FT_PRINTF_PATH) fclean
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re libs
