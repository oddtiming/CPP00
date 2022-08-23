NAME	=	catsNdawgz

SHELL	=	bash

GREEN		=	\033[0;32m
CYAN		=	\033[0;36m
RED			=	\033[0;31m
RESET_COL	=	\033[0m

CFILES	=	Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			main.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp

OBJ_DIR	= obj
OBJS	= $(addprefix $(OBJ_DIR)/, $(CFILES:.cpp=.o))

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

RM_OBJS			=	rm -rf $(OBJ_DIR)
RM_EXE			=	rm -f $(NAME)

COMPILE_EXE		=	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
COMPILE_EXE_OUT	=	$$($(COMPILE_EXE) 2>&1 | sed -e 's/error/\\\033[0;31merror\\\033[0m/g' -e 's/warning/\\\033[0;33mwarning\\\033[0m/g')

COMPILE_C		=	$(CC) $(CFLAGS) -o $@ -c $<
COMPILE_C_OUT	=	$$($(COMPILE_C) 2>&1 | sed -e 's/error/\\\033[0;31merror\\\033[0m/g' -e 's/warning/\\\033[0;33mwarning\\\033[0m/g')

$(OBJ_DIR)/%.o:	%.cpp
	@mkdir -p $(OBJ_DIR)
	@printf "$(CYAN)%-30s-->%30s $(RESET_COL)\n$(COMPILE_C_OUT)" $^ $@

all: $(NAME)
	@if [ -e $(NAME) ]; then \
		echo -e "$(GREEN)>>>>>>>> Compilation successful\n>>>>>>>>$(RESET_COL)"; \
	else \
		echo -e "$(RED)>>>>>>>> Compilation failed\n>>>>>>>>$(RESET_COL)"; \
	fi

$(NAME):	pretty_print $(OBJS)
	@echo -e "\n$(CYAN)>>>>>>>> Compiling $(NAME) ...$(RESET_COL)$(COMPILE_EXE_OUT)"

pretty_print: 
	@echo -e "\n--------------------- $(NAME) ---------------------"

clean:
	@echo -e "$(RED)>>>>>>>> Deleting obj files$(RESET_COL)"
	@$(RM_OBJS)

fclean:	clean
	@echo -e "$(RED)>>>>>>>> Deleting ./$(NAME) $(RESET_COL)"
	@$(RM_EXE)

re:	fclean all

.PHONY: all clean fclean re pretty_print print_out
