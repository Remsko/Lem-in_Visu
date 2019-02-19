# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/19 12:55:23 by rpinoit           #+#    #+#              #
#    Updated: 2019/02/19 13:07:45 by rpinoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visu
RM = rm -rf

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  HEADERS                                     #

INC_PATH += ./incs

INC_NAME += proto.h
INC_NAME += type.h
INC_NAME += visu.h

INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

#==============================================================================#
#------------------------------------------------------------------------------#
#                            COMPILER & FLAGS                                  #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = $(addprefix -I, $(INC_PATH))

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  SOURCES                                     #

SRC_PATH = ./srcs/
SRC_NAME += main.c

SRC_SUB += sdl
SRC_NAME += sdl_destroy.c
SRC_NAME += sdl_event.c
SRC_NAME += sdl_handle_event.c
SRC_NAME += sdl_fps.c
SRC_NAME += sdl_init.c
SRC_NAME += sdl_loop.c
SRC_NAME += sdl_draw.c
SRC_NAME += sdl_utils.c

SRC_SUB += parser
SRC_NAME += parser_entry.c
SRC_NAME += parser_ants.c
SRC_NAME += parser_rooms.c
SRC_NAME += parser_links.c
SRC_NAME += parser_runs.c
SRC_NAME += parser_find.c

SRC_SUB += del
SRC_NAME += garbage_collector.c
SRC_NAME += del.c

SRC_SUB += draw
SRC_NAME += draw_all.c
SRC_NAME += draw_fill_circle.c

SRC_SUB += norm
SRC_NAME += normalize_coord.c

vpath %.c $(SRC_PATH) $(addprefix $(SRC_PATH)/, $(SRC_SUB))

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  OBJECTS                                     #

OBJ_PATH = .obj
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME)) 

#==============================================================================#
#------------------------------------------------------------------------------#
#                                LIBRARIES                                     #

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
CPPFLAGS += -I$(LIBFT_PATH)
LDFLAGS += -L$(LIBFT_PATH) -lft

CPPFLAGS += `sdl2-config --cflags --libs`
LDFLAGS += -lSDL2

LFLAGS += -lm

#==============================================================================#
#------------------------------------------------------------------------------#
#                                 RULES                                        #

all: $(NAME)

$(NAME): $(OBJ) | $(LIBFT)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ): $(INC) | $(OBJ_PATH)
$(OBJ): $(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	mkdir -p $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re