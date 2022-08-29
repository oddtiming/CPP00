NAME	=	dollarStoreSed

LOGFILE	=	quote.txt
LOGMSG	=	One word can change the entire meaning of a sentence.

SHELL	=	bash

GREEN		=	\033[0;32m
CYAN		=	\033[0;36m
RED			=	\033[0;31m
UYELLOW		=	\033[4;33m
RESET_COL	=	\033[0m

CFILES	=	main.cpp

OBJ_DIR	= obj
OBJS	= $(addprefix $(OBJ_DIR)/, $(CFILES:.cpp=.o))

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -pedantic-errors -std=c++98 -O3

RM_OBJS			=	rm -rf $(OBJ_DIR)
RM_EXE			=	rm -f $(NAME)
RM_REPLACEMENTS	=	rm -f *.replace

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
	@echo -e "\n$(CYAN)>>>>>>>> Compiling into executable $(UYELLOW)./$(NAME)$(RESET_COL)$(COMPILE_EXE_OUT)"
	@echo -e "\n$(CYAN)>>>>>>>> Writing \"$(LOGMSG)\" into $(LOGFILE)...$(RESET_COL)\n"
	@echo -e "$(GREEN)>>>>>>>> $(LOGFILE) successfuly created!\n>>>>>>>>$(RESET_COL)";
	@echo "$(LOGMSG)" > $(LOGFILE)

pretty_print: 
	@echo -e "\n--------------------- $(NAME) ---------------------"

clean:
	@echo -e "$(RED)>>>>>>>> Deleting obj files$(RESET_COL)"
	@$(RM_OBJS)

fclean:	clean
	@echo -e "$(RED)>>>>>>>> Deleting ./$(NAME) $(RESET_COL)"
	@$(RM_EXE)
	@echo -e "$(RED)>>>>>>>> Deleting *.replace $(RESET_COL)"
	@$(RM_REPLACEMENTS)

re:	fclean all

.PHONY: all clean fclean re pretty_print print_out
