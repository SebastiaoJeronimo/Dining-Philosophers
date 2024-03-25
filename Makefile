NAME = philo

SRC = main.c data.c arg_check.c program.c time.c utils.c one_philo.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra #-O3 -fsanitize=thread 

LPTHREAD = -lpthread

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LPTHREAD)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all