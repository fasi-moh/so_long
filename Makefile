# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 16:32:56 by fasi-moh          #+#    #+#              #
#    Updated: 2021/11/17 16:33:53 by fasi-moh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		so_long.c\
						get_next_line_utils.c\
						get_next_line.c\
						ft_error.c\
						ft_split.c\
						ft_strcat.c\
						ft_affmap.c\
						ft_affgame.c\
						write_error.c\
						toucha_s_d_w.c\
						moove.c\
						end.c\
				
				
												
				
				
				
				
				
				
				
			

OBJS 		= ${SRCS:.c=.o}

UNAME		:= $(shell uname)
PATH_MLX	= mlx
CC 			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all
