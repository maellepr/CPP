# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 14:39:20 by mapoirie          #+#    #+#              #
#    Updated: 2024/03/18 16:48:40 by mapoirie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = tests.cpp Account.cpp
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