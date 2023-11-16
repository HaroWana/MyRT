CC = c++
CFLAGS = -Wall -Werror -Wextra

EXEC = RT_tests

SRC = tests.cpp \
	srcs/tests/tuple_operations.cpp \
	srcs/tests/projectiles.cpp \
	srcs/tests/color_operations.cpp \
	srcs/objs/Tuple.cpp \
	srcs/objs/Vector.cpp \
	srcs/objs/Point.cpp \
	srcs/objs/Color.cpp \
	srcs/objs/Image.cpp

OBJ = $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
