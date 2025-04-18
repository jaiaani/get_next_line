NAME := libget_next_line.a

CC := cc

LIB := -L../libft -libft

CCFLAGS := -Wall -Wextra -Werror -D BUFFER_SIZE=1

RM := rm -f

AR := ar rcs

SRCS =  get_next_line.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CCFLAGS) -c $< -o ${<:.c=.o}
