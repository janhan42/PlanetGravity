# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 15:00:22 by janhan            #+#    #+#              #
#    Updated: 2023/12/20 18:06:39 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		PlanetGravity

CXX				=		c++
CXXFLAGS		=		-I./SFML/include
LDFLAGS			=		-L./SFML/lib -lsfml-window -lsfml-graphics -lsfml-system -Wl,-rpath,./SFML/lib

SRCS_DIR		=		./srcs

OBJ_DIR			=		./OBJ

SRC_FILES		=		$(SRCS_DIR)/GravitySource.cpp		\
						$(SRCS_DIR)/PatycleSource.cpp		\
						$(SRCS_DIR)/Gui.cpp					\
						$(SRCS_DIR)/main.cpp

OBJ_FILES		=		$(SRC_FILES:$(SRCS_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME) : $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean :
	rm -fr $(OBJ_FILES)

fclean : clean
	rm -fr $(NAME)

re	:
	make fclean
	make all

