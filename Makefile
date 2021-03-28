.PHONY: all ch ps gnl libft test clean fclean help bonus rebonus debug objdel
# .DEFAULT_GOAL = help

NAME = $(CHECKER) $(PUSH_SWAP)
BONUS = $(CHECKER_B) $(PUSH_SWAP_B)
CHECKER = checker
CHECKER_B = checker_bonus
PUSH_SWAP = push_swap
PUSH_SWAP_B = push_swap_bonus

all: gnl libft $(NAME) ## compile the program
bonus: gnl libft $(BONUS)

ch: gnl libft $(CHECKER)
ps: gnl libft $(PUSH_SWAP)

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
	so_init_stack.c \
	so_init_utils.c \
	so_node_utils.c \
	so_operate_push.c \
	so_operate_rotate.c \
	so_operate_rrotate.c \
	so_operate_swap.c \
	so_option_checker.c \
	so_print_stack.c \
	so_push_pop_rotate.c \
	so_set_two_stacks.c
SO_SRC_DIR = $(SRC_DIR)/$(STACK_OP)/
SO_SRCS = $(addprefix $(SO_SRC_DIR),$(SO_SRC))
SO_SRCS_DIR = $(dir $(SO_SRCS))

SO_OBJ = $(SO_SRC:%.c=%.o)
SO_OBJ_DIR = $(OBJ_DIR)/$(STACK_OP)/
SO_OBJS = $(addprefix $(SO_OBJ_DIR),$(SO_OBJ))
SO_OBJS_DIR = $(dir $(SO_OBJS))

CH_SRC = \
	ch_do_operation.c \
	ch_result_check.c \
	checker.c
CH_SRC_B = \
	ch_do_operation.c \
	ch_option_bonus.c \
	ch_result_check.c \
	checker_bonus.c
CH_SRC_DIR = $(SRC_DIR)/$(CHECKER)/
CH_SRCS = $(addprefix $(CH_SRC_DIR),$(CH_SRC))
CH_SRCS_B = $(addprefix $(CH_SRC_DIR),$(CH_SRC_B))
CH_SRCS_DIR = $(dir $(CH_SRCS))

CH_OBJ = $(CH_SRC:%.c=%.o)
CH_OBJ_B = $(CH_SRC_B:%.c=%.o)
CH_OBJ_DIR = $(OBJ_DIR)/$(CHECKER)/
CH_OBJS = $(addprefix $(CH_OBJ_DIR),$(CH_OBJ))
CH_OBJS_B = $(addprefix $(CH_OBJ_DIR),$(CH_OBJ_B))
CH_OBJS_DIR = $(dir $(CH_OBJS))

SRCS_DIR = $(SO_SRCS_DIR)
OBJS_DIR = $(SO_OBJ_DIR) $(CH_OBJ_DIR)

PS_SRC = \
	ps_init_list.c \
	ps_print_register.c \
	ps_register_operation.c \
	ps_simulator_few.c \
	ps_simulator.c \
	ps_simulator_utils.c \
	ps_size_five.c \
	ps_size_three.c \
	push_swap.c \
	quick_sort.c
PS_SRC_B = \
	ps_init_list.c \
	ps_option_bonus.c \
	ps_print_register_bonus.c \
	ps_register_operation_bonus.c \
	ps_simulator_few.c \
	ps_simulator.c \
	ps_simulator_utils.c \
	ps_size_five.c \
	ps_size_three.c \
	push_swap_bonus.c \
	quick_sort.c
PS_SRC_DIR = $(SRC_DIR)/$(PUSH_SWAP)/
PS_SRCS = $(addprefix $(PS_SRC_DIR),$(PS_SRC))
PS_SRCS_B = $(addprefix $(PS_SRC_DIR),$(PS_SRC_B))

PS_OBJ = $(PS_SRC:%.c=%.o)
PS_OBJ_B = $(PS_SRC_B:%.c=%.o)
PS_OBJ_DIR = $(OBJ_DIR)/$(PUSH_SWAP)/
PS_OBJS = $(addprefix $(PS_OBJ_DIR),$(PS_OBJ))
PS_OBJS_B = $(addprefix $(PS_OBJ_DIR),$(PS_OBJ_B))

GNL = gnl
GNL_DIR = ./get_next_line
LIBFT = ft
LIBFT_DIR = ./libft

gnl:
	$(MK) $(MFLAGS) $(GNL_DIR)

libft:
	$(MK) $(MFLAGS) $(LIBFT_DIR)

$(SO_A): $(SO_OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(CHECKER): $(CH_OBJS) $(SO_A)
	$(CC) $(CFLAGS) $(LFLAGS) $(IFLAGS) -o $@ $(CH_OBJS)

$(CHECKER_B): $(CH_OBJS_B) $(SO_A)
	$(CC) $(CFLAGS) $(LFLAGS) $(IFLAGS) -o $@ $(CH_OBJS_B)

$(PUSH_SWAP): $(PS_OBJS) $(SO_A)
	$(CC) $(CFLAGS) $(LFLAGS) $(IFLAGS) -o $@ $(PS_OBJS)

$(PUSH_SWAP_B): $(PS_OBJS_B) $(SO_A)
	$(CC) $(CFLAGS) $(LFLAGS) $(IFLAGS) -o $@ $(PS_OBJS_B)

$(SO_OBJ_DIR)%.o: $(SO_SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $^

$(CH_OBJ_DIR)%.o: $(CH_SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $^

$(PS_OBJ_DIR)%.o: $(PS_SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $^

clean: ## delete all files compiled except for executable
	rm -rf $(OBJ_DIR) lib$(GNL).a lib$(LIBFT).a $(SO_A)
	$(MK) clean $(MFLAGS) $(GNL_DIR)
	$(MK) clean $(MFLAGS) $(LIBFT_DIR)

fclean: clean ## delete all files compiled including executable
	rm -rf $(NAME) $(BONUS)

re: fclean all ## delete all files compiled and recompile

debug: objdel all

objdel:
	rm -rf $(OBJ_DIR)

help: ## show all Makefile command
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
