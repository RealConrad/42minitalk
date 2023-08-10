# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 14:27:42 by cwenz             #+#    #+#              #
#    Updated: 2023/08/10 16:31:55 by cwenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME			:= minitalk

# Compiler flags
CC 				:= cc
CFLAGS			:= -Wall -Werror -Wextra
INCLUDES		:= -I./includes

# Remove command
RM				:= rm -f

# Libraries
LIBFT_PATH		:= ./libraries/42c-library
LIBFT			:= $(LIBFT_PATH)/libft.a
LIBFT_MAKE		:= make -C $(LIBFT_PATH)
LIBFT_FCLEAN	:= make fclean -C $(LIBFT_PATH)

# Source file directories
SRC_DIR			:= ./src/

# Source files
SRC_FILES		:= main.c

SRC				+= $(addprefix $(SRC_DIR), $(SRC_FILES))

# Object files
OBJ				:= $(SRC:.c=.o)

# Default makefile target
all: init-submodule $(NAME)

$(NAME): $(OBJ)
	@$(LIBFT_MAKE)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)
	@echo $(GREEN)"Linking $(NAME)"$(DEFAULT);

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

init-submodule:
	@if [ -z "$(shell ls -A $(LIBFT_PATH))" ]; then \
		git submodule init $(LIBFT_PATH); \
		git submodule update $(LIBFT_PATH); \
	fi

clean:
	@$(RM) $(OBJ)

fclean: clean
	@(LIBFT_FCLEAN)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all init-submodule clean fclean re

# Colours to make it look nice :)
DEFAULT	= "\033[39m"
GREEN	= "\033[32m"
