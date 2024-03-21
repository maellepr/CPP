# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 14:01:18 by mapoirie          #+#    #+#              #
#    Updated: 2024/03/21 14:06:42 by mapoirie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brain

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

all: $(NAME)

%.o: %.cpp
		${CC} ${CFLAGS} -c $< -o $@

clean:
		rm -f $(OBJS)

fclean:
		rm -f $(NAME) $(OBJS)
	
re: fclean
		make all

.PHONY: all clean fclean re