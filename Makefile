NAME = visu

CC = gcc
RM = rm -rf
CFLAGS = -Werror -Wall -Wextra

LIBFT = libft/libft.a

SRC_PATH = srcs/
SRC_NAME = main.c /
			sdl/sdl_destroy.c /
			sdl/sdl_event.c /
			sdl/sdl_fps.c /
			sdl/sdl_init.c /
			sdl/sdl_loop.c /
			parser/parser_entry.c /

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CPPFLAGS = -Iincs -Ilibft
LDFLAGS = -Llibft
LDLIBS = -lft

all: $(NAME)

$(LIBFT):
	make -C libft

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(LIBFT) $(OBJ_PATH) $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C libft
	$(RM) $(OBJ)
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re