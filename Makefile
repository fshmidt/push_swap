# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 17:19:10 by mbesan            #+#    #+#              #
#    Updated: 2022/02/15 21:37:34 by mbesan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

B_NAME			= checker

SRCS			= ./main.c ./arg_sort.c ./additional_utilis.c ./swaps.c \
				./decision.c ./execution.c ./list_developement.c \
				./pushes_and_rrr.c ./rotors.c ./scoring.c ./sorting.c \
				./validation.c ./libs/libft/ft_atoi.c \
				./libs/libft/ft_isdigit.c ./libs/libft/ft_split.c \
				./libs/libft/ft_strlen.c

B_SRCS			= ./checker.c ./arg_sort.c ./additional_utilis.c ./rotors.c \
				./decision.c execution.c ./list_developement.c \
				./pushes_and_rrr.c ./scoring.c ./sorting.c ./swaps.c \
				./validation.c ./libs/libft/ft_atoi.c \
				./libs/libft/ft_isdigit.c ./libs/libft/ft_split.c \
				./libs/libft/ft_strlen.c ./libs/gnl/get_next_line.c \
				./libs/libft/ft_strncmp.c ./libs/libft/ft_calloc.c \
				./libs/libft/ft_strchr.c ./libs/libft/ft_strjoin.c \

OBJS			= $(SRCS:.c=.o)

B_OBJS			= $(B_SRCS:.c=.o)

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -rf

HDR				= push_swap.h

%.o: %.c push_swap.h
				$(CC) -I./libs/libft -I./libs/gnl -g -c $< -o $@

$(NAME):		$(OBJS) $(HDR) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
				make -C libs/libft/

$(B_NAME):		$(HDR) $(B_OBJS) $(LIBFT)
				$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -I. -o $(B_NAME)

all:			$(NAME)

bonus:			$(B_NAME)

clean:			
				make clean -C libs/libft
				$(RM) $(OBJS) $(B_OBJS)

fclean:			clean
				make fclean -C libs/libft
				$(RM) $(NAME) $(B_NAME)

re:				fclean all