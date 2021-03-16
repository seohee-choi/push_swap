.PHONY: all gnl libft test clean fclean help bonus rebonus debug objdel
.DEFAULT_GOAL = help

NAME = $(CHECKER) $(PUSH_SWAP)
CHECKER = checker
# PUSH_SWAP = push_swap

all: gnl libft $(NAME) ## compile the program

CC = gcc
AR = ar
MK = make

CFLAGS = -Wall -Werror -Wextra $(DEBUGF)
LFLAGS = -lgnl -lft -L./include
AFLAGS = -rcus
DEBUGF = -g3 -fsanitize=address
MFLAGS = -C

SRC =
SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR),$(SRC))

OBJ = $(SRC:%.c=%.o)
OBJ_DIR := ./object/
OBJS = $(addprefix $(OBJ_DIR),$(OBJ))
OJBS_DIR = $(dir $(OBJS))

# INC = minishell.h
# INC_DIR = ./include/
# INCS = $(addprefix $(INC_DIR),$(INC))

GNL = libgnl.a
GNL_DIR = ./get_next_line
LIBFT = libft.a
LIBFT_DIR = ./libft

gnl:
	$(MK) $(MFLAGS) $(GNL_DIR)

libft:
	$(MK) $(MFLAGS) $(LIBFT_DIR)

$(NAME): $(OBJS) | $(OBJ_DIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean: ## delete all files compiled except for executable
	rm -rf $(OBJ_DIR) $(GNL) $(LIBFT)
	$(MK) clean $(MFLAGS) $(GNL_DIR)
	$(MK) clean $(MFLAGS) $(LIBFT_DIR)

fclean: clean ## delete all files compiled including executable
	rm -rf $(NAME)

re: fclean all ## delete all files compiled and recompile

debug: objdel all

objdel:
	rm -rf $(OBJ_DIR)

help: ## show all Makefile command
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
