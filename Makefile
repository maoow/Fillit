# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: starrit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/27 15:02:31 by starrit           #+#    #+#              #
#    Updated: 2017/03/30 16:58:44 by cbinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_NAME = ft_addtetrilst.c\
	   ft_align.c\
	   ft_bt_count.c\
	   ft_bt_getpos.c\
	   ft_bt_getsize_tab.c\
	   ft_bt_place_tetri.c\
	   ft_check_available_tab.c\
	   ft_check_available_tetri.c\
	   ft_convert.c\
	   ft_extracttetrilst.c\
	   ft_newtetrilst.c\
	   ft_read.c\
	   ft_sqrt.c\
	   ft_malloctetritab.c\
	   ft_setdefinitive.c\
	   ft_tetribacktrack.c\
	   ft_disptetritab.c\
	   ft_bt_remove_tetri.c\
	   ft_bt_checks.c\
	   ft_freelst.c\
	   ft_intracttetrilst.c\
	   fillit.c

SRC_PATH = srcs/

SRCS =  $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJS = ft_addtetrilst.o\
	   ft_align.o\
	   ft_bt_count.o\
	   ft_bt_getpos.o\
	   ft_bt_getsize_tab.o\
	   ft_bt_place_tetri.o\
	   ft_check_available_tab.o\
	   ft_check_available_tetri.o\
	   ft_convert.o\
	   ft_extracttetrilst.o\
	   ft_newtetrilst.o\
	   ft_read.o\
	   ft_sqrt.o\
	   ft_malloctetritab.o\
	   ft_setdefinitive.o\
	   ft_tetribacktrack.o\
	   ft_disptetritab.o\
	   ft_bt_remove_tetri.o\
	   ft_bt_checks.o\
	   ft_freelst.o\
	   ft_intracttetrilst.o\
	   fillit.o


LIB = includes/

all: $(NAME)

$(NAME):
	make re -C includes/libft -f Makefile
	gcc -Wall -Wextra -Werror -c -I $(LIB) $(SRCS) 
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJS) includes/libft/libft.a

clean:
	rm -f $(OBJS)
	make clean -C libft -f Makefile

fclean: clean
	rm -f $(NAME)
	make fclean -C libft -f Makefile

re: fclean all

.PHONY:all clean fclean re
