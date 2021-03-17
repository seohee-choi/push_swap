.PHONY: all ch ps gnl libft test clean fclean help bonus rebonus debug objdel
.DEFAULT_GOAL = help

NAME = $(CHECKER) # $(PUSH_SWAP)
CHECKER = checker
PUSH_SWAP = push_swap

# PUSH_SWAP = push_swap

all: gnl libft $(NAME) ## compile the program

ch: gnl libft $(CHECKER)
# ps: gnl libft $(PUSH_SWAP)

CC = gcc
AR = ar
MK = make

CFLAGS = -Wall -Werror -Wextra $(DEBUGF)
LFLAGS = -l$(STACK_OP) -l$(LIBFT) -l$(GNL) -L.
IFLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR)
AFLAGS = -rcus
DEBUGF = -g3 -fsanitize=address
MFLAGS = -C

SRC_DIR = ./src
OBJ_DIR = ./object
INC_DIR = ./include

STACK_OP = stack_op
SO_A = lib$(STACK_OP).a


SO_SRC = \
	ps_init_stack.c \
	ps_init_utils.c \
	ps_node_utils.c \
	ps_operation.c
SO_SRC_DIR = $(SRC_DIR)/$(STACK_OP)/
SO_SRCS = $(addprefix $(SO_SRC_DIR),$(SO_SRC))
SO_SRCS_DIR = $(dir $(SO_SRCS))

SO_OBJ = $(SO_SRC:%.c=%.o)
SO_OBJ_DIR = $(OBJ_DIR)/$(STACK_OP)/
SO_OBJS = $(addprefix $(SO_OBJ_DIR),$(SO_OBJ))
SO_OBJS_DIR = $(dir $(SO_OBJS))

CH_SRC = \
	checker.c
CH_SRC_DIR = $(SRC_DIR)/$(CHECKER)/
CH_SRCS = $(addprefix $(CH_SRC_DIR),$(CH_SRC))
CH_SRCS_DIR = $(dir $(CH_SRCS))

CH_OBJ = $(CH_SRC:%.c=%.o)
CH_OBJ_DIR = $(OBJ_DIR)/$(CHECKER)/
CH_OBJS = $(addprefix $(CH_OBJ_DIR),$(CH_OBJ))
CH_OBJS_DIR = $(dir $(CH_OBJS))


SRCS_DIR = $(SO_SRCS_DIR)
OBJS_DIR = $(SO_OBJ_DIR) $(CH_OBJ_DIR)

# PS_SRC =
# PS_SRC_DIR = ./src/
# PS_SRCS = $(addprefix $(SRC_DIR),$(SRC))

# PS_OBJ = $(SRC:%.c=%.o)
# PS_OBJ_DIR := ./object/
# PS_OBJS = $(addprefix $(OBJ_DIR),$(OBJ))

GNL = gnl
GNL_DIR = ./get_next_line
LIBFT = ft
LIBFT_DIR = ./libft

gnl:
	$(MK) $(MFLAGS) $(GNL_DIR)

libft:
	$(MK) $(MFLAGS) $(LIBFT_DIR)

$(CHECKER): $(CH_OBJS) $(SO_A)
	$(CC) $(CFLAGS) $(LFLAGS) $(IFLAGS) -o $@ $<

$(SO_A): $(SO_OBJS)
	$(AR) $(ARFLAGS) $@ $^

# $(PUSH_SWAP):

$(SO_OBJ_DIR)%.o: $(SO_SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $^

$(CH_OBJ_DIR)%.o: $(CH_SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

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
