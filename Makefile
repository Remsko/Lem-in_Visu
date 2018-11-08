NAME = visu

CC = gcc
RM = rm -rf
CFLAGS = -Werror -Wall -Wextra

LIBFT = libft/libft.a

SRC_PATH = srcs/
SRC_NAME = main.c \
			sdl/sdl_destroy.c \
			sdl/sdl_event.c \
			sdl/sdl_fps.c \
			sdl/sdl_init.c \
			sdl/sdl_loop.c \
			sdl/sdl_draw.c \
			sdl/sdl_utils.c \
			parser/parser_entry.c \
			parser/parser_ants.c \
			parser/parser_rooms.c \
			parser/parser_links.c \
			parser/parser_runs.c \
			del/garbage_collector.c \
			del/del.c \
			draw/draw_all.c \
			draw/draw_circle.c \
			draw/draw_line.c \
			draw/draw_fill_circle.c \
			norm/normalize_coord.c \

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CPPFLAGS = -Iincs -Ilibft -I ~/.brew/include/SDL2
LDLIBS = -Llibft -L ~/.brew/lib
LDFLAGS = -lft -lSDL2

all: $(NAME)

$(LIBFT):
	make -C libft

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)sdl
	mkdir -p $(OBJ_PATH)parser
	mkdir -p $(OBJ_PATH)del
	mkdir -p $(OBJ_PATH)draw
	mkdir -p $(OBJ_PATH)norm

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
