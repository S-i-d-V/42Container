.SILENT:

#COLOR
RED =`tput setaf 1`
GREEN =`tput setaf 2`
YELLOW =`tput setaf 3`
BLUE =`tput setaf 4`
CLEAR =`tput sgr0`

#ALIASES
CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

#PROJECT
EXEC1 = myBinary
EXEC2 = stlBinary

#FILES
MAIN1 = myMain.cpp
MAIN2 =	stlMain.cpp
OUTPUT1 = my.output
OUTPUT2 = stl.output
HEADERS = containers/vector/vector.hpp containers/vector/vector_iterator.hpp \
			containers/stack/stack.hpp \
			containers/map/map.hpp containers/map/map_iterator.hpp \
			utils/binary_tree.hpp utils/enable_if.hpp utils/equal.hpp utils/iterator_traits.hpp utils/lexicographical_compare.hpp utils/pair.hpp utils/reverse_iterator.hpp

#RULES
all: $(OUTPUT1) $(OUTPUT2) $(HEADERS) $(MAIN1) $(MAIN2)

$(OUTPUT1): $(EXEC1)
	echo ""; echo "$(BLUE)Executing 1st binary file and saving output in $(YELLOW)$(OUTPUT1)$(BLUE) ...$(CLEAR)"
	./$(EXEC1) > $(OUTPUT1)
	echo "$(GREEN)Done.$(CLEAR)"

$(OUTPUT2): $(EXEC2)
	echo ""; echo "$(BLUE)Executing 1st binary file and saving output in $(YELLOW)$(OUTPUT2)$(BLUE) ...$(CLEAR)"
	./$(EXEC2) > $(OUTPUT2)
	echo "$(GREEN)Done.$(CLEAR)"

$(EXEC1):
	echo ""; echo "$(BLUE)Compiling 1st binary file from $(YELLOW)$(MAIN1)$(BLUE) ...$(CLEAR)"
	$(CC) $(CCFLAGS) $(STD) $^ $(MAIN1) -o $(EXEC1)
	echo "$(GREEN)Binary $(YELLOW)$(EXEC1)$(GREEN) is now ready to use !$(CLEAR)"

$(EXEC2):
	echo ""; echo "$(BLUE)Compiling 2st binary file from $(YELLOW)$(MAIN2)$(BLUE) ...$(CLEAR)"
	$(CC) $(CCFLAGS) $(STD) $^ $(MAIN2) -o $(EXEC2)
	echo "$(GREEN)Binary $(YELLOW)$(EXEC2)$(GREEN) is now ready to use !$(CLEAR)"

clean:
	$(RM) $(EXEC1) $(EXEC2)
	echo "$(RED) - Binaries deleted.$(CLEAR)"

fclean: clean
	$(RM) $(OUTPUT1) $(OUTPUT2)
	echo "$(RED) - Outputs cleared.$(CLEAR)"

re: fclean all

.PHONY: all