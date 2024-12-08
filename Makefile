NAME = libftprintf.a
SRCS = ft_print_forms.c ft_printf.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
RM = rm -f


all : $(NAME)
	

$(NAME):	$(OBJS)
				ar rc $(NAME) $(OBJS)  

clean: 
				$(RM) $(OBJS)

fclean: 	clean
				$(RM) $(NAME)

re: 		fclean $(NAME)


.PHONY  : all clean fclean re 

