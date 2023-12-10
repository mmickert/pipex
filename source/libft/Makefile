# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mickert <mickert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 17:45:12 by mickert           #+#    #+#              #
#    Updated: 2023/12/06 17:01:35 by mickert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = ft_strlen.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c \
ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_toupper.c ft_strncmp.c ft_strlcat.c ft_tolower.c ft_strchr.c ft_strrchr.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_calloc.c ft_putchar_fd.c ft_striteri.c ft_strmapi.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_strtrim.c ft_itoa.c ft_split.c ft_lstadd_front.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c ft_printf.c ft_put.c ft_puthex_fd.c 

OBJDIR = objectives
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
NAME = libft.a
# NAME = ./a.out

# Bon_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
# ft_lstclear.c ft_lstiter.c ft_lstmap.c 

# Bon_OBJ = $(Bon_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@mkdir -p $(OBJDIR)
	ar	-rcs	$(NAME)	$(OBJ) 
# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -o $@

# bonus: $(Bon_OBJ)
# 	ar	-rcs	$(NAME)	$(Bon_OBJ)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re