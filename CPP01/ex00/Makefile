# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:43:17 by mapoirie          #+#    #+#              #
#    Updated: 2024/03/21 11:15:12 by mapoirie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

INC_PATH = ./include/
INC = -I $(INC_PATH)

SRCS_PATH = ./sources/
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
SRCS = $(addprefix $(SRCS_PATH), $(SRC))

OBJS_PATH = ./objects/
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJS_PATH), $(OBJ))

all: $(OBJS_PATH) $(NAME)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
		${CC} ${CFLAGS} -c $< -o $@ $(INC)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

clean:
		rm -rf $(OBJS_PATH)

fclean:
		rm -rf $(NAME) $(OBJS_PATH)
	
re: fclean
		make all

.PHONY: all clean fclean re