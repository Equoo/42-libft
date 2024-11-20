NAME = libft.a
CC = cc
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror -MMD -I .
SRCS = ft_isalnum.c\
       ft_isalpha.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_strlen.c\
	   ft_memset.c\
	   ft_bzero.c\
	   ft_memmove.c\
	   ft_memcpy.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strncmp.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strnstr.c\
	   ft_atoi.c\
	   ft_calloc.c\
	   ft_strdup.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_split.c\
	   ft_itoa.c\
	   ft_strmapi.c\
	   ft_striteri.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c
SRCS_BONUS = ft_lstnew_bonus.c\
	   ft_lstadd_front_bonus.c\
	   ft_lstsize_bonus.c\
	   ft_lstlast_bonus.c\
	   ft_lstadd_back_bonus.c\
	   ft_lstdelone_bonus.c\
	   ft_lstclear_bonus.c\
	   ft_lstiter_bonus.c\
	   ft_lstmap_bonus.c
SRCS_ALL = $(SRCS) $(SRCS_BONUS)

DIR_OBJ = obj/
OBJS = ${patsubst %.c,$(DIR_OBJ)%.o, $(SRCS)}
OBJS_BONUS = ${patsubst %.c,$(DIR_OBJ)%.o, $(SRCS_BONUS)}
OBJS_ALL = ${OBJS} ${OBJS_BONUS}

DEPS= ${patsubst %.c,$(DIR_OBJ)%.d, $(SRCS_ALL)}
-include $(DEPS)

ifdef BONUS
	OBJS = ${patsubst %.c,$(DIR_OBJ)%.o, $(SRCS_ALL)}
endif

.PHONY: all
all: $(NAME)

.PHONY: bonus
bonus: $(OBJS_BONUS)
	$(MAKE) BONUS=1 all

$(DIR_OBJ):
	mkdir -p $@

$(DIR_OBJ)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(DIR_OBJ) $(OBJS) Makefile
	$(AR) $@ $(OBJS)

.PHONY: clean
clean:
	rm -Rf $(DIR_OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all 

.DEFAULT_GOAL = all