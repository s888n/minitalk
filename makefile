# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srachdi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 03:17:22 by srachdi           #+#    #+#              #
#    Updated: 2023/02/02 03:17:24 by srachdi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server
CLIENT   = client
SERVER_BONUS  = server_bonus
CLIENT_BONUS   = client_bonus
CC = cc
CFLAGS = -Wall  -Wextra -Werror
RM = rm -f
INCLUDES = minitalk.h
%.o : %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(SERVER) $(CLIENT)
	@echo "\033[0;31m Manditory. \033[0m"
$(SERVER) : server.o utils.o minitalk.h
	@$(CC) $(CFLAGS) server.o utils.o -o $@
$(CLIENT) : client.o utils.o minitalk.h
	@$(CC) $(CFLAGS) client.o utils.o -o $@

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "\033[0;31m Bonus. \033[0m"
$(SERVER_BONUS) : server_bonus.o utils_bonus.o utils2_bonus.o minitalk_bonus.h
	@$(CC) $(CFLAGS) server_bonus.o utils_bonus.o utils2_bonus.o -o $@
$(CLIENT_BONUS) : client_bonus.o utils_bonus.o utils2_bonus.o minitalk_bonus.h
	@$(CC) $(CFLAGS) client_bonus.o utils_bonus.o utils2_bonus.o -o $@

clean : 
	@$(RM) *.o
	@echo "\033[0;31m Cleaned.\033[0m"
fclean : clean
	@$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "\033[0;31m Removed Binaries. \033[0m"
re : fclean all
.PHONY : all clean fclean re bonus
