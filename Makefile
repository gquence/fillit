CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC_DIR = srcs/
INC_DIR = includes/
LIB_INC = libft/includes
LIB_DIR = libft/
LIB_NAME = libft.a
SRCS = *.c
OBJ = $(SRCS:.c=.o)
NAME = fillit

all: $(LIB_NAME) $(NAME) 

$(LIB_NAME):
	make -C $(LIB_DIR) $(LIB_NAME)

$(NAME): $(LIB_NAME)
	$(CC) -c $(SRC_DIR)$(SRCS) -I $(INC_DIR) -I $(LIB_INC) $(FLAGS)
	$(CC) $(OBJ) -o $(NAME) -L $(LIB_DIR) -lft -g

clean:
	make -C $(LIB_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all
