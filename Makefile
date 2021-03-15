# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epilar <epilar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 16:09:31 by epilar            #+#    #+#              #
#    Updated: 2020/12/12 16:01:50 by epilar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

SRC = ft_printf.c\
		parser.c\
		utils/initstruct.c\
		utils/clearstruct.c\
		utils/printwidth.c\
		utils/getrank.c\
		utils/checknegwidth.c\
		types/ifchar.c\
		types/ifstring.c\
		types/ifpointer.c\
		types/ifdecint.c\
		types/ifunsign.c\
		types/ifhex.c\
		types/ifpercent.c

OBJ = $(patsubst %.c, %.o, $(SRC))

D_FILES = $(patsubst %.c, %.d, $(SRC))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C ./libft
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	gcc $(FLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean :
	$(MAKE) clean -C ./libft
	@rm -f $(OBJ) $(D_FILES)

fclean : clean
	$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re
