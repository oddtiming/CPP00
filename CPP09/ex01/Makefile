NAME	=	RPN

SHELL	=	bash

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR) -g

CFILES	=	main.cpp \

INCFILES	=	RPN.hpp \

INC_DIR			= ./includes
INCS			= $(addprefix $(INC_DIR)/, $(INCFILES))

SRC_DIR			= ./srcs
SRCS			= $(addprefix $(SRC_DIR)/, $(CFILES))

OBJ_DIR			= ./obj
OBJS			= $(addprefix $(OBJ_DIR)/, $(CFILES:.cpp=.o))

RM_OBJS			=	rm -rf $(OBJ_DIR)
RM_EXE			=	rm -f $(NAME)

GREEN		=	\033[0;32m
CYAN		=	\033[0;36m
RED			=	\033[0;31m
UYELLOW		=	\033[4;33m
RESET_COL	=	\033[0m

# Compilation rules #

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp $(INCS)
	@printf "$(CYAN)%-30s-->%30s $(RESET_COL)\n" $< $@
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	pretty_print $(OBJ_DIR) $(OBJS)
	@echo -e "\n$(CYAN)>>>>>>>> Compiling into executable $(UYELLOW)./$(NAME)$(RESET_COL)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Commands #

all: $(NAME)
	@if [ -e $(NAME) ]; then \
		echo -e "$(GREEN)>>>>>>>> Compilation successful\n>>>>>>>>$(RESET_COL)"; \
	else \
		echo -e "$(RED)>>>>>>>> Compilation failed\n>>>>>>>>$(RESET_COL)"; \
	fi

pretty_print: 
	@echo -e "\n--------------------- $(NAME) ---------------------"

clean:
	@echo -e "$(RED)>>>>>>>> Deleting obj files$(RESET_COL)"
	@$(RM_OBJS)

fclean:	clean
	@echo -e "$(RED)>>>>>>>> Deleting ./$(NAME) $(RESET_COL)"
	@$(RM_EXE)

re:	fclean all

run: all
	@./$(NAME) input.txt

.PHONY: all clean fclean re pretty_print run
