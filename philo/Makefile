# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 14:50:46 by ael-asri          #+#    #+#              #
#    Updated: 2022/04/22 14:32:06 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =  philosophers.c\
		forking.c\
		threading.c\
		routine.c\
		actions.c\
		philosophers_utils.c\
		get_time.c\
		philosophing.c\
		ending.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

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