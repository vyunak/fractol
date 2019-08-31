# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/30 13:34:20 by vyunak            #+#    #+#              #
#    Updated: 2019/08/30 13:34:35 by vyunak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = 	color.c       	key_conntin.c 	main_init.c\
		fractol.c     	main.c        	mouse.c\
		key.c         	main_cycle.c  	posix.c
SRCDIR = ./src/
LIBDIR = ./libft/
RWDIR = ./libft/
SRCO = $(addprefix $(SRCDIR), $(SRC:.c=.o))
FLAGS = -framework OpenGL -framework AppKit -lmlx -lpthread
WWE = -Wall -Wextra -Werror -Ofast
O = N
FAST_FLAG = -Ofast
INCDIR = ./src/
INC = $(addprefix $(INCDIR), fractol.h)
LIBINC = $(addprefix $(LIBDIR), libft.h)
LIBFT = $(LIBDIR)libft.a

all: $(NAME)

ifeq ($(O),O)
$(NAME): $(LIBFT) $(SRCO) $(LIBINC) $(INC)
	gcc $(WWE) $(FLAGS) $(FAST_FLAG) -o $(NAME) $(SRCO) -L $(LIBDIR) -lft  -I $(INCDIR) -I $(LIBDIR)

$(LIBFT):
	make -C $(LIBDIR) O=O

$(SRCDIR)%.o: $(SRCDIR)%.c $(LIBINC) $(INC)
	gcc $(WWE) $(FAST_FLAG) -c -o $@ $<  -I $(INCDIR) -I $(LIBDIR)
else
$(NAME): $(LIBFT) $(SRCO) $(LIBINC) $(INC)
	gcc $(WWE) $(FLAGS) -o $(NAME) $(SRCO) -L $(LIBDIR) -lft -I $(INCDIR) -I $(LIBDIR)

$(LIBFT):
	make -C $(LIBDIR)

$(SRCDIR)%.o: $(SRCDIR)%.c $(LIBINC) $(INC)
	gcc $(WWE) -c -o $@ $< -I $(INCDIR) -I $(LIBDIR)
endif

clean:
	make -C $(LIBDIR) clean
	/bin/rm -f $(SRCO)

fclean: clean
	make -C $(LIBDIR) fclean
	/bin/rm -f $(NAME)

re: fclean all
