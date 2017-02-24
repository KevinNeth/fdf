# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kneth <kneth@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 10:20:20 by kneth             #+#    #+#              #
#    Updated: 2017/02/24 16:50:16 by kneth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCDIR = srcs

SRC_NAME =	fdf.c ft_parsing.c ft_checkmap.c ft_newmap.c ft_painter.c \
			ft_eventmap.c

SRC = $(addprefix ${SRCDIR}/, ${SRC_NAME})

OBJDIR = objs

OBJ = $(addprefix ${OBJDIR}/, $(SRC_NAME:.c=.o))

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLX = minilibx_macos/

FRAMEWORKS = -framework OpenGL -framework AppKit

all:${NAME}

${NAME}: ${OBJ}
		@make -C libft/
		@make -C ${MLX}
		@echo "__/\OOOOOOOOOOOOO\__/\OOOOOOOOOO\_____/\OOOOOOOOOOOOO\_        "
		@echo " _\/\O\///////////__\/\O\////////\O\__\/\O\///////////__       "
		@echo "  _\/\O\_____________\/\O\______\//\O\_\/\O\_____________      "
		@echo "   _\/\OOOOOOOOO\_____\/\O\_______\/\O\_\/\OOOOOOOOO\_____     "
		@echo "    _\/\O\///////______\/\O\_______\/\O\_\/\O\///////______    "
		@echo "     _\/\O\_____________\/\O\_______\/\O\_\/\O\_____________   "
		@echo "      _\/\O\_____________\/\O\_______/\O\__\/\O\_____________  "
		@echo "       _\/\O\_____________\/\OOOOOOOOOOO/___\/\O\_____________ "
		@echo "        _\///______________\////////////_____\///______________"
		@echo "\033[32mIS NOW READY !\033[0m"
		@${CC} ${CFLAGS} -g -I. -Ilibft/includes/ -I${MLX} -Llibft/ -lft \
						-L${MLX} -lmlx ${FRAMEWORKS} -o $@ $^

${OBJDIR}/%.o: ${SRCDIR}/%.c
		@/bin/mkdir -p ${OBJDIR}
		@${CC} ${CFLAGS} -g -I. -Ilibft/includes/ -I${MLX} -c -o $@ $<

clean:
	@echo Clean mlx...
	@make -C ${MLX} clean
	@echo Clean libft...
	@make -C libft/ clean
	@echo Clean objs...
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@echo FClean libft...
	@make -C libft/ fclean
	@echo Clean ${NAME}...
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
