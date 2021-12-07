.SILENT:

#COLOR
RED =`tput setaf 1`
GREEN =`tput setaf 2`
YELLOW =`tput setaf 3`
BLUE =`tput setaf 4`
CLEAR =`tput sgr0`

#ALIASES
CC = gcc
CCFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

#PROJECT
EXEC =

#FILES
MAIN =
SRCSDIR =
SRCS =
SRCSPATH = $(addprefix $(SRCSDIR), $(SRCS))
OBJSDIR = objects
OBJS = $(SRCS:%.cpp=$(OBJSDIR)/%.o)

#RULES
$(OBJSDIR)/%.o: $(SRCSDIR)/%.cpp
	echo "$(BLUE)Compiling $(YELLOW)$@$(BLUE) from $(YELLOW)$^$(BLUE) ..$(CLEAR)"
	mkdir -p $(OBJSDIR)
	$(CC) $(CCFLAGS) -c $< -o $@
	echo "$(BLUE) - $(YELLOW)$@$(CLEAR) [$(GREEN)OK$(CLEAR)]"

all: $(EXEC)

$(EXEC): $(OBJS)
	echo "$(GREEN)All $(YELLOW)objects$(GREEN) compiled with success !$(CLEAR)"
	$(CC) $(CCFLAGS) $(STD) $^ $(MAIN) -o $(EXEC)
	echo ""; echo "$(BLUE)Compiling binary file from $(YELLOW)$(MAIN)$(BLUE) ...$(CLEAR)"
	echo "$(GREEN)Binary $(YELLOW)$(EXEC)$(GREEN) is now ready to use !$(CLEAR)"

clean:
	$(RM) $(OBJSDIR)
	echo "$(BLUE)Deleting following files :$(CLEAR)"
	echo "$(RED) - Repertory $(YELLOW)$(OBJSDIR)/$(RED) & $(YELLOW)content$(RED) deleted.$(CLEAR)"

fclean: clean
	$(RM) $(EXEC)
	echo "$(RED) - Binary $(YELLOW)$(EXEC)$(RED) deleted.$(CLEAR)"

newline:
	echo ""

re: fclean newline all

.PHONY: all