# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 14:25:06 by mapoirie          #+#    #+#              #
#    Updated: 2024/03/14 14:09:55 by mapoirie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp PhoneBook.cpp Contact.cpp 
OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

all: $(NAME)

%.o: %.cpp
		${CC} ${CFLAGS} -c $< -o $@

clean:
		rm -f $(OBJS)

fclean:
		rm -f $(NAME)
	
re: fclean
		make all

.PHONY: all clean fclean re