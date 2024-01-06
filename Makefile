# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 17:06:41 by dstarov           #+#    #+#              #
#    Updated: 2023/12/03 19:48:14 by dstarov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = srcs
STACK_DIR = $(SRC_DIR)/stack
ALGORITHM_DIR = $(SRC_DIR)/algorithm
UTILS_DIR = $(SRC_DIR)/utils
LIBFT_DIR = $(SRC_DIR)/libft

MAIN_SOURCE = $(SRC_DIR)/main.c
STACK_SOURCES = $(wildcard $(STACK_DIR)/*.c)
ALGORITHM_SOURCES = $(wildcard $(ALGORITHM_DIR)/*.c)
UTILS_SOURCES = $(wildcard $(UTILS_DIR)/*.c)
LIBFT_SOURCES = $(wildcard $(LIBFT_DIR)/*.c)

CFLAGS = -Wall -Wextra -Werror
MY_HEADER = ./includes/

OBJ_DIR = obj
OBJ_STACK = $(addprefix $(OBJ_DIR)/,$(notdir $(STACK_SOURCES:.c=.o)))
OBJ_ALGORITHM = $(addprefix $(OBJ_DIR)/,$(notdir $(ALGORITHM_SOURCES:.c=.o)))
OBJ_UTILS = $(addprefix $(OBJ_DIR)/,$(notdir $(UTILS_SOURCES:.c=.o)))
OBJ_LIBFT = $(addprefix $(OBJ_DIR)/,$(notdir $(LIBFT_SOURCES:.c=.o)))
OBJ_MAIN = $(OBJ_DIR)/main.o

.PHONY: all clean fclean re

all: $(NAME)

define PRINT_SUCCESS
	@printf "\r\033[K\033[0;32mAll objects built successfully!\033[0m\n"
endef

$(OBJ_DIR)/%.o: $(STACK_DIR)/%.c | $(OBJ_DIR)
	@$(call PRINT_PROGRESS,$(STACK_DIR),$2)
	@gcc $(CFLAGS) -c -I $(MY_HEADER) $< -o $@

$(OBJ_DIR)/%.o: $(ALGORITHM_DIR)/%.c | $(OBJ_DIR)
	@$(call PRINT_PROGRESS,$(ALGORITHM_DIR),$2)
	@gcc $(CFLAGS) -c -I $(MY_HEADER) $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIR)
	@$(call PRINT_PROGRESS,$(UTILS_DIR),$2)
	@gcc $(CFLAGS) -c -I $(MY_HEADER) $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c | $(OBJ_DIR)
	@$(call PRINT_PROGRESS,$(LIBFT_DIR),$2)
	@gcc $(CFLAGS) -c -I $(MY_HEADER) $< -o $@

$(OBJ_DIR)/main.o: $(MAIN_SOURCE) | $(OBJ_DIR)
	@$(call PRINT_PROGRESS,$(MAIN_SOURCE),$2)
	@gcc $(CFLAGS) -c -I $(MY_HEADER) $< -o $@

$(NAME): $(OBJ_STACK) $(OBJ_ALGORITHM) $(OBJ_UTILS) $(OBJ_LIBFT) $(OBJ_MAIN)
	@$(call PRINT_SUCCESS)
	@cc $(CFLAGS) -o $(NAME) $(OBJ_STACK) $(OBJ_ALGORITHM) $(OBJ_UTILS) $(OBJ_LIBFT) $(OBJ_MAIN)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
