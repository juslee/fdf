# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 14:31:18 by welee             #+#    #+#              #
#    Updated: 2024/08/11 21:03:06 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(BINS_DIR)/fdf
BONUS_NAME = $(BINS_DIR)/fdf_bonus

SRCS = $(wildcard $(SRCS_DIR)/*.c) \
	   $(wildcard $(SRCS_DIR)/parser/*.c) \
	   $(wildcard $(SRCS_DIR)/render/*.c) \
	   $(wildcard $(SRCS_DIR)/utils/*.c)
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

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
	MLX_DIR = $(LIBS_DIR)/minilibx-linux
	MLX = $(MLX_DIR)/libmlx.a
	MLX_LIB = -L$(MLX_DIR) -lmlx -L/usr/X11/include/../lib -lXext -lX11 -lm
	MLX_INC = $(MLX_DIR)
endif

LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/bin/libft.a
LIBFT_LIB = -L$(LIBFT_DIR)/bin -lft
LIBFT_INC = $(LIBFT_DIR)/includes

GET_NEXT_LINE_DIR = $(LIBS_DIR)/get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/bin/libgnl.a
GET_NEXT_LINE_LIB = -L$(GET_NEXT_LINE_DIR)/bin -lgnl
GET_NEXT_LINE_INC = $(GET_NEXT_LINE_DIR)/includes

FT_PRINTF_DIR = $(LIBS_DIR)/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/bin/libftprintf.a
FT_PRINTF_LIB = -L$(FT_PRINTF_DIR)/bin -lftprintf
FT_PRINTF_INC = $(FT_PRINTF_DIR)/includes

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCS_DIR) -I$(LIBFT_INC) -I$(GET_NEXT_LINE_INC) -I$(FT_PRINTF_INC) -I$(MLX_INC)
RM = rm -f
MKDIR = mkdir -p

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

# Targets
all: $(NAME)

$(NAME): $(LIBFT) $(GET_NEXT_LINE) $(FT_PRINTF) $(MLX) $(OBJS) | $(BINS_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) $(FT_PRINTF_LIB) $(GET_NEXT_LINE_LIB) $(LIBFT_LIB)

$(BINS_DIR):
	$(MKDIR) $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GET_NEXT_LINE):
	$(MAKE) -C $(GET_NEXT_LINE_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

norm:
	$(NORM) $(NORM_FLAGS) $(SRCS_DIR) $(INCS_DIR)

.PHONY: all clean fclean re norm
