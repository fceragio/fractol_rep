#Makefile#

NAME = fractol

BONUS = bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = main.c \
	f_strings.c \
	f_explainations.c \
	f_mandelbrot.c \
	f_mathematicals.c \
	f_events.c \
	f_rendering.c \
	f_julia.c \
	f_convert_str.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = bonus_burningship_bonus.c \
	bonus_events_bonus.c \
	bonus_explainations_bonus.c \
	bonus_main_bonus.c \
	bonus_rendering_bonus.c	\
	bonus_convert_str_bonus.c \
	bonus_julia_bonus.c \
	bonus_mandelbrot_bonus.c \
	bonus_mathematicals_bonus.c \
	bonus_strings_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

COLOR_GREEN=\033[0;32m
COLOR_END=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L../mlx_linux -lmlx_Linux -L/usr/lib -I../mlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) created.✅$(COLOR_END)"

$(BONUS): $(BONUS_OBJS)
	@if [ ! -f $(BONUS) ] || { for obj in $(BONUS_OBJS); do [ $$obj -nt $(BONUS) ] && exit 0; done; false; }; then \
		$(CC) $(BONUS_OBJS) -L../mlx_linux -lmlx_Linux -L/usr/lib -I../mlx_linux -lXext -lX11 -lm -lz -o $(BONUS); \
		echo "$(COLOR_GREEN)$(BONUS) created.✅$(COLOR_END)"; \
	else \
		echo "$(COLOR_GREEN)nothing to do for $(BONUS).✅$(COLOR_END)"; \
	fi

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS)
	@echo "$(COLOR_GREEN)$(NAME) cleaned.✅$(COLOR_END)"

re: fclean all

.PHONY: all clean fclean re bonus