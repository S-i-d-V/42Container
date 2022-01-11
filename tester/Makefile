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
EXEC = ContainerTester

#FILES
MAIN = main.cpp
SRCS =	stack/s_empty.cpp stack/s_pop.cpp stack/s_push.cpp stack/s_size.cpp stack/s_top.cpp stack/test_stack.cpp \
		vector/test_vector.cpp vector/v_iterators.cpp vector/v_reverse_iterators.cpp vector/v_max_size.cpp vector/v_resize.cpp vector/v_size.cpp vector/v_capacity.cpp vector/v_empty.cpp vector/v_reserve.cpp\
		map/test_map.cpp \
		utils.cpp 
SRCSPATH = $(addprefix $(SRCSDIR), $(SRCS))
OBJSDIR = objects
OBJS = $(SRCS:%.cpp=$(OBJSDIR)/%.o)

#RULES
$(OBJSDIR)/%.o: %.cpp
	echo "$(BLUE)Compiling $(YELLOW)$@$(BLUE) from $(YELLOW)$^$(BLUE) ..$(CLEAR)"
	mkdir -p $(OBJSDIR) $(OBJSDIR)/stack $(OBJSDIR)/vector $(OBJSDIR)/map
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