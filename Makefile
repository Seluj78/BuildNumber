CC = clang

CFLAGS = -g -Wall -Wextra -Werror

NAME = buildnumber

# Libraries
#LIBS_FOLDER    = lib
## libcbc
LIB_CBC_DIR := libcbc

# libft:
INC += -I $(LIB_CBC_DIR)/libft/includes
# ftprintf:
INC += -I $(LIB_CBC_DIR)/libftprintf/includes
# logger:
INC += -I $(LIB_CBC_DIR)/liblogger/includes
# tcaps:
INC += -I $(LIB_CBC_DIR)/libtcaps/includes

LIBS += -L $(LIB_CBC_DIR) -lcbc

all: lib buildnumber

lib:
	@make -C $(LIB_CBC_DIR)

buildnumber:
	@$(CC) buildnumber.c buildnumber_print.c $(INC) $(LIB) -o $(NAME) $(LIB_CBC_DIR)/libcbc.a
clean:
	rm -rf buildnumber.o
	@make clean -C $(LIB_CBC_DIR)


fclean: clean
	rm -rf buildnumber.o $(NAME)
	@make fclean -C $(LIB_CBC_DIR)

re: fclean $(LIB) all

.PHONY: re clean fclean all buildnumber