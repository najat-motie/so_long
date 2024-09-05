NAME = so_long

CFLAGS = -Wall -Wextra -Werror

SRC_FILES = main.c gnl/get_next_line.c gnl/get_next_line_utils.c parsing_map/checks1.c \
parsing_map/checks2.c parsing_map/file_extension.c parsing_map/finding_path.c \
init_map/read_map.c init_map/window.c init_map/key_events.c init_map/close_pgm.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): ${OBJ_FILES} so_long.h
	cc $(OBJ_FILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all