NAME = libftprintf.a

COMPILER = cc

COMPILER_FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c

OBJS := $(SRCS:%.c=%.o)

%.o: %.c printf.h
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@ 

.PHONY: clean fclean re all 

all: $(NAME)

$(NAME):
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all