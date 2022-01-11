.SILENT:

#COLOR
RED =`tput setaf 1`
GREEN =`tput setaf 2`
YELLOW =`tput setaf 3`
BLUE =`tput setaf 4`
CLEAR =`tput sgr0`

#ALIASES
CC = g++
CCFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#PROJECT
EXEC1 = output_ft
EXEC2 = output_std

#FILES
MAIN1 = binaries/ft.cpp
MAIN2 = binaries/std.cpp

#RULES

all: $(EXEC1) $(EXEC2)

$(EXEC1):
	echo ""; echo "$(BLUE)Compiling first binary file from $(YELLOW)$(MAIN1)$(BLUE) ...$(CLEAR)"
	$(CC) $(CCFLAGS)  $(MAIN1) -o $(EXEC1)
	echo "$(GREEN)Binary $(YELLOW)$(EXEC1)$(GREEN) is now ready to use !$(CLEAR)"

$(EXEC2):
	echo ""; echo "$(BLUE)Compiling second binary file from $(YELLOW)$(MAIN2)$(BLUE) ...$(CLEAR)"
	$(CC) $(CCFLAGS)  $(MAIN2) -o $(EXEC2)
	echo "$(GREEN)Binary $(YELLOW)$(EXEC2)$(GREEN) is now ready to use !$(CLEAR)"


fclean:
	$(RM) $(EXEC1) $(EXEC2)
	echo "$(RED) - Binaries $(YELLOW)$(EXEC1) & $(EXEC2)$(RED) deleted.$(CLEAR)"

re: fclean all

.PHONY: all