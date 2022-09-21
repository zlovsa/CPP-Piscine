SRCS	= megaphone.cpp
NAME	= megaphone

CC		= g++
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

all:		$(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):	$(OBJS)
			$(CC) -g $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			${RM} $(OBJS)

fclean:		clean
			${RM} $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re