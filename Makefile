CC = c++
CFLAGS = -Wall -Werror -Wextra

EXEC_TEST = RT_tests

# MAIN_SRC = 

TEST_SRC = tests.cpp \
		srcs/tests/tuple_operations.cpp \
		srcs/tests/projectiles.cpp \
		srcs/tests/color_operations.cpp

SRC = srcs/objs/Tuple.cpp \
	srcs/objs/Vector.cpp \
	srcs/objs/Point.cpp \
	srcs/objs/Color.cpp \
	srcs/objs/Image.cpp

OBJ = $(SRC:.cpp=.o)
OBJ_TEST = $(TEST_SRC:.cpp=.o)

all: $(EXEC)

test: $(EXEC_TEST)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(EXEC_TEST): $(OBJ_TEST) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
