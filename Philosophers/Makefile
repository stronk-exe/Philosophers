# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 14:50:46 by ael-asri          #+#    #+#              #
#    Updated: 2022/04/13 23:37:49 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

BNAME = philo_bonus

SRCS =  philosophers.c\
		forking.c\
		threading.c\
		routine.c\
		actions.c\
		philosophers_utils.c\
		get_time.c\
		philosophing.c\
		ending.c

BSRCS = _bonus/philosophers_bonus.c\
		_bonus/forking_bonus.c\
		_bonus/threading_bonus.c\
		_bonus/routine_bonus.c\
		_bonus/actions_bonus.c\
		philosophers_utils.c\
		get_time.c\
		_bonus/philosophing_bonus.c\
		ending.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus : $(BNAME)

$(NAME): $(OBJS)
		cc $(CFLAGS) -pthread $^ -o $@

$(BNAME): $(BOBJS)
		cc $(CFLAGS) -pthread $^ -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
		rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all bonus clean fclean re