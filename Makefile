# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 15:00:22 by janhan            #+#    #+#              #
#    Updated: 2023/12/21 01:35:41 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		PlanetGravity

CXX				=		c++
CXXFLAGS		=		-I./SFML/include
LDFLAGS			=		-L./SFML/lib -lsfml-window -lsfml-graphics -lsfml-system -Wl,-rpath,./SFML/lib

SRCS_DIR		=		./srcs

OBJ_DIR			=		./.OBJ

SRC_FILES		=		$(SRCS_DIR)/GravitySource.cpp		\
						$(SRCS_DIR)/PatycleSource.cpp		\
						$(SRCS_DIR)/Gui.cpp					\
						$(SRCS_DIR)/main.cpp

OBJ_FILES		=		$(SRC_FILES:$(SRCS_DIR)/%.cpp=$(OBJ_DIR)/%.o)

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
PURPLE='\033[35m'
BLUE='\033[34m'
DELETELINE='\033[K;

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	@echo $(CURSIVE)$(YELLOW) "   - Making PlanetGravity Game -" $(NONE)
	@$(CXX) $(LDFLAGS) $^ -o $@
	@echo $(CURSIVE)$(YELLOW) "    - Compiling $(NAME) -" $(NONE)
	@echo $(GREEN)"            - Complete -"$(NONE)

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.cpp
	@echo $(CURSIVE)$(YELLOW) "      - Making object files -" $(NONE)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@rm -fr $(OBJ_FILES)
	@echo $(CURSIVE)$(BLUE) "       - clean OBJ files -" $(NONE)

fclean : clean
	@rm -fr $(NAME)
	@echo $(CURSIVE)$(PURPLE)"  - clean PlanetGravity Game file -"$(NONE)

re	:
	@make fclean
	@make all
