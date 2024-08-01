# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 14:31:18 by welee             #+#    #+#              #
#    Updated: 2024/08/01 17:20:38 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(BINS_DIR)/fdf
BONUS_NAME = $(BINS_DIR)/fdf_bonus

SRCS_DIR = srcs
OBJS_DIR = objs
INCS_DIR = includes
BINS_DIR = bin
LIBS_DIR = libs
PUBL_DIR = public

# Detect OS and set OS-specific flags
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	MLX_DIR = $(LIBS_DIR)/minilibx_macos
	MLX = $(MLX_DIR)/libmlx.a
	MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	MLX_INC = $(MLX_DIR)
else ifeq ($(UNAME_S),Linux)
	MLX_DIR = $(LIBS_DIR)/minilibx
	MLX = $(MLX_DIR)/libmlx.a
	MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
	MLX_INC = $(MLX_DIR)
endif

LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/bin/libft.a
LIBFT_LIB = -L$(LIBFT_DIR)/bin -lft
LIBFT_INC = $(LIBFT_DIR)/includes

SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCS_DIR) -I$(LIBFT_INC) -I$(MLX_INC)
RM = rm -f

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

# Targets
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) | $(BINS_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX_LIB)

$(BINS_DIR) $(OBJS_DIR):
	@mkdir -p $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
