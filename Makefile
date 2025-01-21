CC      = cc
CFLAGS  = -Wall -Wextra -Werror

all: server client

server: server.c minitalk.h
	$(CC) $(CFLAGS) server.c -o server

client: client.c minitalk.h
	$(CC) $(CFLAGS) client.c -o client

clean:
	rm -f server client

fclean: clean

re: fclean all

.PHONY: all clean fclean re

bonus: server_bonus client_bonus

server_bonus: server_bonus.c minitalk_bonus.h
	$(CC) $(CFLAGS) server_bonus.c -o server_bonus

client_bonus: client_bonus.c minitalk_bonus.h
	$(CC) $(CFLAGS) client_bonus.c -o client_bonus

clean_bonus:
	rm -f server_bonus client_bonus

fclean: clean_bonus

re: fclean all

.PHONY: all clean fclean re

