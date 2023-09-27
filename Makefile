NAME = libftprintf.a

COMPILER = cc

COMPILER_FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putnbr_fd.c ft_bzero.c ft_putstr_fd.c ft_putchar_fd.c

OBJS := $(SRCS:%.c=%.o)

%.o: %.c printf.h
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@ 

#delete next line 
program : main.c $(OBJS)
	cc -Wall -Wextra -Werror -o program main.c $(OBJS)
	
.PHONY: clean fclean re all 

all: $(NAME)

$(NAME):
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all