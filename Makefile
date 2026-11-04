# The name of the libft archive
NAME= libftprintf.a

# Compiler + flags for executable
CC= cc
CFLAGS= -Wall -Werror -Wextra

# Compiler + flags for archive
AR= ar
ARFLAGS= rsc

# Source and object directories
SRC_DIR= SRC
OBJ_DIR= OBJ

# List of src files
SRCS=	$(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/ft_putchar_fd.c \
		$(SRC_DIR)/ft_puthexa_fd.c \
		$(SRC_DIR)/ft_putnbr_fd.c \
		$(SRC_DIR)/ft_putstr_fd.c \
		$(SRC_DIR)/ft_putptr_fd.c \
		$(SRC_DIR)/ft_countargs.c \
		$(SRC_DIR)/ft_len.c \
		$(SRC_DIR)/ft_putunbr_fd.c \

# List of obj files
OBJS=	$(OBJ_DIR)/ft_printf.o \
		$(OBJ_DIR)/ft_putchar_fd.o \
		$(OBJ_DIR)/ft_puthexa_fd.o \
		$(OBJ_DIR)/ft_putnbr_fd.o \
		$(OBJ_DIR)/ft_putstr_fd.o \
		$(OBJ_DIR)/ft_putptr_fd.o \
		$(OBJ_DIR)/ft_countargs.o \
		$(OBJ_DIR)/ft_len.o \
		$(OBJ_DIR)/ft_putunbr_fd.o \

# Compile everything
all: $(NAME)

# Compile everything into an archive
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Compile src files into obj files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up obj files
clean:
	rm -f $(OBJS)

# Clean up obj files and archive
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
