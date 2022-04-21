# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 14:50:46 by ael-asri          #+#    #+#              #
#    Updated: 2022/04/21 17:48:43 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS = 	philosophers_bonus.c\
		forking_bonus.c\
		routine_bonus.c\
		actions_bonus.c\
		philosophers_utils_bonus.c\
		get_time_bonus.c\
		philosophing_bonus.c\
		ending_bonus.c

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