# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mickert <mickert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 15:40:11 by mickert           #+#    #+#              #
#    Updated: 2023/12/12 16:41:48 by mickert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
# CFLAGS = -fsanitize=address -Wunreachable-code

SRC = source/pipex.c source/utils.c

ODIR = objectives
OBJ = $(SRC:source/%.c=$(ODIR)/%.o)

HEADER = ./includes/pipex.h
NAME = ./pipex

LIBFTDIR = ./source/libft
LIBFT = $(LIBFTDIR)/libft.a
LIBFT_OBJDIR = $(LIBFTDIR)/objectives
INC = -I ./includes -I $(LIBFTDIR)/includes
VPATH = source source/libft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INC) -o $(NAME)

$(LIBFT): | $(LIBFT_OBJDIR)
	$(MAKE) -C $(LIBFTDIR)

$(ODIR)/%.o: source/%.c $(HEADER) | $(ODIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(ODIR):
	@mkdir -p $@

$(LIBFT_OBJDIR):
	@mkdir -p $@

clean:
	rm -f $(ODIR)/*.o
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
