# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 14:57:54 by abasarud          #+#    #+#              #
#    Updated: 2022/11/21 11:05:52 by abasarud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c initialise.c monitor.c forks.c message.c error.c utils.c

CC = gcc 
LIBS = -lpthread
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

OBJS = $(SRCS:.c=.o) 

all:  $(NAME)

$(NAME): $(OBJS)
		@echo "$(GR) ... compiling philosophers$(DF)"
		 @$(CC)  ${CFLAGS} -o ${NAME} ${SRCS:.c=.o} ${LIBS}
		 @echo "$(GR) ... done compiling$(DF)"

clean : 
			@$(RM) ./*.o
			@echo "$(RED)	removing all objs files$(DF)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)	removing exec files$(DF)"

re:				fclean $(NAME)




GR 	:= \033[3;92m
YL	:= \033[1;93m
DF	:= \033[0m

RED := \033[1;31m     
BL := \033[3;34m        
ITA := \033[3;90m