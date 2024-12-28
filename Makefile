
NAME := libget_next_line.a

BONUS_NAME := libget_next_line_bonus.a

CC := cc

CCFLAGS := -Wall -Wextra -Werror

RM := rm -f

AR := ar rcs

SRCS =  get_next_line_utils.c get_next_line.c

BSRCS = get_next_line_utils_bonus.c get_next_line_bonus.c

OBJS := $(SRCS:.c=.o)

BOBJS := $(BSRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

.c.o:
	$(CC) $(CCFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
			$(AR) $(NAME) $(OBJS)


$(BONUS_NAME) : $(BOBJS)
				$(AR) $(BONUS_NAME) $(BOBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
		$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
