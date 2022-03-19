NAME = philosophers


SRCS =  philosophers.c\
		forking.c\
		philosophing.c\
		routine.c\
		actions.c\
		philosophers_utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		cc $(CFLAGS) -pthread $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re