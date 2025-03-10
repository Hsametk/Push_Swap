NAME = push_swap

# Paths
FT_PRINTF_PATH = library_srcs/printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a
LIBFT_PATH = library_srcs/libft
LIBFT = $(LIBFT_PATH)/libft.a

# Compilation Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
INCLUDES = -I includes -I $(FT_PRINTF_PATH) -I $(LIBFT_PATH)
FT_PRINTF_LIB_FLAGS = -L $(FT_PRINTF_PATH) -lftprintf
FT_LIBFT_LIB_FLAGS = -L $(LIBFT_PATH) -lft
RM = rm -f

# Source Files
SRC = push_swap.c \
      arg_checks.c \
      stack_operations.c \
      rotations/rotate.c \
      rotations/reverse_rotate.c \
      rotations/push.c \
      rotations/swap.c \
      sorting_algorithms/radix_sort.c \
      sorting_algorithms/short_shorting.c

# Object Files
OBJ = push_swap.o \
      arg_checks.o \
      stack_operations.o \
      rotations/rotate.o \
      rotations/reverse_rotate.o \
      rotations/push.o \
      rotations/swap.o \
      sorting_algorithms/radix_sort.o \
      sorting_algorithms/short_shorting.o

# Targets
all: $(NAME)

libs: $(LIBFT) $(FT_PRINTF)

$(NAME): libs $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(FT_PRINTF_LIB_FLAGS) $(FT_LIBFT_LIB_FLAGS)

# Pattern rule for root-level .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Pattern rule for files in srcs/rotations/
srcs/rotations/%.o: srcs/rotations/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_PATH)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re libs