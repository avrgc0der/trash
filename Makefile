NAME = minishell

CFILES = src/minishell.c

OBJECTS = $(CFILES:.c=.o)

LIBFT_PATH = libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes
CFLAGS += -fsanitize=address -g3

LINKFLAGS = -lreadline -L/includes

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: subsystems $(NAME) build

build :

		@echo "$(MAGENTA) /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\ $(RESET)"
		@echo "$(MAGENTA)( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )$(RESET)"
		@echo "$(MAGENTA) > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ < $(RESET)"
		@echo "$(MAGENTA) /\_/\ $(RESET) $(BLUE)  █████                                █████   $(RESET) $(MAGENTA) /\_/\ $(RESET)"
		@echo "$(MAGENTA)( o.o )$(RESET) $(BLUE) ░░███░                               ░░███   $(RESET) $(MAGENTA)( o.o )$(RESET)"
		@echo "$(MAGENTA) > ^ < $(RESET) $(GREEN) ███████   ████████   ██████    █████  ░███████ $(RESET) $(MAGENTA) > ^ < $(RESET)"
		@echo "$(MAGENTA) /\_/\ $(RESET) $(GREEN) ░░░███░   ░░███░░███ ░░░░░███  ███░░   ░███░░███$(RESET) $(MAGENTA) /\_/\ $(RESET)"
		@echo "$(MAGENTA)( o.o )$(RESET) $(YELLOW)  ░███     ░███ ░░░   ███████ ░░█████  ░███ ░███$(RESET) $(MAGENTA)( o.o )$(RESET)"
		@echo "$(MAGENTA) > ^ < $(RESET) $(YELLOW)  ░███ ███ ░███      ███░░███  ░░░░███ ░███ ░███$(RESET) $(MAGENTA) > ^ < $(RESET)"
		@echo "$(MAGENTA) /\_/\ $(RESET) $(YELLOW)  ░░█████  █████    ░░████████ ██████  ████ █████$(RESET) $(MAGENTA) /\_/\ $(RESET)"
		@echo "$(MAGENTA)( o.o )$(RESET) $(OTHER)   ░░░░░  ░░░░░      ░░░░░░░░ ░░░░░░  ░░░░ ░░░░░$(RESET) $(MAGENTA)( o.o )$(RESET)"
		@echo "$(MAGENTA) > ^ < $(RESET) $(WHITE)    a terminal recreation application shell     $(RESET) $(MAGENTA) > ^ < $(RESET)"
		@echo "$(MAGENTA) /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\ $(RESET)"
		@echo "$(MAGENTA)( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )$(RESET)"
		@echo "$(MAGENTA) > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ < $(RESET)"

MAGENTA=\033[95m
BLUE=\033[36m
YELLOW=\033[33m
GREEN=\033[32m
RESET=\033[0m
OTHER=\033[90m
WHITE=\033[97m

subsystems:
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJECTS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAGS) $(LINKFLAGS) -o $(NAME)

clean:
	make clean -C libft/
	rm -rf $(OBJECTS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
