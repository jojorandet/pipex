NAME = pipex

DIR_BIN		=	./bin
DIR_SRC		=	./src

UNAME := $(shell uname)
CFLAGS = -Wall -Werror -Wextra -g
ifeq ($(UNAME), Darwin)
CFLAGS += -fsanitize=address
endif

SRCS			=	main.c \
					ft_utils.c \
					ft_split.c \
					ft_split_utils.c \
					ft_parsing.c \
					ft_init.c \
					redirection.c \
					ft_error_handling.c 

OBJ				=	$(addprefix $(DIR_BIN)/, $(SRCS:.c=.o))

INCLUDE_FLAGS	=	-I$(DIR_SRC)

all:	$(NAME)

$(NAME): $(OBJ) | $(DIR_BIN)
	@$(CC) $(OBJ) $(CFLAGS) -o $@

$(DIR_BIN)/%.o: $(DIR_SRC)/%.c | $(DIR_BIN)
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(DIR_BIN):
	@mkdir -p $@

clean:
	@rm -rf $(DIR_BIN)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all