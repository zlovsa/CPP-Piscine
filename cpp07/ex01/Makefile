SRC_FILES	= main.cpp

NAME		= iter

CC			= clang++
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -std=c++98

INCLUDES_DIR	= .
SRCS_DIR	= .
OBJS_DIR	= ./objs

SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(patsubst $(SRCS_DIR)/%.cpp,$(OBJS_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

all:		$(NAME)

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -MMD -MP -c -o $@ $<

$(OBJS_DIR):
			mkdir -p $(OBJS_DIR)

$(NAME):	$(OBJS)
			$(CC) -g $(CFLAGS) -I$(INCLUDES_DIR) -MMD -MP -o $(NAME) $(OBJS)

clean:
			if [ -d "$(OBJS_DIR)" ]; then rm -rfv $(OBJS_DIR); fi

fclean:		clean
			$(RM) $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re