# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 14:14:34 by mapoirie          #+#    #+#              #
#    Updated: 2024/03/22 14:28:41 by mapoirie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = weapon

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -std=c++98

INC_PATH = ./includes/
INC = -I $(INC_PATH)

SRCS_PATH = ./sources/
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
SRCS = $(addprefix $(SRCS_PATH), $(SRC))

OBJS_PATH = ./objects/
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJS_PATH), $(OBJ))

DEPS = $(OBJS:.o=.d)

all: $(OBJS_PATH) $(NAME)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
		${CXX} ${CXXFLAGS} -c $< -o $@ $(INC)

$(NAME) : $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(INC)

-include $(DEPS)

clean:
		rm -rf $(OBJS_PATH)

fclean:
		rm -rf $(NAME) $(OBJS_PATH)
	
re: fclean
		make all

.PHONY: all clean fclean re