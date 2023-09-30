NAME = libftprintf.a

COMPILER = cc

COMPILER_FLAGS = -Wall -Wextra -Werror

SRCS = ft_bzero.c \
ft_calloc.c \
ft_printf.c \
ft_putchar_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_strlcpy.c \
ft_strlen.c \
ft_toupper.c \
printc.c \
printdi.c \
printp.c \
prints.c \
printu.c \
printx.c \
putunbr.c 

OBJS := $(SRCS:%.c=%.o)

%.o: %.c ft_printf.h
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@ 
	
.PHONY: clean fclean re all 

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all