ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = all
%:
	@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "\033[1;32m `expr " [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]\033[0m"
endif

CC = c++
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

EXEC = RT_tests

SRC = tests.cpp \
	srcs/Tests/tuple_operations.cpp \
	srcs/Tests/projectiles.cpp \
	srcs/Tests/color_operations.cpp \
	srcs/Tests/image_tests.cpp \
	srcs/Utils/numDigits.cpp \
	srcs/Classes/Tuple.cpp \
	srcs/Classes/Vector.cpp \
	srcs/Classes/Point.cpp \
	srcs/Classes/Color.cpp \
	srcs/Classes/Image.cpp

OBJ = $(SRC:.cpp=.o)

all: $(EXEC)
	@$(ECHO) "\033[1;32mProject Compiled\033[0m"

$(EXEC): $(OBJ)
	@$(ECHO) Linking $@
	@sleep 0.1
	@touch $@
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	@$(ECHO) Compiling $@
	@sleep 0.1
	@touch $@
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)
	@echo "\033[1;32mBinaries Deleted\033[0m"

fclean: clean
	@rm -f $(EXEC)
	@echo "\033[1;32mExecutable Deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re

endif