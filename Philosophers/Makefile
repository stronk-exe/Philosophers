# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 14:50:46 by ael-asri          #+#    #+#              #
#    Updated: 2022/04/11 01:20:59 by ael-asri         ###   ########.fr        #
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

BSRCS = philosophers_bonus/actions_bonus.c\
		philosophers_bonus/philosophers_bonus.c\
		philosophers_bonus/philosophing_bonus.c\
		philosophers_bonus/processing_bonus.c\
		philosophers_bonus/forking_bonus.c\
		philosophers_bonus/routine_bonus.c\
		get_time.c

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