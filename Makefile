NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc

LIBFT = ./libft/libft.a

SRCS = src/flag_detect.c \
	   src/lst_util.c \
	   src/parse_util.c \
	   src/setting_util.c \
	   src/make_string_util.c \
	   src/make_string_c.c \
	   src/make_string_d.c \
	   src/make_string_p.c \
	   src/make_string_per.c \
	   src/make_string_s.c \
	   src/make_string_u.c \
	   src/make_string_x.c \
	   src/make_string_x2.c \
	   src/make_string_i.c \
	   src/number_left.c \
	   src/number_right.c \
	   src/number_util.c \
	   src/get_malloc_size.c \
	   src/get_malloc_size2.c \
	   src/ft_printf.c

SURP = flag_detect.o \
	   lst_util. o \
	   parse_util.o \
	   setting_util.o \
	   make_string_util.o \
	   make_string_c.o \
	   make_string_d.o \
	   make_string_p.o \
	   make_string_per.o \
	   make_string_s.o \
	   make_string_u.o \
	   make_string_x.o \
	   make_string_i.o \
	   number_left.o \
	   number_right.o \
	   number_util.o \
	   get_malloc_size.o \
	   get_malloc_size2.o \
	   make_string_x2.o 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a ./$(NAME)
	ar -rc $(NAME) $(OBJS)
clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURP)
	rm -f $(OBJS)

fclean :
	$(MAKE) fclean -C ./libft
	rm -f $(OBJS) $(NAME)
	
re : fclean all

.PHONY: clean fclean all re bonus
