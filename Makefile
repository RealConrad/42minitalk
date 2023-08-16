# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 14:27:42 by cwenz             #+#    #+#              #
#    Updated: 2023/08/16 16:04:05 by cwenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
CLIENT_NAME		:= client
SERVER_NAME		:= server

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
CLIENT_DIR		:= ./src/client/
SERVER_DIR		:= ./src/server/
ERROR_DIR		:= ./src/error/
UTILS_DIR		:= ./src/utils/

# Source files
CLIENT_FILES	:= client.c
SERVER_FILES	:= server.c
ERROR_FILES		:= error.c
UTIL_FILES		:= utils.c

CLIENT_SRC		+= $(addprefix $(CLIENT_DIR), $(CLIENT_FILES))
SERVER_SRC		+= $(addprefix $(SERVER_DIR), $(SERVER_FILES))

SRC				+= $(addprefix $(ERROR_DIR), $(ERROR_FILES))
SRC				+= $(addprefix $(UTILS_DIR), $(UTIL_FILES))

# Object files
CLIENT_OBJ		:= $(CLIENT_SRC:.c=.o)
SERVER_OBJ		:= $(SERVER_SRC:.c=.o)
SRC_OBJ			:= $(SRC:.c=.o)

# Default makefile target
all: init-submodule $(LIBFT) $(SERVER_NAME) $(CLIENT_NAME)
	
$(LIBFT):
	@$(LIBFT_MAKE)

$(CLIENT_NAME): $(CLIENT_OBJ) $(SRC_OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_OBJ) $(SRC_OBJ) $(LIBFT) -o $(CLIENT_NAME)
	@echo $(GREEN)"Linking $(CLIENT_NAME)"$(DEFAULT);

$(SERVER_NAME): $(SERVER_OBJ) $(SRC_OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_OBJ) $(SRC_OBJ) $(LIBFT) -o $(SERVER_NAME)
	@echo $(GREEN)"Linking $(SERVER_NAME)"$(DEFAULT);

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

init-submodule:
	@if [ -z "$(shell ls -A $(LIBFT_PATH))" ]; then \
		git submodule init $(LIBFT_PATH); \
		git submodule update $(LIBFT_PATH); \
	fi

clean:
	@$(RM) $(SRC_OBJ) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	@$(LIBFT_FCLEAN)
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all init-submodule clean fclean re

# Colours to make it look nice :)
DEFAULT	= "\033[39m"
GREEN	= "\033[32m"
