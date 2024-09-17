# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 14:31:18 by welee             #+#    #+#              #
#    Updated: 2024/09/17 15:46:01 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(BINS_DIR)/fdf
SRCS = $(wildcard $(SRCS_DIR)/*.c) \
	   $(wildcard $(SRCS_DIR)/color/*.c) \
	   $(wildcard $(SRCS_DIR)/map/*.c) \
	   $(wildcard $(SRCS_DIR)/matrix/*.c) \
	   $(wildcard $(SRCS_DIR)/render/*.c) \
	   $(wildcard $(SRCS_DIR)/utils/*.c) \
	   $(wildcard $(SRCS_DIR)/vector/*.c)
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# Directory Variables -------------------------------------------------------- #
SRCS_DIR = srcs
OBJS_DIR = objs
INCS_DIR = includes
TEST_DIR = tests
DIST_DIR = dist
LIBS_DIR = libs
BINS_DIR = bin
DOCS_DIR = docs
# ---------------------------------------------------------------------------- #

# Library Variables ---------------------------------------------------------- #
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

MLX_DIR = $(LIBS_DIR)/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_LIB = -L$(MLX_DIR) -lmlx -L/usr/X11/include/../lib -lXext -lX11 -lm
MLX_INC = $(MLX_DIR)
# ---------------------------------------------------------------------------- #

# Macro Definitions ---------------------------------------------------------- #
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCS_DIR) -I$(LIBFT_INC) -I$(GET_NEXT_LINE_INC) -I$(FT_PRINTF_INC) -I$(MLX_INC)
LIBC = ar rcs
RM = rm -f
MKDIR = mkdir -p
MAKE = make
CD = cd
CP = cp -r
ECHO = echo
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	SED := sed -i
else ifeq ($(UNAME_S),Darwin)
	SED := sed -i ''
else
	$(error Unsupported OS)
endif
WHOAMI = $(shell whoami)
# ---------------------------------------------------------------------------- #

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

DOXYGEN = doxygen
DOXYGEN_CONF = Doxyfile

# Rules Definitions ---------------------------------------------------------- #
all: $(NAME)

$(NAME): $(LIBFT) $(GET_NEXT_LINE) $(FT_PRINTF) $(MLX) $(OBJS) | $(BINS_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) $(FT_PRINTF_LIB) $(GET_NEXT_LINE_LIB) $(LIBFT_LIB)
	@$(ECHO) "\033[32m$(NAME) compiled\033[0m"

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
	@$(ECHO) "\033[33m$@\033[0m"

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	@$(ECHO) "\033[31m$(NAME) object files removed\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(DIST_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	@$(ECHO) "\033[31m$(NAME) removed\033[0m"

re: fclean all

norm:
	$(NORM) $(NORM_FLAGS) $(SRCS_DIR) $(INCS_DIR)
	@$(ECHO) "\033[32mNorm check completed\033[0m"

tests:
	$(MAKE) -C $(TEST_DIR)
	@$(ECHO) "\033[32mTest completed\033[0m"

doxygen:
	$(DOXYGEN) $(DOXYGEN_CONFIG)
	@$(ECHO) "\033[32mDoxygen generated\033[0m"

dist: fclean
	$(MKDIR) $(DIST_DIR)
	$(CP) $(SRCS_DIR) $(INCS_DIR) $(LIBS_DIR) $(DIST_DIR)
	$(CP) Makefile $(DIST_DIR)
	$(SED) 's|^NAME = $$(BINS_Dcd dIR)/fdf$$|NAME = fdf|' $(DIST_DIR)/Makefile
	$(SED) '/^\$$(NAME):/ s/ | $$(BINS_DIR)//' $(DIST_DIR)/Makefile
	@$(ECHO) "\033[32mDistribution files copied\033[0m"

.PHONY: all clean fclean re norm tests doxygen dist
# ---------------------------------------------------------------------------- #
