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
