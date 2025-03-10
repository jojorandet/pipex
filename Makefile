NAME = pipex

DIR_BIN		=	./bin
DIR_SRC		=	./src
DIR_LIB		=	$(DIR_SRC)/lib

UNAME := $(shell uname)
CFLAGS = -Wall -Werror -Wextra -g
ifeq ($(UNAME), Darwin)
CFLAGS += -fsanitize=address
endif

vpath %.c $(DIR_SRC):$(DIR_SRC)/lib
vpath %.h $(DIR_SRC):$(DIR_SRC)

SRCS 	= 	main.c \
			struct_init.c \
			handle_heredoc.c \
			here_doc_init.c \
			init_pipex.c \
			find_command_path.c \
			ft_error_handling.c \
			execute_command.c \
			ft_string_utils.c \
			clean_string_array.c \
			ft_split.c \
			ft_calloc.c \
			ft_strndup.c
					
OBJ				=	$(addprefix $(DIR_BIN)/, $(SRCS:.c=.o))

INCLUDE_FLAGS	=	-I$(DIR_SRC) -I$(DIR_LIB)

all:	$(NAME)

$(NAME): $(OBJ) | $(DIR_BIN)
	@$(CC) $(OBJ) $(CFLAGS) -o $@

$(DIR_BIN)/%.o: %.c | $(DIR_BIN)
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(DIR_BIN):
	@mkdir -p $@

clean:
	@rm -rf $(DIR_BIN)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all