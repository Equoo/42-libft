CC= cc
AR= ar -crs
CFLAGS= -Wall -Wextra -Werror -MMD
SRCS= $(wildcard *.c)
OBJS= ${SRCS:.c=.o}
NAME = libft
$(NAME): $(OBJS) Makefile
	$(AR) $(NAME).a $(OBJS)

DEPS= $(wildcard *.d)

-include $(DEPS)

all: $(NAME)

.PHONY: fclean all clean

clean:
	rm -f $(OBJS) $(DEPS)
 
fclean: clean
	rm -f $(NAME).a

re: fclean all

