SRCS	= phonebook.cpp Phonebook.class.cpp Contact.class.cpp
NAME	= phonebook

CC		= g++
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all:		$(NAME)

-include $(DEPS)
%.o: %.cpp
	$(CC) $(CFLAGS) -MMD -MP -c -o $@ $<

$(NAME):	$(OBJS)
			$(CC) -g $(CFLAGS) -MMD -MP -o $(NAME) $(OBJS)

clean:
			${RM} $(OBJS)

fclean:		clean
			${RM} $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re